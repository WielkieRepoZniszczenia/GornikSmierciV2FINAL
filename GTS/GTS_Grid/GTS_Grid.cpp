


/// CTOR / DTOR
Grid::Grid()
{
	bFullBoard = true;

	m_LPS.x = 0;
	m_LPS.y = 0;

	m_SPM.x = 0;
	m_SPM.y = 0;

	m_LPM.x = 0;
	m_LPM.y = 0;

	m_TOB.x = 0;
	m_TOB.y = 0;

	bUnderground = false;

	m_currentSector.x = 0;
	m_currentSector.y = 0;
}
Grid::~Grid()
{
	freeTiles();
}
///



/// SET GRID
template<class tile_Type>
int Grid::set(unsigned int sectors_in_row, unsigned int sectors_in_column,
			  unsigned int locations_in_row, unsigned int locations_in_column,
			  bool underground, bool fullyLoaded,
			  GTS::Location defaultLocation)
{
	/// free location memory
	m_surfaceLocations_.erase(m_surfaceLocations_.begin(), m_surfaceLocations_.end());
	m_undergroundLocations_.erase(m_undergroundLocations_.begin(), m_undergroundLocations_.end());

	/// set new data
	m_SPM.x = sectors_in_row;
	m_SPM.y = sectors_in_column;

	m_LPS.x = locations_in_row;
	m_LPS.y = locations_in_column;

	m_LPM.x = m_SPM.x*m_LPS.x;
	m_LPM.y = m_SPM.y*m_LPS.y;

	bUnderground = underground;

	/// create new locations
	m_surfaceLocations_.resize(m_SPM.x*m_SPM.y*m_LPS.x*m_LPS.y, defaultLocation);
	if(bUnderground == true)
		m_undergroundLocations_.resize(m_SPM.x*m_SPM.y*m_LPS.x*m_LPS.y, defaultLocation);



	/// free tile memory
	freeTiles();

	/// create new tiles
	if(fullyLoaded == true)
	{
		m_TOB.x = m_LPM.x;
		m_TOB.y = m_LPM.y;

		m_tiles_.resize(m_TOB.x*m_TOB.y, NULL);
		for(unsigned int n = 0; n < m_tiles_.size(); ++n)
		{
			m_tiles_.at(n) = new tile_Type;
			m_surfaceLocations_.at(n).attach_tile(m_tiles_.at(n));
		}

		m_tilesU_.resize(m_TOB.x*m_TOB.y, NULL);
		for(unsigned int n = 0; n < m_tilesU_.size(); ++n)
		{
			m_tilesU_.at(n) = new tile_Type;
			m_undergroundLocations_.at(n).attach_tile(m_tilesU_.at(n));
		}
	}
	else
	{
		m_TOB.x = 3*m_LPS.x;
		m_TOB.y = 3*m_LPS.y;

		m_tiles_.resize(m_TOB.x*m_TOB.y, NULL);
		for(unsigned int n = 0; n < m_tiles_.size(); ++n)
		{
			m_tiles_.at(n) = new tile_Type;
		}
	}


	return 0;
}
///



/// GET SIZE OF...
GTS::Vec2D<unsigned int> Grid::get_LPS()
{
	return m_LPS;
}
GTS::Vec2D<unsigned int> Grid::get_SPM()
{
	return m_SPM;
}
GTS::Vec2D<unsigned int> Grid::get_LPM()
{
	return m_LPM;
}
GTS::Vec2D<unsigned int> Grid::get_TOB()
{
	return m_TOB;
}
///



/// GET LOCATION
GTS::Location* Grid::get_location(int x, int y, bool underground)
{
	if(x < 0 || x > (int)m_LPM.x
	|| y < 0 || y > (int)m_LPM.y)
		return NULL;

	if(bUnderground == true)
	{
		if(underground == true)
			return &m_undergroundLocations_.at(y*m_LPM.x + x);

		else
			return &m_surfaceLocations_.at(y*m_LPM.x + x);
	}

	return &m_surfaceLocations_.at(y*m_LPM.x + x);
}
///



/// GET TILE
GTS::Tile* Grid::get_tile(int x, int y, bool underground)
{
	GTS::Location* location = get_location(x, y, underground);
	if(location == NULL)
		return NULL;

	GTS::Tile* tile = dynamic_cast<GTS::Tile*>(location->get_tile());

	return tile;
}
///



/// SAVE / LOAD
int Grid::saveBase(std::ofstream* fout)
{
	if(fout == NULL)
	{
		printf("Grid error. Could not save grid.\n");
		return -1;
	}
	fout->write((char*) &m_LPS, sizeof(m_LPS));
	fout->write((char*) &m_SPM, sizeof(m_SPM));
	fout->write((char*) &m_LPM, sizeof(m_LPM));
	fout->write((char*) &m_TOB, sizeof(m_TOB));

	return 0;
}
int Grid::loadBase(std::ifstream* fin)
{
	if(fin == NULL)
	{
		printf("Grid error. Could not load grid.\n");
		return -1;
	}
	fin->read((char*) &m_LPS, sizeof(m_LPS));
	fin->read((char*) &m_SPM, sizeof(m_SPM));
	fin->read((char*) &m_LPM, sizeof(m_LPM));
	fin->read((char*) &m_TOB, sizeof(m_TOB));

	return 0;
}
int Grid::saveSector(int x, int y, std::ofstream* fout)
{

	return 0;
}
int Grid::loadSector(int x, int y, std::ifstream* fin)
{
	return 0;
}
int Grid::saveBoard(std::ofstream* fout)
{
	return 0;
}
int Grid::loadBoard(std::ifstream* fin)
{
	return 0;
}
///


void Grid::freeTiles()
{
	/// surface tiles
	for(unsigned int n = 0; n < m_tiles_.size(); ++n)
		delete m_tiles_.at(n);

	m_tiles_.erase(m_tiles_.begin(), m_tiles_.end());

	/// underground tiles
	for(unsigned int n = 0; n < m_tilesU_.size(); ++n)
		delete m_tilesU_.at(n);

	m_tilesU_.erase(m_tilesU_.begin(), m_tilesU_.end());
}
