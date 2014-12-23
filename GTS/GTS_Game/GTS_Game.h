#ifndef GTS_GAME_H
#define GTS_GAME_H


#include "GTS_Game/GTS_GameInterface.h"

#include "GTS_Player/GTS_Player.h"
#include "GTS_Map/GTS_Map.h"


/** GAME
	* this is main game class
	* it contains map and players
	* game should have all states and state connections,
	* win and lose conditions
*/
namespace GTS
{
	class Game : public GTS::GameInterface
	{
		public:
			enum GAME_STATE
			{
				PLAYER_WON = 0,

				STATE_LAST
			};
            enum WIN_CONDITIONS // this should be some class group, with win condition as interface
            {
            	SURVIVE_TIME = 0,
            	DEFEAT_ALL,
            	DEFEAT_SPECIFIC,
            	GET_RESOURCES,
            	GET_ITEM,
            	GET_ITEMS,
            	GO_TO_LOCATION,

            	CONDITION_LAST
            };
			Game();
			virtual ~Game();

			/// STATES METHODS
			GTS::State* get_firstState();
			///

			/// PLAYERS METHODS
			static const unsigned int MAX_PLAYERS; // this is engine dependent
			int add_player(GTS::Player* player);
			GTS::Player* get_player(int id);
			///

			/// MAP METHODS
			virtual int set_map() = 0; // allocate new map object
			GTS::Map* get_map();
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
			bool bSet; // if all is set for playing

			GTS::State* m_firstState; // just a pointer, can't be deleted in destructor!!

			GTS::Map* m_map;

			std::vector<GTS::Player*> m_players;

			std::vector<GTS::Player*> m_winners;
			std::vector<GTS::Player*> m_losers;

		private:

	};
	#include "GTS_Game.cpp"
}

#endif // GTS_GAME_H
