#ifndef GTS_RESOURCE_MANAGER_H
#define GTS_RESOURCE_MANAGER_H


#include <list>

#include "GTS_Resource/GTS_Resource.h"


namespace GTS
{
	/// @@@ SINGLETON @@@
	class ResourceManager
	{
		public:
			static int create();
			static ResourceManager* get();
			static void destroy();

			~ResourceManager();

			/** @@ SET @@
				* use like this: resourceManager->initialize<Resource0>();
				* returns -1 on error
				*/
				template<class resourceType>
				int set();

			/** @@ DETACH @@
				* it erases given resource from the list
				*/
				void detach(GTS::Resource* resource);

			/** @@ CLEAR @@
				* destroys all resources in the list
				*/
				void clear();

		private:
			ResourceManager();
			static ResourceManager* sm_resourceManager;

			std::list<GTS::Resource*> m_res_;
	};

	#include "GTS_ResourceManager.cpp"
}

#endif // GTS_RESOURCEMANAGER_H
