InitRes* InitRes::sm_initRes = NULL;



/// CTOR / DTOR
InitRes::InitRes()
{
	//dtor
}
InitRes::~InitRes()
{
	//dtor
}
///



/// SINGLETON METHODS
int InitRes::create()
{
	if(sm_initRes == NULL)
	{
		if(sm_initRes == NULL)
		{
			sm_initRes = new InitRes;

			return 0;
		}
	}


	printf("Intro resources already exist.\n");

	return -1;
}
InitRes* InitRes::get()
{
	return sm_initRes;
}
void InitRes::destroy()
{
	if(sm_initRes != NULL)
	{
		delete sm_initRes;
		sm_initRes = NULL;
	}
}
///



GTS::Texture* InitRes::get_texture(int index)
{
	return &m_initTex;
}



int InitRes::set()
{
	GTS::WindowManager* WM = GTS::WindowManager::get();
	if(WM == NULL)
		return -1;

	GTS::Window* window = WM->get_window(0);
	if(window == NULL)
		return -1;

	if(m_initTex.load("Textures/intro.png") != 0)
		return -1;

	m_initTex.set_outputWindow(window);

	return 0;
}



void InitRes::free()
{
	GTS::ResourceManager* rm = GTS::ResourceManager::get();// <-
	rm->detach(sm_initRes); 							   // <- you have to do this part with all resources

	destroy();
}
