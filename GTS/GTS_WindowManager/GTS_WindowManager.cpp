WindowManager* WindowManager::sm_windowManager = NULL;



/// CTOR / DTOR
WindowManager::WindowManager()
{
	//ctor
}
WindowManager::~WindowManager()
{
	//dtor
}
///



/// SINGLETON METHODS
int WindowManager::create()
{
	if(sm_windowManager == NULL)
	{
		if(sm_windowManager == NULL)
		{
			sm_windowManager = new WindowManager;
			return 0;
		}
	}

	printf("Error, window manager already exist.\n");

	return -1;
}
WindowManager* WindowManager::get()
{
	return sm_windowManager;
}
void WindowManager::destroy()
{
	if(sm_windowManager != NULL)
	{
		delete sm_windowManager;
		sm_windowManager = NULL;
	}
}
///



int WindowManager::create_window(int windowID, std::string title, int x, int y, unsigned int w, unsigned int h)
{
	if(sm_windowManager != NULL)
	{
		std::map<int, GTS::Window>::iterator iLocator;
		for(iLocator = m_windows.begin(); iLocator != m_windows.end(); ++iLocator)
		{
			if(iLocator->first == windowID)
			{
				printf("Could not create window. Window with given ID already exist.\n");
				return -1;
			}
		}

		m_windows.insert(std::make_pair(windowID, GTS::Window()));

		for(iLocator = m_windows.begin(); iLocator != m_windows.end(); ++iLocator)
		{
			if(iLocator->first == windowID)
			{
				GTS::Window* window = &iLocator->second;
				window->set(title, x, y, w, h);

				return 0;
			}
		}

		printf("Could not set new window.\n");
		return -1;
	}

	printf("WindowManager error. WindowManager does not exist.\n");
	return -1;
}
GTS::Window* WindowManager::get_window(int windowID)
{
	if(sm_windowManager != NULL)
	{
		std::map<int, GTS::Window>::iterator iLocator;
		for(iLocator = m_windows.begin(); iLocator != m_windows.end(); ++iLocator)
		{
			if(iLocator->first == windowID)
			{
				return &iLocator->second;
			}
		}
	}

	return NULL;
}
