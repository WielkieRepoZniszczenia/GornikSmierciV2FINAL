#ifndef GTS_CHARACTER_H
#define GTS_CHARACTER_H

#include "GTS_OBJ/GTS_Object/GTS_Object.h"

#include "GTS_CharacterDescription/GTS_CharacterDescription.h"
#include "GTS_CharacterAbilities/GTS_CharacterAbilities.h"
#include "GTS_CharacterItems/GTS_CharacterItems.h"
#include "GTS_CharacterFeatures/GTS_CharacterFeatures.h"
#include "GTS_CharacterState/GTS_CharacterState.h"
#include "GTS_CharacterAnimations/GTS_CharacterAnimations.h"
//#include "CharacterCreatures/CharacterCreatures.h"

namespace GTS
{
	class Character : public Object
	{
		public:
			Character();
			virtual ~Character();
			Character(const Character& other);


			/// character interface
			int set_description(const GTS::CharacterDescription& description);
			int set_abilities(const GTS::CharacterAbilities& abilities);
			int set_items(const GTS::CharacterItems& items);
			int set_features(const GTS::CharacterFeatures& features);
			int set_state(const GTS::CharacterState& state);
			int set_animations(const GTS::CharacterAnimations& animations);

			GTS::CharacterDescription* m_description;
			GTS::CharacterAbilities* m_abilities;
			GTS::CharacterItems* m_items;
			GTS::CharacterFeatures* m_features;
			GTS::CharacterState* m_state;
			GTS::CharacterAnimations* m_animations;
			///


			/// save/load this object
			virtual int save(std::ofstream* fout);
			virtual int load(std::ifstream* fin);
			///

		protected:

		private:
	};

	#include "GTS_Character.cpp"

}

#endif // GTS_CHARACTER_H
