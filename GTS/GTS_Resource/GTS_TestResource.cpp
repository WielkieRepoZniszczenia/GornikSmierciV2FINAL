

TestResource* TestResource::sm_TestResource = NULL;



/// SINGLETON METHODS
int TestResource::create()
{
	if(sm_TestResource != NULL)
	{
		printf("Error. You can't create multiple instances of GTS_TestResource.\n");
		return -1;
	}

	sm_TestResource = new TestResource();

	return 0;
}
TestResource* TestResource::get()
{
	return sm_TestResource;
}
void TestResource::destroy()
{
	if(sm_TestResource != NULL)
	{
		delete sm_TestResource;
		sm_TestResource = NULL;
	}
}
///



/// CONSTRUCTOR/DESTRUCTOR
TestResource::TestResource()
{
	//ctor
}
TestResource::~TestResource()
{
	//dtor
}
///



/// GET
GTS::Texture* TestResource::get(TEST_IDS index)
{
	if(index == TEST_TXE)
	{
		return &testTXE;
	}

	return NULL;
}
///


/// SET
int TestResource::set()
{
	SDL_Surface* loadedSurface = IMG_Load("dwarf01.png");
	testTXE.load(loadedSurface);

	SDL_FreeSurface(loadedSurface);

	gFont = TTF_OpenFont( "lazy.ttf", 28 );
	if( gFont == NULL )
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return -1;
	}

	return 0;
}
///



/// FREE
void TestResource::free()
{
	GTS::ResourceManager* rm = GTS::ResourceManager::get();
	rm->detach(sm_TestResource);
	destroy();
}
///
