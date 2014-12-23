#ifndef GTS_ACTION_H
#define GTS_ACTION_H


namespace GTS /// BUILD IN COMMAND STRUCTURES
{
	enum COMMAND_TYPE
	{
		NONE = 0,
		BUSY,
		FACE,
		MOVE,

		GET_LOCATION,
		RETURN_LOCATION,

		GET_POSITION,
		RETURN_POSITION,

		COMMAND_LAST
	};

	enum DIRECTION
	{
		NORTH = 0,
		NORTHWEST,
		NORTHEAST,
		WEST,
		EAST,
		SOUTHWEST,
		SOUTHEAST,
		SOUTH,

		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	typedef struct{ /// FACE
		COMMAND_TYPE type;
		DIRECTION direction;
	} Face;

	typedef struct{	/// MOVE
		COMMAND_TYPE type;
		DIRECTION direction;
		double speed;
	} Move;

	typedef struct{	/// RETURN_LOCATION
		COMMAND_TYPE type;
		GTS::Vec2D<unsigned int> location;
	} Return_Location;

	typedef struct{	/// RETURN_POSITION
		COMMAND_TYPE type;
		GTS::Vec3D<long> position;
	} Return_Position;

}

namespace GTS /// COMMAND UNION
{
	struct Command{
		GTS::COMMAND_TYPE type;
		union
		{
			GTS::Face face;
			GTS::Move move;
			GTS::Return_Location location;
			GTS::Return_Position position;
		};

	};
}

namespace GTS /// COMMAND ==OPERATOR
{
	bool operator==(GTS::Command &a, GTS::Command &b)
	{
		if(a.type != b.type)
			return false;

		char* bufA = reinterpret_cast<char*>(&a);
		char* bufB = reinterpret_cast<char*>(&b);

		unsigned int size = sizeof(a);

		for(unsigned int n = 0; n < size; ++n)
		{
			if(bufA[n] != bufB[n])
				return false;
		}

		/// match
		return true;
	}
}


#endif // GTS_ACTION_H
