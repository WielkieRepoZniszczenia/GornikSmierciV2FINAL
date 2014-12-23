#ifndef GTS_MINIMAP_H
#define GTS_MINIMAP_H

#include "GTS_Grid/GTS_Grid.h"

namespace GTS
{
	class MiniMap
	{
		public:
			MiniMap();
			virtual ~MiniMap();

			virtual int render(int x, int y) = 0;

		protected:
		private:
	};

	#include "GTS_MiniMap.cpp"
}

#endif // GTS_MINIMAP_H
