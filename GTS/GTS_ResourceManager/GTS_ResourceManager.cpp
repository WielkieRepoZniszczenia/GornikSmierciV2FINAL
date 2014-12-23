
ResourceManager* ResourceManager::sm_resourceManager = NULL;

/// SINGLETON METHODS
int ResourceManager::create()
{
	if(sm_resourceManager != NULL)
	{
		if(sm_resourceManager != NULL)
		{
			printf("You can not create multiple instances of GTS::ResourceManager.\n");
			return -1;
		}
	}

	sm_resourceManager = new ResourceManager;
	return 0;
}
ResourceManager* ResourceManager::get()
{
	return sm_resourceManager;
}
void ResourceManager::destroy()
{
	if(sm_resourceManager != NULL)
	{
		delete sm_resourceManager;
		sm_resourceManager = NULL;
	}
}
///



/// CTOR / DTOR
ResourceManager::ResourceManager()
{
	//ctor
}
ResourceManager::~ResourceManager()
{
	clear();
}
///



/// SET
template<class resourceType>
int ResourceManager::set()
{
	resourceType* pResource = resourceType::get();
	if(pResource != NULL)
	{
		//no need to create another instance of this resource
		return 0;
	}
	resourceType::create();
	pResource = resourceType::get();
	if(pResource == NULL)
	{
		printf("Resource Manager error. Could not add new resource to a list.\n");
		return -1;
	}

	if(pResource->set() != 0)
	{
		printf("Resource Manager error. Could not set given resource.\n");
		return -1;
	}

	m_res_.push_back(pResource);

	return 0;
}
///



/// UPDATE
void ResourceManager::detach(GTS::Resource* resource)
{
	list<GTS::Resource*>::iterator iLoc;
	for(iLoc = m_res_.begin(); iLoc != m_res_.end(); ++iLoc)
	{
		if(*iLoc == resource)
		{
			m_res_.erase(iLoc);
			break;
		}
	}
}
///



/// CLEAR
void ResourceManager::clear()
{

	list<GTS::Resource*>::iterator iLoc;
	unsigned int size = m_res_.size();
	while(size != 0)
	{
		iLoc = m_res_.begin();
		if(*iLoc != NULL)
			(*iLoc)->free();

		size = m_res_.size();
	}
}
///
