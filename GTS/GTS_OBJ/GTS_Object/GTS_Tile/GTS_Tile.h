#ifndef GTS_TILE_H
#define GTS_TILE_H

#include "GTS_OBJ/GTS_Object/GTS_Object.h"

namespace GTS
{
	class Tile : public GTS::Object
	{
		public:
			Tile();
			virtual ~Tile();

			virtual int edit() = 0;

			virtual int update(long currentTime) = 0;
			virtual int show() = 0;

			virtual int save(std::ofstream* fout) = 0;
			virtual int load(std::ifstream* fin) = 0;

		protected:

		private:


	};

	#include "GTS_Tile.cpp"
}

#endif // GTS_TILE_H
