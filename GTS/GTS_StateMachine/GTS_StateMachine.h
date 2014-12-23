#ifndef GTS_STATEMACHINE_H
#define GTS_STATEMACHINE_H


#include <stdio.h>
#include <vector>
#include "GTS_State/GTS_State.h"
#include "GTS_Window/GTS_Window.h"

#include <typeinfo> // to identify the type of incoming states



namespace GTS
{
	/// @@@ SINGLETON @@@
	class StateMachine
	{
		public:
			static int create();
			static StateMachine* get();
			static void destroy();

			~StateMachine();

			/** @@ state switching @@
				@set_nextState() :
				* if succeed:
					* nextState pointer is set to new created state
				* if not:
					* everything stays the same, except nextState
					  gets destroyed and its pointer is set to NULL
					+ function returns -1

				@switch_to_nextState()
				* if succeed:
					* lastState is destroyed
					* lastState pointer is set to currentState
					* currentState pointer is set to nextState
					* nextState pointer is set to NULL
				* if not:
					+ function returns -1

				*/
				int set_nextState(GTS::State* next);
				bool changed();
				int swtch_to_nextState();


			GTS::State* get_currentState();
			GTS::State* get_lastState();


		private:
			StateMachine();
			static StateMachine* sm_StateMachine;

			GTS::State* m_lastState;
			GTS::State* m_currentState;
			GTS::State* m_nextState;
	};

	#include "GTS_StateMachine.cpp"
}

#endif // GTS_STATEMACHINE_H
