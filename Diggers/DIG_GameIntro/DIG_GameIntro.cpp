

/// CTOR / DTOR
GameIntro::GameIntro()
{
	m_menuState = NULL;
	m_thisName = "game intro";

	m_introRes = NULL;

	m_mainWindow = NULL;
}
GameIntro::~GameIntro()
{
	//dtor
}
///



/// BASE METHODS
int GameIntro::set()
{
	GTS::ResourceManager* rm = GTS::ResourceManager::get();
	rm->set<DIG::IntroRes>();

	m_introRes = DIG::IntroRes::get();
	if(m_introRes == NULL)
	{
		printf("Could not set intro resources. \n");
		return -1;
	}

	GTS::WindowManager* WM = GTS::WindowManager::get();
	if(WM == NULL)
		return -1;

	m_mainWindow = WM->get_window(0);
	if(m_mainWindow == NULL)
		return -1;

	return 0;
}
int GameIntro::events(SDL_Event &event)
{
	while(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_QUIT)
		{
			GTS::Engine::bKillEngine = true;
		}

		if(event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_0)
			{
				if(m_mainWindow->fullScreen(false) != 0)
					return -1;
			}
			else if(event.key.keysym.sym == SDLK_1)
			{
				if(m_mainWindow->fullScreen(true) != 0)
					return -1;
			}
		}
	}
	return 0;
}
int GameIntro::logic()
{
	return 0;
}
int GameIntro::sounds()
{
	return 0;
}
int GameIntro::render()
{
	GTS::Texture* pTex = m_introRes->get_texture(0);

	if(pTex->render(0, 0) != 0)
		return -1;

	return 0;
}
int GameIntro::clear()
{
	return 0;
}
///



/// BASE METHODS
void GameIntro::set_menuState(GTS::State& menuState)
{
	m_menuState = &menuState;
}
///
