#ifndef GTS_CHARACTERDESCRIPTION_H
#define GTS_CHARACTERDESCRIPTION_H

namespace GTS
{
	class CharacterDescription
	{
		public:
			CharacterDescription();
			virtual ~CharacterDescription();
			CharacterDescription(const CharacterDescription& other);
			CharacterDescription& operator=(const CharacterDescription& other);

			int get_(){return 0;}
		protected:
		private:
	};

	#include "GTS_CharacterDescription.cpp"

}
#endif // GTS_CHARACTERDESCRIPTION_H
