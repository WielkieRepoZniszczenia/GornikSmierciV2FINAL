

/// CTOR / DTOR
Tile::Tile()
{
	//ctor
}
Tile::~Tile()
{
	//dtor
}
///



void Tile::set_tileDim()
{
	GTS::SQTile::set_tileDimS(80, 80);
}
GTS::Vec2D<unsigned int> Tile::get_tileDim()
{
	return GTS::SQTile::get_tileDimS();
}



/// RENDER
int Tile::renderBG()
{
	return 0;
}
int Tile::renderFG()
{
	return 0;
}
///
