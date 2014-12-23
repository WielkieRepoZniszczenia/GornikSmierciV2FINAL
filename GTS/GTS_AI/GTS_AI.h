#ifndef GTS_AI_H
#define GTS_AI_H

#include <list>

#include "GTS_Instruction/GTS_Instruction.h"
#include "GTS_PathFinder/GTS_PathFinder.h"


#include "GTS_Instruction/GTS_Loop/GTS_Loop.h"
#include "GTS_Instruction/GTS_Condition/GTS_Condition.h"
#include "GTS_Instruction/GTS_Parallel/GTS_Parallel.h"
#include "GTS_Instruction/GTS_Select/GTS_Select.h"
#include "GTS_Instruction/GTS_Wait/GTS_Wait.h"
#include "GTS_Instruction/GTS_Task/GTS_Task.h"

namespace GTS
{
	/** @brief
		all computer players should have their own, individual instance of AI class
	*/
	class AI
	{
		public:
			AI();
			virtual ~AI();

			/** PROCESS
				* return value indicates process state
				* if 0 - ai working
				* if 1 - ai finished all instructions
				*/
				int process();

		protected:
		private:
			GTS::Instruction* m_first;

			static GTS::PathFinder m_pathFinder; //finds path between two locations(A*)
			//GTS::ObjectFinder m_objFinder; //finds objects in different ways
			//GTS::TaskManager* m_taskManager;
	};

	#include "GTS_AI.cpp"
}


#endif // GTS_AI_H
