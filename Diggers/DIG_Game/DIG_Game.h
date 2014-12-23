#ifndef DIG_GAME_H
#define DIG_GAME_H

#include "GTS_Game/GTS_Game.h"

/// -> DIG mechanics
#include "DIG_Map/DIG_Map.h"
/// <-

/// -> DIG resources
#include "DIG_Resources/DIG_InitRes.h"
#include "DIG_Resources/DIG_MenuRes.h"
#include "DIG_Resources/DIG_TileRes.h"
/// <-

/// -> DIG states
#include "DIG_InitializeGame/DIG_InitializeGame.h"
#include "DIG_MainMenu/DIG_MainMenu.h"
/// <-


namespace DIG
{
	class Game : public GTS::Game
	{
		public:
			Game();
			virtual ~Game();

			virtual int set();

			/// MAP METHODS
			virtual int set_map();
			///

			/// WIN CONDITION METHODS
			///

			/// LOSE CONDITION METHODS
			///

			/// SAVE / LOAD METHODS
			virtual int save(std::ofstream* fout);
			virtual int load(std::ifstream* fin);
			///

		protected:
		private:
			DIG::InitializeGame m_initializeState;
			DIG::MainMenu m_mainMenu;

	};

	#include "DIG_Game.cpp"

}
#endif // DIG_GAME_H
