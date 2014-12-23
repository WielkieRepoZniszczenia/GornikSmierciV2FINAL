#ifndef GTS_MAP_H
#define GTS_MAP_H

#include <string>
#include <list>
#include <fstream>

#include "GTS_Grid/GTS_Grid.h"
#include "GTS_MiniMap/GTS_MiniMap.h"

namespace GTS
{
	/// SINGLETON
	class Map
	{
		public:
			Map();
			virtual ~Map();

			std::string get_mCode();

			void set_mapName(std::string str);
			std::string get_mapName();

			GTS::Vec4D<long> get_worldBorder();
			GTS::Vec4D<long> get_cameraProjection();
			GTS::Vec4D<long> get_activeProjection(); //area around camera (simplifies rendering textures outside projection)

			int render_grid(int x, int y);
			int render_miniMap(int x, int y);

			virtual int set() = 0;
			virtual int update() = 0;

			virtual int save(std::ofstream* fout) = 0;
			virtual int load(std::ifstream* fin) = 0;

		protected:
			int saveBase(std::ofstream* fout);
			int loadBase(std::ifstream* fin);


			void set_mCode(std::string str);
			void set_worldBorder(unsigned int w, unsigned int h, int x = 0, int y = 0);

			GTS::Camera m_camera;

		private:
			/** MAP DESCRIPTION
				* m_WorldBorder:
					camera projection can move only inside this rectangle(+ some y offset caused by terrain height// it can be turned off)
				*/
				std::string m_mapCode;
				std::string m_mapName;
				GTS::Vec4D<long> m_worldBorder;

				GTS::Grid* m_grid;
				GTS::MiniMap* m_miniMap;
	};

	#include "GTS_Map.cpp"
}

#endif // GTS_MAP_H
