

/// CTOR / DTOR
Texture::Texture()
{
	m_window = NULL;

	m_texture = NULL;

	m_dim.w = 0;
	m_dim.h = 0;

	m_center = NULL;

	bSet = false;
	bLockable = true;
}
Texture::~Texture()
{
	if(m_texture != NULL)
		SDL_DestroyTexture(m_texture);

	if(m_center != NULL)
		delete m_center;
}
///



/// CREATE TEXTURE
int Texture::createBlank(int width, int height, SDL_TextureAccess access)
{
	if(bSet == true)
	{
		printf("Texture error. Texture is already set.\n");
		return -1;
	}

	GTS::WindowManager* WM = GTS::WindowManager::get();
	if(WM == NULL)
	{
		printf("Texture error. Could not open window manager.\n");
		return -1;
	}

	// set main window as default target
	m_window = WM->get_window(0);
	if(m_window == NULL)
	{
		printf("Texture error. Could not set default window.\n");
		return -1;
	}

	if(access == SDL_TEXTUREACCESS_STATIC)
		bLockable = false;

	if(m_window == NULL)
	{
		printf("Texture error. Unable to create blank texture! Window is a null pointer.\n");
		return -1;
	}

	m_texture = SDL_CreateTexture(m_window->get_renderer(), SDL_PIXELFORMAT_RGBA8888, access, width, height);
	if(m_texture == NULL)
	{
		printf("Texture error. Unable to create blank texture! SDL Error: %s\n", SDL_GetError());
		return -1;
	}
	else
	{
		m_dim.w = width;
		m_dim.h = height;
	}

	bSet = true;

	return 0;
}
int Texture::load(string path, SDL_TextureAccess access)
{
	if(bSet == true)
	{
		printf("Texture error. Texture is already set.\n");
		return -1;
	}

	if(access == SDL_TEXTUREACCESS_STATIC)
		bLockable = false;

	GTS::WindowManager* WM = GTS::WindowManager::get();
	if(WM == NULL)
	{
		printf("Texture error. Could not open window manager.\n");
		return -1;
	}

	// set main window as default target
	m_window = WM->get_window(0);
	if(m_window == NULL)
	{
		printf("Texture error. Could not set default window.\n");
		return -1;
	}

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL)
	{
		printf("Could not load specific surface: %s\n Error: %s\n", path.c_str(), IMG_GetError());
		return -1;
	}
	else
	{
		m_texture = SDL_CreateTextureFromSurface(m_window->get_renderer(), loadedSurface);
		if(m_texture == NULL)
		{
			printf("Could not create texture: %s\n Error: %s\n", path.c_str(), SDL_GetError());
			return -1;
		}
		SDL_FreeSurface(loadedSurface);

		// set default texture dimensions
		SDL_QueryTexture(m_texture, NULL, NULL, &m_dim.w, &m_dim.h);
	}

	bSet = true;

	return 0;
}
int Texture::load(SDL_Surface* surface, SDL_Rect* fragment, SDL_TextureAccess access)
{
	if(bSet == true)
	{
		printf("Texture error. Texture is already set.\n");
		return -1;
	}

	if(access == SDL_TEXTUREACCESS_STATIC)
		bLockable = false;

	GTS::WindowManager* WM = GTS::WindowManager::get();
	if(WM == NULL)
	{
		printf("Texture error. Could not open window manager.\n");
		return -1;
	}

	// set main window as default target
	m_window = WM->get_window(0);
	if(m_window == NULL)
	{
		printf("Texture error. Could not set default window.\n");
		return -1;
	}

	if(surface == NULL)
	{
		printf("Texture error. Given surface is a null pointer.\n");
		return -1;
	}

	SDL_Rect clip = {0, 0, surface->w, surface->h};
	if(fragment != NULL)
	{
		clip = *fragment;
	}

	SDL_Surface* partSurface = NULL;

	#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	partSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, clip.w, clip.h, 32, 0xFF000000, 0x00FF0000, 0x0000FF00, 0x000000FF);
	#else
	partSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, clip.w, clip.h,32, 0x000000FF, 0x0000FF00, 0x00FF0000, 0xFF000000);
	#endif

	if(partSurface == NULL)
	{
		printf("Texture error. Could not create surface for texture.\n");
		return -1;
	}

	if(SDL_BlitSurface(surface, &clip, partSurface, NULL) != 0)
	{
		printf("Texture error. Surface blitting error: %s\n", SDL_GetError());
		return -1;
	}

	m_texture = SDL_CreateTextureFromSurface(m_window->get_renderer(), partSurface);
	if(m_texture == NULL)
	{
		printf("Texture error. Could not create texture from partSurface, error: %s\n", SDL_GetError());
		return -1;
	}

	SDL_FreeSurface(partSurface);

	SDL_QueryTexture(m_texture, NULL, NULL, &m_dim.w, &m_dim.h);

	bSet = true;

	return 0;
}
///



/// TEXTURE SETTINGS
void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(m_texture, blending);
}
int Texture::set_outputWindow(GTS::Window* window)
{
	if(window == NULL)
	{
		printf("Null was passed as argument in GTS::Texture::set_outputWindow function.\n");
		return -1;
	}
	m_window = window;

	return 0;
}
///



/// DIMENSIONS
void Texture::set_center(int x, int y)
{
	if(m_center != NULL)
	{
		delete m_center;
		m_center = NULL;
	}
	m_center = new SDL_Point;
	m_center->x = x;
	m_center->y = y;
}
GTS::Vec2D<int> Texture::get_dim()
{
	return m_dim;
}
///



/// RENDER
void Texture::setAsRenderTarget()
{
	SDL_SetRenderTarget(m_window->get_renderer(), m_texture );
}
int Texture::renderNormal(int x, int y, GTS::Vec4D<long>* border, GTS::TexTrans* trans)
{
	// scale texture
	GTS::Vec2D<double> windowScale = m_window->get_scale();

	SDL_Rect dstRect = {x, y, m_dim.w, m_dim.h};
			 dstRect.x *= windowScale.x;
			 dstRect.y *= windowScale.y;
			 dstRect.w *= windowScale.w;
			 dstRect.h *= windowScale.h;

	// check if texture is in active area(use dimensions without transformations)
	if(border != NULL)
	{
		if(dstRect.x >= border.x && dstRect.x < border.x + border.w
		&& dstRect.y >= border.y && dstRect.y < border.y + border.h)
		{
			return 0; // don't render anything
		}
	}

	if(trans != NULL)
	{
		if(trans->clip != NULL)
		{
			dstRect = *trans->clip;
		}
		GTS::Vec2D<double> tScale = trans->scale;
			// scale can't be less than 0
			if(tScale.x < 0)
				tScale.x = 0.0;
			if(tScale.y < 0)
				tScale.y = 0.0;

		GTS::Vec2D<int> scaleOffset(0, 0); // resizing texture cause position transformation(for scale > 1 => offset < 0, for scale < 1 => offset > 0)
			if(tScale.x < 1.0)
				scaleOffset.x = dstRect.w*(1.0 - tScale.x);
			else
				scaleOffset.x = (-1)*dstRect.w*(tScale.x - 1.0);

			if(tScale.y < 1.0)
				scaleOffset.y = dstRect.h*(1.0 - tScale.y);
			else
				scaleOffset.y = (-1)*dstRect.h*(tScale.y - 1.0);

		dstRect.x += scaleOffset.x/2;
		dstRect.y += scaleOffset.y/2;
		dstRect.w *= tScale.w;
		dstRect.h *= tScale.h;

		if(m_center != NULL)
		{
			dstRect.x += m_center->x;
			dstRect.y += m_center->y;
		}

		if(SDL_RenderCopyEx(m_window->get_renderer(), m_texture, trans->clip, &dstRect, trans->angle, m_center, trans->flip) != 0)
		{
			printf("SDL_Error(Ex): %s\n", SDL_GetError());
			return -1;
		}
	}
	else
	{
		if(SDL_RenderCopy(m_window->get_renderer(), m_texture, NULL, &dstRect) != 0)
		{
			printf("SDL_Error: %s\n", SDL_GetError());
			return -1;
		}
	}

	return 0;
}
int Texture::render(int x, int y, GTS::Vec4D<long>* border, GTS::TexTrans* trans, GTS::Texture* target)
{
	if(bSet == false)
	{
		printf("Could not render texture, because it is not set.\n");
		return -1;
	}
	if(m_window == NULL)
	{
		printf("Texture error. Texture has no target.\n");
		return -1;
	}

	if(target != NULL)
	{
		target->setAsRenderTarget();
	}

	if(renderNormal(x, y, trans) != 0)
	{
		printf("Could not render texture in normal mode.\n");
		return -1;
	}

	SDL_SetRenderTarget(m_window->get_renderer(), NULL);

	return 0;
}
///
