


/// CTOR / DTOR
Map::Map()
{
	m_mapCode = "defaultCode";
	m_mapName = "defaultMap";
	m_worldBorder.x = 0;
	m_worldBorder.y = 0;
	m_worldBorder.w = 0;
	m_worldBorder.h = 0;

	m_grid = NULL;
	m_miniMap = NULL;
}
Map::~Map()
{
	if(m_grid != NULL)
	{
		delete m_grid;
	}
	if(m_miniMap != NULL)
	{
		delete m_miniMap;
	}
}
///


void Map::set_mapName(std::string str)
{
	m_mapName = str;
}
std::string Map::get_mapName()
{
	return m_mapName;
}


GTS::Vec4D<long> Map::get_worldBorder()
{
	return m_worldBorder;
}
GTS::Vec4D<long> Map::get_cameraProjection()
{
	return camera.get_projection();
}
GTS::Vec4D<long> Map::get_activeProjection()
{
	GTS::Vec4D<long> box = camera.get_projection();
	box.x -= 300;
	box.y -= 300;
	box.w += 600;
	box.h += 600;

	return box;
}


/// RENDER
int Map::render_grid(int x, int y)
{
	if(m_grid != NULL)
	{
		m_grid->render(x, y);
	}
	return 0;
}
int Map::render_miniMap(int x, int y)
{
	if(m_miniMap != NULL)
	{
		m_miniMap->render(x, y);
	}
	return 0;
}
///



/// SAVE / LOAD
int Map::saveBase(std::ofstream* fout)
{
	saveString(m_mapCode, fout);
	saveString(m_mapName, fout);

	fout->write((char*) &m_worldBorder, sizeof(m_worldBorder));

	/** save grid
		*/{
		if(m_grid == NULL)
		{
			printf("Map error. Could not save base data.\n");
			return -1;
		}
		if(m_grid->save(fout) != 0)
		{
			return -1;
		}
	}

	return 0;
}
int Map::loadBase(std::ifstream* fin)
{
	loadString(m_mapCode, fin);
	loadString(m_mapName, fin);

	fin->read((char*) &m_worldBorder, sizeof(m_worldBorder));

	/** load grid
		*/{
		if(m_grid == NULL)
		{
			printf("Map error. Could not load base data.\n");
			return -1;
		}
		if(m_grid->load(fin) != 0)
		{
			return -1;
		}
	}

	return 0;
}
///
