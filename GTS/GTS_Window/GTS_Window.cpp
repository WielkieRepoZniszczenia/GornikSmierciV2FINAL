


/// CTOR / DTOR
Window::Window()
{
    mRes = RES_1600x900; // default
    mScale.x = 1;
    mScale.y = 1;

	mWindow = NULL;
	mRenderer = NULL;

    mWDefDim.x = 1600;
    mWDefDim.y = 900;

    mWDim.x = mWDefDim.x;
    mWDim.y = mWDefDim.y;

    mDefColor.r = 255;
    mDefColor.g = 255;
    mDefColor.b = 255;
    mDefColor.a = 255;
}
Window::~Window()
{
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
}
///


int Window::set(std::string title, int x, int y, unsigned int w, unsigned int h)
{
	mTitle = title;
	mWDim.x = x;
	mWDim.y = y;
	mWDim.w = w;
	mWDim.h = h;

	mWDefDim.x = w;
    mWDefDim.y = h;

	if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
	{
		printf( "Warning: Linear texture filtering not enabled!" );
		return -1;
	}

    mWindow = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN);
    //mWindow = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE );

	if(mWindow == NULL)
	{
		printf("Fail to create window: %s\n", SDL_GetError());
		return -1;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
	if(mRenderer == NULL)
	{
		printf("Could not create renderer: %s\n", SDL_GetError());
		return -1;
	}

    return 0;
}
int Window::resize(GTS_RESOLUTION resolution) // GTS_RESOLUTION mode
{
    switch(resolution)
    {
        case RES_640x480:
        {
            mWDim.w = 640;
            mWDim.h = 480;
            break;
        }
        case RES_800x600:
        {
            mWDim.w = 800;
            mWDim.h = 600;
            break;
        }
        case RES_1024x768:
		{
			mWDim.w = 1024;
            mWDim.h = 768;
            break;
		}
		/*case RES_1152x864:
		{
			mWDim.w = 1152;
            mWDim.h = 864;
            break;
		} */
		case RES_1280x720:
		{
			mWDim.w = 1280;
            mWDim.h = 720;
            break;
		}
		/*case RES_1280x800:
		{
			mWDim.w = 1280;
            mWDim.h = 800;
            break;
		}*/
		/*case RES_1280x960:
		{
			mWDim.w = 1280;
            mWDim.h = 960;
            break;
		}*/
		/*case RES_1360x768:
		{
			mWDim.w = 1360;
            mWDim.h = 768;
            break;
		}*/
		case RES_1600x900:
		{
			mWDim.w = 1600;
            mWDim.h = 900;
            break;
		}
		/*case RES_1600x1024:
		{
			mWDim.w = 1600;
            mWDim.h = 1024;
            break;
		}*/
		/*case RES_1680x1050:
		{
			mWDim.w = 1680;
            mWDim.h = 1050;
            break;
		}*/
		case RES_1920x1080:
		{
			mWDim.w = 1920;
            mWDim.h = 1080;
            break;
		}
        default:
        {
            mWDim.w = mWDefDim.x;
            mWDim.h = mWDefDim.y;
            break;
        }
    }
    SDL_SetWindowSize(mWindow, mWDim.w, mWDim.h);
    mScale.x = (double)mWDim.w/mWDefDim.x;
	mScale.y = (double)mWDim.h/mWDefDim.y;
    mRes = resolution;

    return 0;
}

int Window::fullScreen(bool flag)
{
	if(flag == true)
	{
		if(SDL_SetWindowFullscreen(mWindow, SDL_TRUE) != 0)
		{
			printf("Could not set full screen on. SDL Error: %s\n", SDL_GetError());
			return -1;
		}
	}
	else
	{
		if(SDL_SetWindowFullscreen(mWindow, SDL_FALSE) != 0)
		{
			printf("Could not set full screen off. SDL Error: %s\n", SDL_GetError());
			return -1;
		}
	}

	return 0;
}

SDL_Renderer* Window::get_renderer()
{
	return mRenderer;
}
GTS::Vec2D<double> Window::get_scale()
{
	return mScale;
}
SDL_Rect Window::get_wdim()
{
	return mWDim;
}

SDL_Rect Window::align(SDL_Rect& rect)
{
    SDL_Rect clipedRect;
             clipedRect.x = 0;
             clipedRect.y = 0;
             clipedRect.w = 0;
             clipedRect.h = 0;

    /// X
    if(rect.x < 0)
    {
        clipedRect.x = rect.x*(-1);
        if(rect.x + rect.w >= mWDim.w/mScale.x)
        {
            clipedRect.w = mWDim.w/mScale.x;
        }
        else
        {
            clipedRect.w = rect.w + rect.x;
        }
    }
    else if(rect.x < mWDim.w/mScale.x)
    {
        if(rect.x + rect.w < mWDim.w/mScale.x)
        {
            clipedRect.w = rect.w;
        }
        else
        {
            clipedRect.w = mWDim.w/mScale.x - rect.x;
        }
    }
    /// Y
    if(rect.y < 0)
    {
        clipedRect.y = rect.y*(-1);
        if(rect.y + rect.y >= mWDim.h/mScale.y)
        {
            clipedRect.h = mWDim.h/mScale.y;
        }
        else
        {
            clipedRect.h = rect.h + rect.y;
        }
    }
    else if(rect.y < mWDim.h/mScale.y)
    {
        if(rect.y + rect.h < mWDim.h/mScale.y)
        {
            clipedRect.h = rect.h;
        }
        else
        {
            clipedRect.h = mWDim.h/mScale.y - rect.y;
        }
    }

    return clipedRect;
}

int Window::apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip)
{
    SDL_Rect srcRect;
    if(clip != NULL)
    {
        srcRect = *clip;
        srcRect.x += x;
        srcRect.y += y;
    }
    else
    {
        srcRect.x = x;
        srcRect.y = y;
        srcRect.w = source->w;
        srcRect.h = source->h;
    }

    SDL_Rect scaleBox;
             scaleBox.x = x*mScale.x;
             scaleBox.y = y*mScale.y;
             scaleBox.w = srcRect.w*mScale.x;
             scaleBox.h = srcRect.h*mScale.y;

    SDL_Rect box = align(srcRect);

    if(source == NULL)
    {
        printf("No source surface! \n");
        return -1;
    }
   /* if(SDL_BlitScaled(source, &box, screen, &scaleBox) != 0)
    {
        printf("Fail to blit surface: %s\n", SDL_GetError());
        return -1;
    } */

    return 0;
}

int Window::clear(Pixel32* color)
{
	if(color != NULL)
		SDL_SetRenderDrawColor(mRenderer, color->r, color->g, color->b, color->a);
	else
		SDL_SetRenderDrawColor(mRenderer, mDefColor.r, mDefColor.g, mDefColor.b, mDefColor.a);

	if(SDL_RenderClear(mRenderer) != 0)
	{
		printf("Could not clear window: %s\n", SDL_GetError());
		return -1;
	}

	return 0;
}

void Window::update()
{
	SDL_RenderPresent(mRenderer);
}
