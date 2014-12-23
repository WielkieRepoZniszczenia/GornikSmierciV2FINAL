#ifndef GTS_OBJECT_H
#define GTS_OBJECT_H

#include <string>

#include "GTS_OBJ/GTS_OBJ.h"

namespace GTS
{
	class Object : public GTS::OBJ
	{
		public:
			Object();
			virtual ~Object();
			Object(const Object& other);

			/// location
			int set_location(GTS::Location* location);
			GTS::Location* get_location();
			///

			/// position
			void set_position(GTS::Vec3D<long> newPosition);
			GTS::Vec3D<long> get_position();
			///

			/// save/load this object
			virtual int save(std::ofstream* fout);
			virtual int load(std::ifstream* fin);
			///

		protected:

		private:
			std::string m_name;
			GTS::Location* m_location;
			GTS::Vec3D<long> m_position;

	};

	#include "GTS_Object.cpp"

}

#endif // GTS_OBJECT_H
