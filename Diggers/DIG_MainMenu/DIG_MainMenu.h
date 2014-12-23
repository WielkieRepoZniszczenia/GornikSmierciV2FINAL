#ifndef DIG_MAINMENU_H
#define DIG_MAINMENU_H

#include "GTS_State/GTS_State.h"


namespace DIG
{
	class MainMenu : public GTS::State
	{
		public:
			MainMenu();
			~MainMenu();

			/// base methods
				int set();

				int events(SDL_Event &event);

				int logic();

				int sounds();

				int render();

				int clear();

		protected:
		private:
	};

	#include "DIG_MainMenu.cpp"

}
#endif // DIG_MAINMENU_H
