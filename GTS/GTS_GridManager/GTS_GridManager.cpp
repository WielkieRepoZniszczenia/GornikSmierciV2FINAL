GridManager* GridManager::sGridManager = NULL;

GridManager::GridManager()
{
	mTilesPerSector.x = 0;
	mTilesPerSector.y = 0;

	mSectorsPerMap.x = 0;
	mSectorsPerMap.y = 0;

	bUnderground = false;

	mCurrentSector.x = 0;
	mCurrentSector.y = 0;
}

GridManager::~GridManager()
{
	//dtor
}


int GridManager::create()
{
	if(sGridManager != NULL)
	{
		printf("You can't create multiple instances of GTS::GridManager.\n");
		return -1;
	}
	sGridManager = new GridManager;

	return 0;
}
GridManager* GridManager::get()
{
	return sGridManager;
}
void GridManager::destroy()
{
	if(sGridManager != NULL)
	{
		delete sGridManager;
		sGridManager = NULL;
	}
}


template<class tile_Type>
int GridManager::set_grid(unsigned int sectors_in_row, unsigned int sectors_in_column,
						  unsigned int tiles_in_row, unsigned int tiles_in_column, bool underground,
						  GTS::Location defLocation)
{
	/// free tile memory
	for(unsigned int n = 0; n < mTiles_.size(); ++n)
		delete mTiles_.at(n);

	mTiles_.erase(mTiles_.begin(), mTiles_.end());

	/// free location memory
	mSurfaceLocations_.erase(mSurfaceLocations_.begin(), mSurfaceLocations_.end());
	mUndergroundLocations_.erase(mUndergroundLocations_.begin(), mUndergroundLocations_.end());

	/// set new data
	mSectorsPerMap.x = sectors_in_row;
	mSectorsPerMap.y = sectors_in_column;

	mTilesPerSector.x = tiles_in_row;
	mTilesPerSector.y = tiles_in_column;

	bUnderground = underground;

	mSurfaceLocations_.resize(mSectorsPerMap.x*mSectorsPerMap.y*mTilesPerSector.x*mTilesPerSector.y, defLocation);
	if(bUnderground == true)
		mUndergroundLocations_.resize(mSectorsPerMap.x*mSectorsPerMap.y*mTilesPerSector.x*mTilesPerSector.y, defLocation);

	mTiles_.resize(mTilesPerSector.x*mTilesPerSector.y*9, NULL);
	for(unsigned int n = 0; n < mTiles_.size(); ++n)
	{
		mTiles_.at(n) = new tile_Type;
	}

	return 0;
}

GTS::Vec2D<unsigned int> GridManager::get_TPS()
{
	return mTilesPerSector;
}
GTS::Vec2D<unsigned int> GridManager::get_SPM()
{
	return mSectorsPerMap;
}
GTS::Vec2D<unsigned int> GridManager::get_TOB()
{
	GTS::Vec2D<unsigned int> tempSize;

	tempSize.x = 3*mTilesPerSector.x;
	tempSize.y = 3*mTilesPerSector.y;

	return tempSize;
}



GTS::Tile* GridManager::get_tile(unsigned int xLocation, unsigned int yLocation)
{
	GTS::Vec2D<unsigned int> max;
							 max.x = mSectorsPerMap.x*mTilesPerSector.x;
							 max.y = mSectorsPerMap.y*mTilesPerSector.y;

	if(xLocation > max.x || yLocation > max.y)
		return NULL; // this is not an error, it is useful for tile grid editing

	GTS::Vec2D<unsigned int> offset;
							 offset.x = mCurrentSector.x*mTilesPerSector.x;
							 offset.y = mCurrentSector.y*mTilesPerSector.y;

	unsigned int tileIndex = (yLocation - offset.y)*mTilesPerSector.x*3 + xLocation - offset.x;

	if(tileIndex < 0 || tileIndex >= mTiles_.size()) // this is error, it should be in tile vector range
	{
		printf("Wrong tile index in GridManager::get_tile().\n");
		return NULL;
	}

	return mTiles_.at(tileIndex);
}
