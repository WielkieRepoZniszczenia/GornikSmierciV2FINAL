



/// CTOR / DTOR
SQTile::SQTile()
{
	//ctor
}
SQTile::~SQTile()
{
	//dtor
}
///



/// EDIT
void SQTile::set_flags(char* a, char* b, char* c, char* d)
{
	if(a != NULL)
		m_tFlags[0] = a;

	if(b != NULL)
		m_tFlags[1] = b;

	if(c != NULL)
		m_tFlags[2] = c;

	if(d != NULL)
		m_tFlags[3] = d;
}
const char* SQTile::get_flags()
{
	return m_tFlags;
}
void SQTile::set_variant(char v)
{
	m_variant = v;
}
///
