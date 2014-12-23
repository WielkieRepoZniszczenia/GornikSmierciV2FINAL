#ifndef GTS_PARALLEL_H
#define GTS_PARALLEL_H

#include <list>
#include "GTS_AI/GTS_Instruction/GTS_Instruction.h"

namespace GTS
{
	class Parallel : public GTS::Instruction
	{
		public:
			Parallel();
			~Parallel();



		protected:
		private:
			std::list<GTS::Instruction*> m_instruction_;
	};

	#include "GTS_Parallel.cpp"
}
#endif // GTS_PARALLEL_H
