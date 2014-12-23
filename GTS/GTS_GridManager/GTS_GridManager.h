#ifndef GTS_GRIDMANAGER_H
#define GTS_GRIDMANAGER_H

namespace GTS
{
	/// SINGLETON
	class GridManager
	{
		public:
			static int create();
			static GridManager* get();
			static void destroy();

			~GridManager();

			template<class tile_Type>
			int set_grid(unsigned int sectors_in_row, unsigned int sectors_in_column,
						 unsigned int tiles_in_row, unsigned int tiles_in_column, bool underground,
						 GTS::Location defLocation);

			GTS::Vec2D<unsigned int> get_TPS();// tiles per sector
			GTS::Vec2D<unsigned int> get_SPM();// sectors per map
			GTS::Vec2D<unsigned int> get_TOB();// tiles on board

			GTS::Tile* get_tile(unsigned int xLocation, unsigned int yLocation);
			GTS::Location* get_location(unsigned int x, unsigned int y);

		protected:

		private:
			GridManager();
			static GridManager* sGridManager;

			GTS::Vec2D<unsigned int> mTilesPerSector;
			GTS::Vec2D<unsigned int> mSectorsPerMap;
			bool bUnderground;

			GTS::Vec2D<unsigned int> mCurrentSector;

			std::vector<long> mSectorMemoryPointer;

			std::vector<GTS::Tile*> mTiles_;
			std::vector<GTS::Location> mSurfaceLocations_;
			std::vector<GTS::Location> mUndergroundLocations_;


	};

	#include "GTS_GridManager.cpp"
}

#endif // GTS_GRIDMANAGER_H
