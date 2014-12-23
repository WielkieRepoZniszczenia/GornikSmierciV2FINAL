#ifndef GTS_CREATURE_H
#define GTS_CREATURE_H

#include "GTS_Object/GTS_Object.h"

namespace GTS
{
	class Creature : public Object
	{
		public:
			Creature();
			virtual ~Creature();

		protected:
		private:
	};

	#include "GTS_Creature.cpp"
}
#endif // GTS_CREATURE_H
