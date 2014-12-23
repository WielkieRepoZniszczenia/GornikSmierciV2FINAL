
/// CONSTRUCTOR / DESTRUCTOR / MIMIC
Object::Object()
{
	//ctor
}
Object::~Object()
{
	//dtor
}
Object::Object(const Object& other)
{
	*this = other;
}
///



/// LOCATION
int Object::set_location(GTS::Location* location)
{
	return 0;
}
GTS::Location* Object::get_location()
{
	return NULL;
}
///



/// POSITION
void Object::set_position(GTS::Vec3D<long> newPosition)
{

}
GTS::Vec3D<long> Object::get_position()
{
	return m_position;
}
///



/// SAVE / LOAD
int Object::save(std::ofstream* fout)
{
	return 0;
}
int Object::load(std::ifstream* fin)
{
	return 0;
}
///
