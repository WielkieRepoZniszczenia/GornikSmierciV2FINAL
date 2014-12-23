#ifndef DIG_TILE_H
#define DIG_TILE_H

#include "GTS_SQTile/GTS_SQTile.h"

namespace DIG
{
	class Tile : public GTS::SQTile
	{
		public:
			Tile();
			virtual ~Tile();

			static void set_tileDim();
			GTS::Vec2D<unsigned int> get_tileDim();

			int renderBG();
			int renderFG();

		protected:
		private:

	};

	#include "DIG_Tile.cpp"
}

#endif // DIG_TILE_H
