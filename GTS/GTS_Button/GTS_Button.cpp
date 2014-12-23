
const int Button::LINK_BREAK = -1;


Button::Button()
{
	bActive = true;

	bPressed = false;
	bChecked = false;

	mBounceTime = 0;
	mBounceStartTime = 0;

	bMouseOver = false;
	bGlobalMouseOver = NULL;

	/// BOX
	mBox.x = 0;
	mBox.y = 0;
	mBox.w = 0;
	mBox.h = 0;

	/// LINK SYSTEM
	bLinked = false;
	mLink = NULL;
	mLinkID = LINK_BREAK;

	/// TEXTURES
	mPressedTexture = NULL;
	mUnpressedTexture = NULL;
	mHighlightedTexture = NULL;
	mInactiveTexture = NULL;
}

Button::~Button()
{
	//dtor
}

bool Button::const_check()
{
	return bPressed;
}
bool Button::single_check()
{
	if(bChecked == false)
	{
		bChecked = true;
		return bPressed;
	}

	return false;
}


void Button::set_box(int x, int y, unsigned int w, unsigned int h)
{
	mBox.x = x;
	mBox.y = y;
	mBox.w = w;
	mBox.h = h;
}

void Button::set_active(bool flag)
{
	bActive = flag;
}

int Button::set_link(int &link, int buttonID)
{
	if(buttonID == LINK_BREAK)
	{
		printf("Button linkID can't be set to LINK_BREAK value.\n");
		return -1;
	}
	mLink = &link;
	mLinkID = buttonID;

	return 0;
}

void Button::set_bounce(long bounceTime)
{
	mBounceTime = bounceTime;
}

void Button::set_globalMouseOver(bool &globalMouseOver)
{
	bGlobalMouseOver = &globalMouseOver;
}

int Button::set_unpressedTexture(GTS::Texture* texture)
{
	if(texture == NULL)
	{
		printf("Could not set button unpressed texture. Argument is NULL pointer.\n");
		return -1;
	}

	mUnpressedTexture = texture;

	return 0;
}

int Button::set_pressedTexture(GTS::Texture* texture)
{
	if(texture == NULL)
	{
		printf("Could not set button pressed texture. Argument is NULL pointer.\n");
		return -1;
	}

	mPressedTexture = texture;

	return 0;
}

int Button::set_highlightedTexture(GTS::Texture* texture)
{
	if(texture == NULL)
	{
		printf("Could not set button highlighted texture. Argument is NULL pointer.\n");
		return -1;
	}

	mHighlightedTexture = texture;

	return 0;
}

int Button::set_inactiveTexture(GTS::Texture* texture)
{
	if(texture == NULL)
	{
		printf("Could not set button inactive texture. Argument is NULL pointer.\n");
		return -1;
	}

	mInactiveTexture = texture;

	return 0;
}

void Button::set_press(bool flag)
{
	if(bPressed != flag)
	{
		bChecked = false;
	}
	if(mLink != NULL)
	{
		if(flag == true)
		{
			*mLink = mLinkID;
		}
		else // flag == false
		{
			if(mBounceTime == 0)
				*mLink = LINK_BREAK;
		}
	}
	if(flag == false)
	{
		mBounceStartTime = 0;
	}
	bPressed = flag;
}



int Button::events(SDL_Event &event)
{
	if(mBox.w == 0 || mBox.h == 0)
	{
		printf("Error! Button collisions are not set.\n");
		return -1;
	}
	if(bActive == true)
	{
		int x = event.motion.x;
        int y = event.motion.y;

		if(x > mBox.x && x < mBox.x + mBox.w
		&& y > mBox.y && y < mBox.y + mBox.h)
		{
			bMouseOver = true;
			if(bGlobalMouseOver != NULL)
			{
				*bGlobalMouseOver = true;
			}
			if(event.type == SDL_MOUSEBUTTONDOWN)
			{
				if(event.button.button == SDL_BUTTON_LEFT)
				{
					if(mBounceTime == 0)
					{
						if(bPressed == false)
						{
							set_press(true);
						}
						else // bPressed == true
						{
							set_press(false);
						}
					}
					else // mBounceTime != 0
					{
						set_press(true);
					}
				}
			}
		}
		else // mouse outside button collision
		{
			bMouseOver = false;
			if(bGlobalMouseOver != NULL)
			{
				*bGlobalMouseOver = false;
			}
		}
	}

	return 0;
}

void Button::update(long currentTime)
{
	if(mLink != NULL)
	{
		if(*mLink != mLinkID)
		{
			set_press(false);
		}
	}
	if(mBounceTime != 0)
	{
		if(bPressed == true)
		{
			if(mBounceStartTime != 0)
			{
				if(currentTime - mBounceStartTime > mBounceTime)
				{
					mBounceStartTime = 0;
					set_press(false);
				}
			}
			else
			{
				mBounceStartTime = currentTime;
			}
		}

	}
}

int Button::render()
{
	if(mUnpressedTexture == NULL)
	{
		printf("Could not render button. There is no unpressed texture.\n");
		return -1;
	}

	if(bActive == true)
	{
		if(bPressed == false)
		{
			mUnpressedTexture->render(mBox.x, mBox.y);
		}
		if(bPressed == true)
		{
			if(mPressedTexture != NULL)
			{
				mPressedTexture->render(mBox.x, mBox.y);
			}
			else // mPressedTexture == NULL
			{
				mUnpressedTexture->render(mBox.x, mBox.y);
			}
		}
		if(mHighlightedTexture != NULL)
		{
			if(bMouseOver == true)
				mHighlightedTexture->render(mBox.x, mBox.y);
		}
	}
	else // bActive == false
	{
		if(mInactiveTexture != NULL)
		{
			mInactiveTexture->render(mBox.x, mBox.y);
		}
		else // mInactiveTexture == NULL
		{
			mUnpressedTexture->render(mBox.x, mBox.y);
		}
	}

	return 0;
}


