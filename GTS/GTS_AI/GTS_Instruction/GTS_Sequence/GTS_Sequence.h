#ifndef GTS_SEQUENCE_H
#define GTS_SEQUENCE_H

#include <list>

#include "GTS_AI/GTS_Instruction/GTS_Instruction.h"

namespace GTS
{
	class Sequence : GTS::Instruction
	{
		public:
			Sequence();
			~Sequence();

			int set_child(GTS::Instruction* child);

			int process();

		protected:

		private:
			std::list<GTS::Instruction*> m_instructions_;
			std::list<GTS::Instruction*>::iterator m_current;
	};

	#include "GTS_Sequence.cpp"

}

#endif // GTS_SEQUENCE_H
