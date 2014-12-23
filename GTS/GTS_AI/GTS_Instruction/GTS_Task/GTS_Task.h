#ifndef GTS_TASK_H
#define GTS_TASK_H

#include <string>

namespace GTS
{
	enum TASK_STATE
	{
		TASK_IN_PROCESS = 0,
		TASK_IDLE,
		TASK_DONE,
		TASK_DISCARDED
	};

	class Task
	{
		public:
			Task();
			virtual ~Task();

			std::string get_describtion();
			TASK_STATE get_state();

			/** CONDITIONS
				* conditions should be checked up to the root
				*          -||-        set internally (GTS::Condition is a template class)
				* some base data can be passed to GTS::Task (pointer to Player, Object, Location, etc.)
				*/
				virtual void set_condition(GTS::Player* player){}
				virtual bool check_conditions(){return false;}

		protected:
			/** INER METHODS
				* should be done in constructor
				*/
				void set_state(TASK_STATE newState);
				void set_describtion(std::string);

		private:
			TASK_STATE m_state;
			std::string m_describtion;

	};

	#include "GTS_Task.cpp"
}

#endif // GTS_TASK_H
