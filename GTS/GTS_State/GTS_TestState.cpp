


/// CTOR / DTOR
TestState::TestState()
{
	// ctor
}
TestState::~TestState()
{
	//dtor
}
///



///
int TestState::set()
{
	GTS::ResourceManager* RM = GTS::ResourceManager::get();


	RM->set<GTS::TestResource>();
	RM->set<GTS::TestButtons>();

	mTestResources = GTS::TestResource::get();
	mTestButtons = GTS::TestButtons::get();


	/// test

	SDL_Surface* surfUP = IMG_Load("objG00.png");

	SDL_Rect box = {0, 0, 80, 80};
	tx1.load(surfUP, &box);

	box.x = 80;
	tx2.load(surfUP, &box);

	SDL_FreeSurface(surfUP);


	/** @@ DZIALANIE PIONKOW
		* w tym wypadku pionek 1 zawiera pionka 2, ktory zawiera pionka 3
		* metoda add_frame() dodaje klatke animacji do konkretnego pionka
		* animacje dzialaja wzgledem punktu czasowego, w tym wypadku jest to 0i przyjmuja ilosc czasu jaka uplynela od startu animacji(patrz metoda render na dole strony)
		* @param offset: polozenie wzgledem punktu zaczepienia(dla pierwszej wygodnie jest wybrac 0, ale normalnie jest to odleglosc od polozenia pionka w grze -> polozenie obiektu)
		* @param TexTrans: jest to zestaw transformacji tekstury(obrot, skala(x, y), modulacja koloru, odbicie wzgledem osi, wycinek tekstury)
		* @param TimeGap: czas wyswietlania danej klatki zanim przeskoczy do nastepnej
		* @param Texture: wskaznik do tekstury jaka ma zostac wyswietlona

		* @Uwaga! modulacja koloru i transformacja wzgledem osi moze nie dzialac w tej wersji kodu, TexTrans ma ustawione domyslne parametry tych transformacji dlatego w kodzie ich nie widac
		*/{
		testTime = 0;

		pawn1.add_frame(PawnFrame(GTS::Vec2D<int>(0, 0), GTS::TexTrans(0.0, GTS::Vec2D<double>(1.0, 1.0)), 1000, &tx1));
		//pawn1.add_frame(PawnFrame(GTS::Vec2D<int>(0, 0), GTS::TexTrans(180.0, GTS::Vec2D<double>(2.0, 2.0)), 1000, &tx1));
		pawn1.add_frame(PawnFrame(GTS::Vec2D<int>(0, 0), GTS::TexTrans(1080.0, GTS::Vec2D<double>(1.0, 1.0)), 0, &tx1));


		pawn2.set_renderOrder(GTS::Pawn::BOTTOM);
		pawn2.add_frame(PawnFrame(GTS::Vec2D<int>(100, 0), GTS::TexTrans(0.0, GTS::Vec2D<double>(1.0, 1.0)), 1000, &tx1));
		pawn2.add_frame(PawnFrame(GTS::Vec2D<int>(200, 0), GTS::TexTrans(180.0, GTS::Vec2D<double>(2.0, 2.0)), 1000, &tx1));
		pawn2.add_frame(PawnFrame(GTS::Vec2D<int>(100, 0), GTS::TexTrans(360.0, GTS::Vec2D<double>(1.0, 1.0)), 0, &tx1));


		pawn3.set_renderOrder(GTS::Pawn::TOP);
		pawn3.add_frame(PawnFrame(GTS::Vec2D<int>(100, 0), GTS::TexTrans(0.0, GTS::Vec2D<double>(1.0, 1.0)), 1000, &tx1));
		pawn3.add_frame(PawnFrame(GTS::Vec2D<int>(100, 0), GTS::TexTrans(180.0, GTS::Vec2D<double>(1.0, 1.0)), 1000, &tx1));
		pawn3.add_frame(PawnFrame(GTS::Vec2D<int>(100, 0), GTS::TexTrans(360.0, GTS::Vec2D<double>(1.0, 1.0)), 0, &tx1));

		pawn1.add_child(&pawn2);
		pawn2.add_child(&pawn3);

		testPosition.x = 300;
		testPosition.y = 300;

	}

	return 0;
}
int TestState::events(SDL_Event &event)
{
	while(SDL_PollEvent(&event) != 0)
	{
		if(event.type == SDL_QUIT)
		{
			GTS::Engine::bKillEngine = true;
		}

		/// windows type presses (single press)
		if(event.type == SDL_KEYDOWN)
		{
			if(event.key.keysym.sym == SDLK_w)
			{
				testPosition.y -= 5;
			}
			if(event.key.keysym.sym == SDLK_s)
			{
				testPosition.y += 5;
			}
			if(event.key.keysym.sym == SDLK_a)
			{
				testPosition.x -= 5;
			}
			if(event.key.keysym.sym == SDLK_d)
			{
				testPosition.x += 5;
			}
		}

		mTestButtons->get(GTS::TestButtons::BUTTON_0)->events(event);
	}

	/// dynamic presses (keyboard state)
	const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
	if(keyboardState[SDL_SCANCODE_UP])
	{
		testPosition.y -= 5;
	}
	if(keyboardState[SDL_SCANCODE_DOWN])
	{
		testPosition.y += 5;
	}
	if(keyboardState[SDL_SCANCODE_LEFT])
	{
		testPosition.x -= 5;
	}
	if(keyboardState[SDL_SCANCODE_RIGHT])
	{
		testPosition.x += 5;
	}

	return 0;
}
int TestState::logic()
{
	GTS::Engine* pEngine = GTS::Engine::get();
	FPS = pEngine->get_fps();

	mTestButtons->get(GTS::TestButtons::BUTTON_0)->update(pEngine->get_time());

	return 0;
}
int TestState::sounds()
{
	return 0;
}
int TestState::render()
{
	mTestButtons->get(GTS::TestButtons::BUTTON_0)->render();
	GTS::TexTrans trans;

	//testAngle += 2.0; /// pionek mozna jeszcze transformowac po wstepnym ustawieniu, ale nie ma takiej potrzeby w tej chwili
	trans.angle = testAngle;


	testTime += 12; /** * testTime to czas jaki uplynal od poczatku wyswietlania animacji
						* testPosition to aktualna pozycja "obiektu" na ekranie
						* @UWAGA! mozna ja zmieniac strzalkami lub WSAD'em
					*/
	if(pawn1.render(testPosition, trans, testTime) != 0)
		return -1;
///

	/////
	SDL_Color color = {0, 0, 0};
	GTS::Text textTest;
	if(textTest.set("FPS: " + IntToString(FPS), gFont, color, m_windows->get_renderer()) != 0)
	{
		printf("Can't render the text.\n");
		return -1;
	}

	if(mTestButtons->get(GTS::TestButtons::BUTTON_0)->const_check() == true)
		if(textTest.render(100, 0, m_windows) != 0)
			return -1;

	return 0;
}
int TestState::clear()
{
	return 0;
}


