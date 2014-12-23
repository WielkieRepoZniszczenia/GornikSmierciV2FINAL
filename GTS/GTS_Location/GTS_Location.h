#ifndef GTS_LOCATION_H
#define GTS_LOCATION_H

#include <list>

namespace GTS
{
	class Location
	{
		public:
			Location();
			~Location();

			/// path finder data
			void set_gVal(unsigned long gVal);
			unsigned long get_gVal();

			void set_hVal(unsigned short hVal);
			unsigned short get_hVal();

			void set_checked(bool checked);
			bool get_checked();

			void set_parent(GTS::Location* parent);
			GTS::Location* get_parent();

			void clear_path_data();

			unsigned long countPFvalue();
			///

			/// set/get id
			void set_id(GTS::Vec2D<unsigned short> id);
			GTS::Vec2D<unsigned short> get_id();
			///

			/// attach/detach tile
			int attach_tile(GTS::OBJ* tile);
			void detach_tile();
			///

			/// attach/detach object
			int attach_object(GTS::OBJ* obj); // object can sign in to this location
			int detach_object(GTS::OBJ* obj); // objects can sign out of this location
			std::list<const GTS::OBJ*> get_objects(); // should return pawn list
			///

			/// get tile
			GTS::OBJ* get_tile();
			///

		protected:
		private:
			/// path finder data
			unsigned long m_GVal;
			unsigned short m_HVal;
			bool bChecked;
			Location* m_Parent;
			///

			GTS::OBJ* m_tile;
			std::list<const GTS::OBJ*> m_objects_;


			GTS::Vec2D<unsigned short> m_ID;

			bool bLocked; // locked for path finder
	};

	#include "GTS_Location.cpp"
}

#endif // GTS_LOCATION_H
