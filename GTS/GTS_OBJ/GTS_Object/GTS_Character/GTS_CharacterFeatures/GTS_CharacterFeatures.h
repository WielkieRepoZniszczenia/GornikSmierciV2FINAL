#ifndef GTS_CHARACTERFEATURES_H
#define GTS_CHARACTERFEATURES_H


namespace GTS
{
	class CharacterFeatures
	{
		public:
			CharacterFeatures();
			virtual ~CharacterFeatures();
			CharacterFeatures(const CharacterFeatures& other);
			CharacterFeatures& operator=(const CharacterFeatures& other);
		protected:
		private:
	};
	#include "GTS_CharacterFeatures.cpp"
}

#endif // GTS_CHARACTERFEATURES_H
