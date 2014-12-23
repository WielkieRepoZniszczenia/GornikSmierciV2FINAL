

TestButtons* TestButtons::sm_TestButtons = NULL;



/// SINGLETON METHODS
int TestButtons::create()
{
	if(sm_TestButtons != NULL)
	{
		printf("Error. You can't create multiple instances of GTS_TestResource.\n");
		return -1;
	}

	sm_TestButtons = new TestButtons();

	return 0;
}
TestButtons* TestButtons::get()
{
	return sm_TestButtons;
}
void TestButtons::destroy()
{
	if(sm_TestButtons != NULL)
	{
		delete sm_TestButtons;
		sm_TestButtons = NULL;
	}
}
///



/// CONSTRUCTOR / DESTRUCTOR
TestButtons::TestButtons()
{
	//ctor
}
TestButtons::~TestButtons()
{
	//dtor
}
///


/// GET
GTS::Button* TestButtons::get(TEST_BUTTONS index)
{
	return &button;
}
///



/// SET
int TestButtons::set()
{
	SDL_Surface* surfUP = IMG_Load("objG00.png");

	SDL_Rect box = {0, 0, 80, 80};
	unpressed.load(surfUP, &box);

	box.x = 80;
	pressed.load(surfUP, &box);

	box.x = 160;
	highlighted.load(surfUP, &box);

	button.set_box(0, 0, 80, 80);
	button.set_bounce(1000); // nie dziala
	button.set_unpressedTexture(&unpressed);
	button.set_pressedTexture(&pressed);
	button.set_highlightedTexture(&highlighted);

	SDL_FreeSurface(surfUP);

	return 0;
}
///



/// FREE
void TestButtons::free()
{
	GTS::ResourceManager* rm = GTS::ResourceManager::get();
	rm->detach(sm_TestButtons);
	destroy();
}
///
