


/// CTOR / DTOR
Game::Game()
{
	//ctor
}
Game::~Game()
{
	//dtor
}
///



/// SET
int Game::set()
{
	m_firstState = &m_initializeState;

	m_initializeState.set_menuState(m_mainMenu);

	return 0;
}
///



/// MAP METHODS
int Game::set_map()
{
	m_map = new DIG::Map;

	return 0;
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
