

/// CTOR
Text::Text()
{
	mTexture = NULL;
	m_renderer = NULL;

	mDim.w = 0;
	mDim.h = 0;
}
Text::~Text()
{
	free();
}
///



/// SET
int Text::set(std::string str, TTF_Font* font, SDL_Color color, GTS::Window* window)
{
	free();

	if(font == NULL)
	{
		printf("Could not set text: %s\nNULL font was passed as argument.\n", str.c_str());
		return -1;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, str.c_str(), color);
	if(textSurface == NULL)
	{
		printf("Could not render text: %s\nTTF_Error: %s\n", str.c_str(), TTF_GetError());
		return -1;
	}
	GTS::Vec2D<unsigned int> surfaceDim;
						 	 surfaceDim.w = textSurface->w;
						 	 surfaceDim.h = textSurface->h;

	GTS::Window* pWindow = window;
	if(pWindow == NULL)
	{
		GTS::WindowManager* WM = GTS::WindowManager::get();
		if(WM == NULL)
		{
			printf("Text error. Window Manager is a null pointer.\n");
			return -1;
		}
		pWindow = WM->get_window(0);
		if(pWindow == NULL)
		{
			printf("Text error. Could not render text. Destination window is a null pointer.\n");
			return -1;
		}
		m_renderer = pWindow->get_renderer();
	}
	mTexture = SDL_CreateTextureFromSurface(m_renderer, textSurface);

	SDL_FreeSurface(textSurface);

	if(mTexture == NULL)
	{
		printf("Could not create texture from rendered text: %s\nSDL_Error: %s", str.c_str(), SDL_GetError());
		return -1;
	}

	mDim = surfaceDim;
	mRecentStr = str;

	return 0;
}
///



/// FREE
void Text::free()
{
	if(mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mDim.w = 0;
		mDim.h = 0;
	}
}
///



/// RENDER
int Text::render(int x, int y, GTS::TexTrans* trans)
{
	SDL_Rect scaledRect = {x, y, mDim.w, mDim.h};
	SDL_Rect* clip = NULL;
	GTS::Vec2D<double> scale(1.0, 1.0);
	double angle = 0.0;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if(trans != NULL)
    {
    	if(trans->clip != NULL)
		{
			clip = trans->clip;
			scaledRect.w = trans->clip->w;
			scaledRect.h = trans->clip->h;
		}

		scaledRect.x *= trans->scale.x;
		scaledRect.y *= trans->scale.y;
		scaledRect.w *= trans->scale.w;
		scaledRect.h *= trans->scale.h;

		angle = trans->angle;

		flip = trans->flip;
	}
	if(SDL_RenderCopyEx(m_renderer, mTexture, clip, &scaledRect, angle, NULL, flip) != 0)
	{
		printf("Could not render text: %s\n", mRecentStr.c_str());
		return -1;
	}

	return 0;
}
///
