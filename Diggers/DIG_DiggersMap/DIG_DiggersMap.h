#ifndef DIG_DIGGERSMAP_H
#define DIG_DIGGERSMAP_H

#include "GTS_Map/GTS_Map.h"

namespace DIG
{
	class DiggersMap : public GTS::Map
	{
		public:
			DiggersMap();
			virtual ~DiggersMap();


			static const GTS::Vec2D<int> SM_TILE_DIM;
			static const GTS::Vec2D<int> SM_TILES_PER_SECTOR;
			static const GTS::Vec2D<int> SM_NUMBER_OF_SECTORS;

			int set();

			int update();

			int save(std::ofstream* fout);
			int load(std::ifstream* fin);

		protected:
		private:
	};

	#include "DIG_DiggersMap.cpp"

}

#endif // DIG_DIGGERSMAP_H
