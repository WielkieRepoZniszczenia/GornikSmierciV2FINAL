#ifndef GTS_CHARACTERABILITIES_H
#define GTS_CHARACTERABILITIES_H

namespace GTS
{
	class CharacterAbilities
	{
		public:
			CharacterAbilities();
			virtual ~CharacterAbilities();
			CharacterAbilities(const CharacterAbilities& other);
			CharacterAbilities& operator=(const CharacterAbilities& other);
		protected:
		private:
	};

	#include "GTS_CharacterAbilities.cpp"
}

#endif // GTS_CHARACTERABILITIES_H
