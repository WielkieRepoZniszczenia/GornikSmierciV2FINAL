

Human::Human()
{
	//ctor
}

Human::~Human()
{
	//dtor
}

int Human::poll_events(SDL_Event &event)
{
	if(bKeyboardControl == true)
	{

	}
	if(bMouseControl == true)
	{

	}

	return 0;
}
int Human::state_events(SDL_Event &event)
{
	if(bKeyboardControl == true)
	{
		const Uint8* currentKeyState = SDL_GetKeyboardState(NULL);

		switch(directionSystem)
		{
			case NORMAL_CROSS:
			{
				if(currentKeyState[SDL_SCANCODE_UP])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_DOWN])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				break;
			}
			case NORMAL_ALL:
			{
				if(currentKeyState[SDL_SCANCODE_UP] && currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_UP] && currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				else if(currentKeyState[SDL_SCANCODE_DOWN] && currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_DOWN] && currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				else if(currentKeyState[SDL_SCANCODE_UP])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_DOWN])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				break;
			}
			case ISOMETRIC_CROSS:
			{
				if(currentKeyState[SDL_SCANCODE_UP])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_DOWN])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				break;
			}
			case ISOMETRIC_ALL:
			{
				if(currentKeyState[SDL_SCANCODE_UP] && currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_UP] && currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				else if(currentKeyState[SDL_SCANCODE_DOWN] && currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_DOWN] && currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				else if(currentKeyState[SDL_SCANCODE_UP])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_DOWN])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_LEFT])
				{

				}
				else if(currentKeyState[SDL_SCANCODE_RIGHT])
				{

				}

				break;
			}
		}
	}

	if(bMouseControl == true)
	{

	}

	return 0;
}
int Human::logic()
{

	return 0;
}
