#ifndef DIG_INITIALIZEGAME_H
#define DIG_INITIALIZEGAME_H

#include "GTS_State/GTS_State.h"

namespace DIG
{
	class InitializeGame : public GTS::State
	{
		public:
			InitializeGame();
			~InitializeGame();

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

			DIG::InitRes* m_initRes;

			GTS::Timer m_timer;

			enum INIT_RES
			{
				INIT_TERRAIN = 0,
				INIT_GRID,

				INIT_LAST
			};
			int m_initCounter;

			TTF_Font* m_font;
			GTS::Text m_text;
	};
	#include "DIG_InitializeGame.cpp"
	//#include "DIG_Initialize.cpp"
}

#endif // DIG_INITIALIZEGAME_H
