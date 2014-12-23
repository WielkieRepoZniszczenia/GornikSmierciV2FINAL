#ifndef GTS_ACTION_H
#define GTS_ACTION_H

#include "GTS_AI/GTS_Instruction/GTS_Instruction.h"

namespace GTS
{
	class Action : public GTS::Instruction
	{
		public:
			Action(GTS::Command& command);
			~Action();
		protected:
		private:
			GTS::Command command;
	};

	#include "GTS_Action.cpp"
}

#endif // GTS_ACTION_H
