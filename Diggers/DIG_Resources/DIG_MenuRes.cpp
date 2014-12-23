MenuRes* MenuRes::sm_menuRes = NULL;



/// CTOR / DTOR
MenuRes::MenuRes()
{
	//dtor
}
MenuRes::~MenuRes()
{
	//dtor
}
///



/// SINGLETON METHODS
int MenuRes::create()
{
	if(sm_menuRes == NULL)
	{
		if(sm_menuRes == NULL)
		{
			sm_menuRes = new MenuRes;

			return 0;
		}
	}


	printf("Intro resources already exist.\n");

	return -1;
}
MenuRes* MenuRes::get()
{
	return sm_menuRes;
}
void MenuRes::destroy()
{
	if(sm_menuRes != NULL)
	{
		delete sm_menuRes;
		sm_menuRes = NULL;
	}
}
///



int MenuRes::set()
{
	GTS::WindowManager* WM = GTS::WindowManager::get();
	if(WM == NULL)
		return -1;

	GTS::Window* window = WM->get_window(0);
	if(window == NULL)
		return -1;

	// set resources here

	return 0;
}



void MenuRes::free()
{
	GTS::ResourceManager* rm = GTS::ResourceManager::get();// <-
	rm->detach(sm_menuRes); 							   // <- you have to do this part with all resources

	destroy();
}
