#ifndef GTS_WAIT_H
#define GTS_WAIT_H

#include "GTS_AI/GTS_Instruction/GTS_Instruction.h"

namespace GTS
{
	class Wait : public GTS::Instruction
	{
		public:
			Wait();
			virtual ~Wait();
		protected:
		private:
	};

	#include "GTS_Wait.cpp"
}
#endif // GTS_WAIT_H
