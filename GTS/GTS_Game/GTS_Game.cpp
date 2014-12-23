


/// CTOR / DTOR
Game::Game()
{
	m_map = NULL;
}
Game::~Game()
{
	if(m_map != NULL)
		delete m_map;
}
///



/// STATES METHODS
GTS::State* Game::get_firstState()
{
	return m_firstState;
}
///



/// PLAYERS METHODS
const unsigned int Game::MAX_PLAYERS = 1; // this is engine dependent
int Game::add_player(GTS::Player* player)
{
	if(player == NULL)
	{
		printf("Game error. Player is a null pointer.\n");
		return -1;
	}
	if(m_players.size() < MAX_PLAYERS)
	{
		m_players.push_back(player);
		return 0;
	}

	printf("Game error. Too many players already.\n");
	return -1;
}
GTS::Player* Game::get_player(int id)
{
	if(id >= 0 && id < (int)m_players.size())
	{
		return m_players.at(id);
	}

	return NULL;
}
///



/// MAP METHODS
GTS::Map* Game::get_map()
{
	return m_map;
}
///



/// WIN CONDITION METHODS
///



/// LOSE CONDITION METHODS
///



/// SAVE / LOAD METHODS
int Game::save(std::ofstream* fout)
{
	return 0;
}
int Game::load(std::ifstream* fin)
{
	return 0;
}
///
