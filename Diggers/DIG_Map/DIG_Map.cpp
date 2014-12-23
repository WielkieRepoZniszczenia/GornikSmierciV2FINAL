


/// CTOR / DTOR
Map::Map()
{
	m_mapCode = "DIGGERS";
	m_mapName = "defaultMap";
}
Map::~Map()
{
	//dtor
}
///



int Map::set()
{
	if(m_grid != NULL)
	{
		return 0;
	}
	m_grid = new DIG::Grid;
	GTS::Vec2D<unsigned int> locations = get_LPM();

	m_worldBorder.x = 0;
	m_worldBorder.y = 0;
	m_worldBorder.w = locations*;
	m_worldBorder.h = 0;

	GTS::MiniMap* m_miniMap;
	return 0;
}
int Map::update()
{
	return 0;
}



/// SAVE LOAD
int Map::save(std::ofstream* fout)
{
	return 0;
}
int Map::load(std::ifstream* fin)
{
	return 0;
}
///
