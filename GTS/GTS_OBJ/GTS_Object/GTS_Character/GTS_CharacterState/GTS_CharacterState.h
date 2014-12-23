#ifndef GTS_CHARACTERSTATE_H
#define GTS_CHARACTERSTATE_H


namespace GTS
{
	class CharacterState
	{
		public:
			CharacterState();
			virtual ~CharacterState();
			CharacterState(const CharacterState& other);
			CharacterState& operator=(const CharacterState& other);
		protected:
		private:
	};

	#include "GTS_CharacterState.cpp"

}

#endif // GTS_CHARACTERSTATE_H
