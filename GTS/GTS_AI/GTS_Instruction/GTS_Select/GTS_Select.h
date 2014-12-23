#ifndef GTS_SELECT_H
#define GTS_SELECT_H

#include "GTS_AI/GTS_Instruction/GTS_Instruction.h"

/** ta klasa powinna zostac usunieta!!!
	* nie ma  z niej pozytku
*/

namespace GTS
{
	class Select : public GTS::Instruction
	{
		public:
			Select();
			virtual ~Select();

		protected:
		private:


	};
	#include "GTS_Select.cpp"
}

#endif // GTS_SELECT_H
