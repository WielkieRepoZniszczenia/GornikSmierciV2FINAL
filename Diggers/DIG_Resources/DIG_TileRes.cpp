TileRes* TileRes::sm_tileoRes = NULL;


/// CTOR / DTOR
TileRes::TileRes()
{
	//ctor
}
TileRes::~TileRes()
{
	//dtor
}
///



/// SINGLETON METHODS
int TileRes::create()
{
	if(sm_tileoRes == NULL)
	{
		if(sm_tileoRes == NULL)
		{
			sm_tileoRes = new TileRes;

			return 0;
		}
	}


	printf("Intro resources already exist.\n");

	return -1;
}
TileRes* TileRes::get()
{
	return sm_tileoRes;
}
void TileRes::destroy()
{
	if(sm_tileoRes != NULL)
	{
		delete sm_tileoRes;
		sm_tileoRes = NULL;
	}
}
///



/// SET
int TileRes::set()
{
	GTS::WindowManager* WM = GTS::WindowManager::get();
	if(WM == NULL)
		return -1;

	GTS::Window* window = WM->get_window(0);
	if(window == NULL)
		return -1;


	/// TEXTURE FUSER
	if(m_txFuser.createBlank(80, 80, SDL_TEXTUREACCESS_STREAMING) != 0) // values w and h are tile dimensions
	{
		printf("TileRes error. Could not create blank texture for txFuser.\n");
		return -1;
	}
	m_txFuser.setBlendMode(SDL_BLENDMODE_BLEND);
	///

	/// CAVE / TUNNEL MASK
	if(m_cave_tunnel_mask.load("Textures/CTmask.png") != 0)
	{
		printf("TileRes error. Could not load: Textures/CTmtx.png\n");
		return -1;
	}
	m_cave_tunnel_mask.setBlendMode(SDL_BLENDMODE_BLEND);
	///

	/// TERRAIN
	if(m_terrain[DIG_HARD_ROCK].load("Textures/hardRock.png") != 0)
	{
		printf("TileRes error. Could not load: Textures/hardRock.png\n");
		return -1;
	}
	m_terrain[DIG_HARD_ROCK].setBlendMode(SDL_BLENDMODE_ADD);
		if(m_terrain[DIG_SOIL_01].load("Textures/soil01.png") != 0)
		{
			printf("TileRes error. Could not load: Textures/soil01.png\n");
			return -1;
		}
		m_terrain[DIG_SOIL_01].setBlendMode(SDL_BLENDMODE_ADD);
	if(m_terrain[DIG_SOIL_DARK_01].load("Textures/soil01dark.png") != 0)
	{
		printf("TileRes error. Could not load: Textures/soil01dark.png\n");
		return -1;
	}
	m_terrain[DIG_SOIL_DARK_01].setBlendMode(SDL_BLENDMODE_ADD);
	///

	return 0;
}
///


/// FREE
void TileRes::free()
{
	GTS::ResourceManager* rm = GTS::ResourceManager::get();// <-
	rm->detach(sm_tileoRes); 							   // <- you have to do this part with all resources

	destroy();
}
///



/// GET TEXTURE
GTS::Texture* TileRes::get_txFuser()
{
	return &m_txFuser;
}
GTS::Texture* TileRes::get_CTmask()
{
	return &m_cave_tunnel_mask;
}
GTS::Texture* TileRes::get_texture(int index)
{
	if(index >= 0 && index < DIG_TERRAIN_LAST)
	{
		return &m_terrain[index];
	}

	return NULL;
}
///
