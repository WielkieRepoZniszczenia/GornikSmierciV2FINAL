#ifndef GTS_GRID_H
#define GTS_GRID_H

#include <vector>
#include "GTS_Location/GTS_Location.h"

namespace GTS
{
	class Grid
	{
		public:
			Grid();
			virtual ~Grid();

			template<class tile_Type>
			int set(unsigned int sectors_in_row, unsigned int sectors_in_column,
					unsigned int locations_in_row, unsigned int locations_in_column,
					bool underground, bool fullyLoaded,
					GTS::Location defaultLocation);

			GTS::Vec2D<unsigned int> get_LPS(); // locations per sector
			GTS::Vec2D<unsigned int> get_SPM(); // sectors per map
			GTS::Vec2D<unsigned int> get_LPM(); // locations per map
			GTS::Vec2D<unsigned int> get_TOB(); // tiles on board

			/** @@ GET METHODS @@
				*/
				GTS::Location* get_location(int x, int y, bool underground);
				GTS::Tile* get_tile(int x, int y, bool underground);

			/** @@ RENDER @@
				*/
				virtual int render(int x, int y) = 0;


			/** @@ SAVE / LOAD @@
				* if bFullBoard is false:
					* during game/editing everything is done on default file "staticData"
					* default map has no string, or in general - dynamic data
				* else
					* everything is saved/loaded to memory
				*/
				virtual int save(std::ofstream* fout) = 0;
				virtual int load(std::ifstream* fin) = 0;

		protected:
			int saveBase(std::ofstream* fout);
			int loadBase(std::ifstream* fin);

			int saveSector(int x, int y, std::ofstream* fout);
			int loadSector(int x, int y, std::ifstream* fin);

			int saveBoard(std::ofstream* fout); // saves sectors around current
			int loadBoard(std::ifstream* fin);  // loads sectors around current

			void freeTiles();

		private:
			bool bFullBoard;
			GTS::Vec2D<unsigned int> m_LPS; // locations per sector
			GTS::Vec2D<unsigned int> m_SPM; // sectors per map
			GTS::Vec2D<unsigned int> m_LPM; // locations per map
			GTS::Vec2D<unsigned int> m_TOB; // tiles on board
			bool bUnderground;

			GTS::Vec2D<unsigned int> m_currentSector;

			std::vector<GTS::Tile*> m_tiles_;
			std::vector<GTS::Tile*> m_tilesU_;
			std::vector<GTS::Location> m_surfaceLocations_;
			std::vector<GTS::Location> m_undergroundLocations_;
	};
	#include "GTS_Grid.cpp"
}

#endif // GTS_GRID_H
