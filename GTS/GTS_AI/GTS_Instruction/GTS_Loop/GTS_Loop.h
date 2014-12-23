#ifndef GTS_LOOP_H
#define GTS_LOOP_H

#include "GTS_AI/GTS_Instruction/GTS_Instruction.h"

namespace GTS
{
	class Loop : public GTS::Instruction
	{
		public:
			Loop();
			virtual ~Loop();
		protected:
		private:
	};

	#include "GTS_Loop.cpp"
}
#endif // GTS_LOOP_H
