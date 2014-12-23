
Engine* Engine::sm_engine = NULL;
bool Engine::bKillEngine = false;



/// SINGLETON METHODS
int Engine::create()
{
	if(sm_engine == NULL)
	{
		if(sm_engine == NULL)
		{
			sm_engine = new Engine();
		}
	}
	else
	{
		printf("Error. You can't create multiple instances of GTS::Engine.\n");
		return -1;
	}

	return 0;
}
Engine* Engine::get()
{
	return sm_engine;
};
void Engine::kill()
{
	if(sm_engine != NULL)
	{
		delete sm_engine;
		sm_engine = NULL;
	}
}
///



/// CTOR / DTOR
Engine::Engine()
{
    m_windowManager = NULL;
    m_mainWindow = NULL;

    m_game = NULL;

    m_resourceManager = NULL;

    m_stateMachine = NULL;
    m_state = NULL;

	bMaxFPS = true;
    maxFPS = 60;
}
Engine::~Engine()
{
	GTS::StateMachine::destroy();

	GTS::ResourceManager::destroy();

    IMG_Quit();

    SDL_Quit();
}
///



/// INITIALIZE
int Engine::initialize()
{
	 ////// SDL VIDEO //////
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Fail to initialize video! SDL Error: %s\n", SDL_GetError());
		return -1;
    }

    ////// IMG //////
    if(!IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)
    {
        printf("Fail to initialize PNG decoder! SDL_img Error: %s\n", IMG_GetError());
        return -1;
    }

    ////// TTF //////
    if(TTF_Init() == -1)
	{
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
		return -1;
	}

	////// WINDOW MANAGER //////
    GTS::WindowManager::create();
    m_windowManager = GTS::WindowManager::get();
    if(m_windowManager == NULL)
	{
		printf("Engine error. Fail to initialize Window Manager.\n");
		return -1;
	}

	////// RESOURCE MANAGER //////
	GTS::ResourceManager::create();
	m_resourceManager = GTS::ResourceManager::get();
	if(m_resourceManager == NULL)
	{
		printf("Engine error. Fail to initialize Resource Manager.\n");
		return -1;
	}

	////// STATE MACHINE //////
    GTS::StateMachine::create();
    m_stateMachine = GTS::StateMachine::get();
    if(m_stateMachine == NULL)
	{
		printf("Engine error. Fail to initialize State Machine.\n");
		return -1;
	}

	return 0;
}
///



/// RUN
int Engine::run(int x, int y, unsigned int w, unsigned int h, std::string gameTitle, GTS::GameInterface* game)
{
    if(initialize() != 0)
	{
		printf("Could not initialize engine.\n");
		return -1;
	}
	if(game == NULL)
	{
		printf("Engine error. Engine can't run on null game.\n");
		return -1;
	}
	m_game = game;
	if(m_game->set() != 0)
	{
		printf("Engine error. Could not set game.\n");
		return -1;
	}

	if(m_windowManager->create_window(0, gameTitle, x, y, w, h) != 0)
    {
    	printf("Engine error. Could not create default window.\n");
        return -1;
    }
    m_mainWindow = m_windowManager->get_window(0);

	globalClock.start();


    if(m_stateMachine->set_nextState(m_game->get_firstState()) != 0)
	{
		printf("Engine can't run on null state pointer.\n");
		return -1;
	}

	GTS::Timer testTimer;
    while(bKillEngine == false)
	{
		long dt = 0;
		testTimer.start();

		/** @@ UPDATE STATE @@
        	*/{
				if(m_stateMachine->changed() == true)
				{
					if(m_stateMachine->swtch_to_nextState() != 0)
					{
						printf("Engine error. Could not switch to next state.\n");
						return -1;
					}

					m_state = m_stateMachine->get_currentState();
					if(m_state == NULL)
					{
						printf("Engine could not set state. \n");
						return -1;
					}
				}
        	}

		/** @@ EVENTS @@
			*/{
				if(m_state->events(m_event) != 0)
				{
					printf("Engine event error.\n");
					return -1;
				}
			}

		/** @@ LOGIC @@
			*/{
				if(m_state->logic() != 0)
				{
					printf("Engine logic error.\n");
					return -1;
				}
			}

		/** @@ SOUNDS @@
			*/{
				if(m_state->sounds() != 0)
				{
					printf("Engine sound error.\n");
					return -1;
				}
			}

		/** @@ RENDER @@
			*/{
				m_mainWindow->clear();
				if(m_state->render() != 0)
				{
					printf("Engine render error.\n");
					return -1;
				}
				m_mainWindow->update();
			}

		/** @@ FPS REGULATION @@
			*/{
				++fpsCounter;

				if(fpsTimer.is_started() == false)
				{
					fpsTimer.start();
					fpsCounter = 0;
				}

				if(fpsTimer.get_ticks() > 1000)
				{
					FPS = fpsCounter;
					fpsTimer.stop();
				}


				if(bMaxFPS == true)
				{
					dt = testTimer.get_ticks();
					long time_to_wait = 1000/maxFPS - dt;
					if(time_to_wait > 0)
					{
						SDL_Delay(time_to_wait);
					}
				}

			}

	}



    return 0;
}

long Engine::get_time()
{
	if(sm_engine != NULL)
		return sm_engine->globalClock.get_ticks();

	return 0;
}

long Engine::get_fps()
{
	if(sm_engine != NULL)
		return sm_engine->FPS;

	return 0;
}
