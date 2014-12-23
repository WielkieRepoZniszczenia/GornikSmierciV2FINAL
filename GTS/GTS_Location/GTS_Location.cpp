


/// CTOR / DTOR
Location::Location()
{
	m_tile = NULL;

	m_ID.x = 0;
	m_ID.y = 0;

	m_GVal = 0;
	--m_GVal;
	m_HVal = 0;
	--m_HVal;
	bChecked = false;
	m_Parent = NULL;
}
Location::~Location()
{
	//dtor
}
///



/// PATH FINDER DATA
void Location::set_gVal(unsigned long gVal)
{
	m_GVal = gVal;
}
unsigned long Location::get_gVal()
{
	return m_GVal;
}

void Location::set_hVal(unsigned short hVal)
{
	m_HVal = hVal;
}
unsigned short Location::get_hVal()
{
	return m_HVal;
}

void Location::set_checked(bool checked)
{
	bChecked = checked;
}
bool Location::get_checked()
{
	return bChecked;
}

void Location::set_parent(GTS::Location* parent)
{
	m_Parent = parent;
}
GTS::Location* Location::get_parent()
{
	return m_Parent;
}
void Location::clear_path_data()
{
	m_GVal = 0;
	--m_GVal;
	m_HVal = 0;
	--m_HVal;
	bChecked = false;
	m_Parent = NULL;
}
unsigned long Location::countPFvalue()
{
	return 0;
}
///



/// SET / GET ID
void Location::set_id(GTS::Vec2D<unsigned short> id)
{
	m_ID = id;
}
GTS::Vec2D<unsigned short> Location::get_id()
{
	return m_ID;
}
///



/// ATTACH / DETACH OBJECT
int Location::attach_tile(GTS::OBJ* tile)
{
	if(tile == NULL)
	{
		printf("Could not add Tile to this Location. Tile is a null pointer.\n");
		return -1;
	}

	m_tile = tile;

	return 0;
}
void Location::detach_tile()
{
	m_tile = NULL;
}
///



/// ATTACH / DETACH OBJECT
int Location::attach_object(GTS::OBJ* obj)
{
	std::list<const GTS::OBJ*>::const_iterator mLoc;

	for(mLoc = m_objects_.begin(); mLoc != m_objects_.end(); ++mLoc)
	{
		if(obj == *mLoc)
		{
			printf("Lodger already exist on the list.\n");
			return -1;
		}
	}
	m_objects_.push_back(obj);

	return 0;
}
int Location::detach_object(GTS::OBJ* obj)
{
	std::list<const GTS::OBJ*>::iterator mLoc;

	for(mLoc = m_objects_.begin(); mLoc != m_objects_.end(); ++mLoc)
	{
		if(obj == *mLoc)
		{
			m_objects_.erase(mLoc);
			return 0;
		}
	}

	printf("Leaver is not on the list of lodgers in this location.\n");
	return -1;
}
///



/// GET TILE / OBJECTS
GTS::OBJ* Location::get_tile()
{
	return m_tile;
}
std::list<const GTS::OBJ*> Location::get_objects()
{
	return m_objects_;
}
///


