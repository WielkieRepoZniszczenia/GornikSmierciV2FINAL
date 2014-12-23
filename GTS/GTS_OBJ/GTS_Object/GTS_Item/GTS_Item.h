#ifndef GTS_ITEM_H
#define GTS_ITEM_H

#include "GTS_OBJ/GTS_Object/GTS_Object.h"

namespace GTS
{
	class Item : public GTS::Object
	{
		public:
			Item();
			virtual ~Item();
		protected:
		private:
	};

	#include "GTS_Item.cpp"
}

#endif // GTS_ITEM_H
