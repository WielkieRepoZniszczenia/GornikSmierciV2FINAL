


/// CTOR / DTOR
InitializeGame::InitializeGame()
{
	m_menuState = NULL;
	m_thisName = "Game initialization state";
	m_initCounter = INIT_TERRAIN;
	m_font = NULL;
}
InitializeGame::~InitializeGame()
{
	clear();
	TTF_CloseFont(m_font);
}
///



/// BASE METHODS
int InitializeGame::set()
{
	m_timer.start();

	GTS::ResourceManager* rm = GTS::ResourceManager::get();
	rm->set<DIG::InitRes>();

	m_initRes = DIG::InitRes::get();
	if(m_initRes == NULL)
	{
		printf("Could not set intro resources. \n");
		return -1;
	}

	m_font = TTF_OpenFont("oneway.ttf", 28);

	return 0;
}
int InitializeGame::events(SDL_Event &event)
{
	while(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_QUIT)
		{
			GTS::Engine::bKillEngine = true;
		}
	}
	return 0;
}
int InitializeGame::logic()
{
	if(m_timer.get_ticks() > 20000)
	{
		m_timer.start();
		++m_initCounter;
	}

	if(m_initCounter == INIT_TERRAIN)
	{
		SDL_Color color = {255, 255, 255};
		if(m_text.set("initializing... terrain", m_font, color) != 0)
		{
			printf("Initialize error. Could not set text.\n");
			return -1;
		}

        GTS::ResourceManager* RM = GTS::ResourceManager::get();
        if(RM->set<DIG::TileRes>() != 0)
		{
			printf("Initialize error. Could not set TileRes.\n");
			return -1;
		}
	}
	if(m_initCounter == INIT_GRID)
	{

	}
	if(m_initCounter == INIT_LAST)
	{
		if(m_menuState == NULL)
		{
			printf("Could not set menu state.\n");
			return -1;
		}

		GTS::StateMachine* SM = GTS::StateMachine::get();
		if(SM == NULL)
		{
			printf((m_thisName + " could not get state machine.\n" ).c_str());
			return -1;
		}

		SM->set_nextState(m_menuState);
	}

	return 0;
}
int InitializeGame::sounds()
{
	return 0;
}
int InitializeGame::render()
{
	/** @@ BACKGROUND @@
		*/{
			GTS::Texture* pTex = m_initRes->get_texture(0);

			if(pTex->render(0, 0) != 0)
			{
				printf("Initialize error. Could not render background.\n");
				return -1;
			}
		}

	if(m_initCounter == INIT_TERRAIN)
	{
		m_text.render(100, 800);
	}

	return 0;
}
int InitializeGame::clear()
{
	m_text.free();
	return 0;
}
///



/// STATE-SPECIFIC METHODS
void InitializeGame::set_menuState(GTS::State& menuState)
{
	m_menuState = &menuState;
}
///
