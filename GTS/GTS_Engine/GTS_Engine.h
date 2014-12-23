#ifndef GTS_ENGINE_H
#define GTS_ENGINE_H

#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


#include "GTS_Utilities/iostring.cpp"
#include "GTS_Utilities/StringConversion.cpp"
#include "GTS_Utilities/triangleMath.cpp"

#include "GTS_PackCreator/GTS_PackCreator.h"

#include "GTS_Pixel32/GTS_Pixel32.h"

#include "GTS_Vector/GTS_Vector.h"

#include "GTS_Timer/GTS_Timer.h"

#include "GTS_WindowManager/GTS_WindowManager.h"


/// @@@ LOWER SECTION @@@
	/// resource manager
	#include "GTS_ResourceManager/GTS_ResourceManager.h"

	/// state machine
	#include "GTS_StateMachine/GTS_StateMachine.h"

	/// game
	#include "GTS_Game/GTS_GameInterface.h"


namespace GTS
{
	/// @@@ SINGLETON @@@
	class Engine
	{
		public:
			static bool bKillEngine;

			static int create();
			static Engine* get();
			static void kill();

			~Engine();

			int run(int x, int y, unsigned int w, unsigned int h, std::string gameTitle, GTS::GameInterface* game);

			static long get_time();
			static long get_fps();

		private:
			Engine();
			static Engine* sm_engine;

			int initialize();

			bool bInitialized;

			GTS::Timer globalClock; // it should be set as soon as engine starts, and should never be turn off

			GTS::Timer fpsTimer;
			int fpsCounter;
			int FPS;
			bool bMaxFPS;
			int maxFPS;

			GTS::WindowManager* m_windowManager;
			GTS::Window* m_mainWindow;

			GTS::GameInterface* m_game;

			GTS::ResourceManager* m_resourceManager;

			GTS::StateMachine* m_stateMachine;
			GTS::State* m_state;

			SDL_Event m_event;

	};

	#include "GTS_Engine.cpp"
}

/// @@@ UPPER SECTION @@@
	#include "GTS_Command/GTS_Command.h"

	#include "GTS_Camera/GTS_Camera.h"

	#include "GTS_Texture/GTS_Texture.h"
	#include "GTS_Text/GTS_Text.h"

	#include "GTS_Pawn/GTS_Pawn.h"

	#include "GTS_OBJ/GTS_OBJ.h"

	#include "GTS_Location/GTS_Location.h"

	#include "GTS_OBJ/GTS_Object/GTS_Object.h"
		#include "GTS_OBJ/GTS_Object/GTS_Tile/GTS_Tile.h"
		#include "GTS_OBJ/GTS_Object/GTS_Character/GTS_Character.h"
		#include "GTS_OBJ/GTS_Object/GTS_Item/GTS_Item.h"

	#include "GTS_Grid/GTS_Grid.h"

	#include "GTS_Player/GTS_Player.h"

	#include "GTS_AI/GTS_AI.h"

	#include "GTS_MiniMap/GTS_MiniMap.h"
	#include "GTS_Map/GTS_Map.h"
	#include "GTS_Game/GTS_Game.h"

	#include "GTS_Button/GTS_Button.h"


#endif // GTS_ENGINE_H
