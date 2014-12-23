#ifndef GTS_CHARACTERITEMS_H
#define GTS_CHARACTERITEMS_H

namespace GTS
{
	class CharacterItems
	{
		public:
			CharacterItems();
			virtual ~CharacterItems();
			CharacterItems(const CharacterItems& other);
			CharacterItems& operator=(const CharacterItems& other);
		protected:
		private:
	};
	#include "GTS_CharacterItems.cpp"
}

#endif // GTS_CHARACTERITEMS_H
