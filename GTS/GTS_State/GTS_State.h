#ifndef GTS_STATE_H
#define GTS_STATE_H

#include <string>

namespace GTS
{
	class State
	{
		public:
			State();
			virtual ~State();

			/** @@ SET @@
				* all base resources should be initialized here
				*/
				virtual int set() = 0;

			/** @@ EVENTS @@
				* user input handling section (keyboard/mouse states, etc.)
				*/
				virtual int events(SDL_Event &event) = 0;

			/** @@ LOGIC @@
				* more advanced calculations(collision detection, algorithms) should take place in this section
				*/
				virtual int logic() = 0;

			/** @@ SOUNDS @@
				* sounds activations
				*/
				virtual int sounds() = 0;

			/** @@ RENDER @@
				* screen updating should be done here
				*/
				virtual int render() = 0;

			/** @@ CLOSE @@
				* all expendables resources should be destroyed here
				*/
				virtual int clear() = 0;

			/** @@ CONNECTION BETWEEN STATES @@
                \note if your state starts some other state, you should put here setter methods...
					  e.g:
					  public:
						 void set_menuState(GTS::State& someState);

				\note ...and use it in main like this:
					  MyState myState;
					  MenuState menuState;

					  myState.set_menuState(menuState);

				\note put pointer to State in private section
					  e.g:

					  private:
						  GTS::State* menuState;

				\note later on if you want to switch to that state simply use the GTS::StateMachine like this:
					  GTS::StateMachine* SM = GTS::StateMachine::get();
					  if(SM == NULL)
					  	  return -1;

					  if(SM->set_nextState(menuState) != 0)
						  return -1;

					  ...engine will do the rest

				*/

		protected:
			GTS::Window* m_windows;
			std::string m_thisName;

		private:

	};

	#include "GTS_State.cpp"
}

#endif // GTS_STATE_H
