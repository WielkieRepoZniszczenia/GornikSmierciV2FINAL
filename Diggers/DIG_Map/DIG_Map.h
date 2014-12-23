#ifndef DIG_MAP_H
#define DIG_MAP_H

#include "GTS_Map/GTS_Map.h"


namespace DIG
{
	class Map : public GTS::Map
	{
		public:
			Map();
			virtual ~Map();

			virtual int set();
			virtual int update();

			virtual int save(std::ofstream* fout);
			virtual int load(std::ifstream* fin);

		protected:
		private:
	};

	#include "DIG_Map.cpp"

}

#endif // DIG_MAP_H
