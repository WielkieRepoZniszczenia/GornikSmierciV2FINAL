
const GTS::Vec2D<int> DiggersMap::SM_TILE_DIM(80, 80);
const GTS::Vec2D<int> DiggersMap::SM_TILES_PER_SECTOR(32, 32);
const GTS::Vec2D<int> DiggersMap::SM_NUMBER_OF_SECTORS(8, 8);

/// CTOR / DTOR
DiggersMap::DiggersMap()
{
	set_mCode("DIG_MAP");
	set_mapName("defaultMap");
}
DiggersMap::~DiggersMap()
{
	//dtor
}
///



int DiggersMap::set()
{
	set_worldBorder(SM_TILE_DIM.w*SM_TILES_PER_SECTOR.x*SM_NUMBER_OF_SECTORS.x,
					SM_TILE_DIM.h*SM_TILES_PER_SECTOR.y*SM_NUMBER_OF_SECTORS.y);

	m_camera.set_projection(GTS::Vec4D<long>(0, 0, 1600, 900));

	// set grid here

	return 0;
}
