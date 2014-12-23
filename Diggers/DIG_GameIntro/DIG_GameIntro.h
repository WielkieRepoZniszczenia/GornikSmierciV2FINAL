#ifndef DIG_GAMEINTRO_H
#define DIG_GAMEINTRO_H

#include "GTS_State/GTS_State.h"

namespace DIG
{
	class GameIntro : public GTS::State
	{
		public:
			GameIntro();
			~GameIntro();

			/// base methods
				int set();

				int events(SDL_Event &event);

				int logic();

				int sounds();

				int render();

				int clear();

			/// state-specific methods
				void set_menuState(GTS::State& menuState);

		protected:

		private:
			GTS::State* m_menuState;

			DIG::IntroRes* m_introRes;

			GTS::Window* m_mainWindow;
	};
	#include "DIG_GameIntro.cpp"
}

#endif // DIG_GAMEINTRO_H
