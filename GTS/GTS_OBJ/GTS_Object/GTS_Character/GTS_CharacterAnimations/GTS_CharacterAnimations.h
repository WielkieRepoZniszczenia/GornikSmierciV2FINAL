#ifndef GTS_CHARACTERANIMATIONS_H
#define GTS_CHARACTERANIMATIONS_H


namespace GTS
{
	class CharacterAnimations
	{
		public:
			CharacterAnimations();
			virtual ~CharacterAnimations();
			CharacterAnimations(const CharacterAnimations& other);
			CharacterAnimations& operator=(const CharacterAnimations& other);
		protected:
		private:
	};

	#include "GTS_CharacterAnimations.cpp"

}

#endif // GTS_CHARACTERANIMATIONS_H
