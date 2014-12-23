#ifndef GTS_RESOURCE_H
#define GTS_RESOURCE_H


#include <string>


/** @@@ INFO @@@
	* all inherited classes should be singletons !!!

	* you can't create inherited class object with GTS_Resource pointer,
	  it must be created with pointer of its own type, by Resource Manager (RM clears all data on exit)

	* be extremely careful when you inherit this class and use it outside the engine,
	  you must be sure you destroy unwanted object by destroy() method

	*/
namespace GTS
{
	class Resource
	{
		public:
			Resource();
			virtual ~Resource();

			/** Singleton type method block(should be in derived class)

				* create() // create instance (if currently pointer is set to NULL)
				* get() // returns pointer to static object
				* destroy() // destroy instance (pointer must be set to NULL!!)

			*/

			/** @@ SET @@
				*/
				virtual int set() = 0;

			/** @@ FREE @@
				* this function should call individual destroy() method in each derived
				  class and @inform resource manager that it is destroyed(*observer schematics*)

				  e.g:

				  	GTS::ResourceManager* rm = GTS::ResourceManager::get();
				  	rm->detach(sm_thisResource); // this informs that this resource will be destroyed and should not be on the rm list anymore
				*/
				virtual void free() = 0;


		protected:

		private:

			/// there should be static pointer to resource object (it must be initialized as NULL)

			std::string m_name; // it may be useful for debugging
	};

	#include "GTS_Resource.cpp"
}

#endif // GTS_RESOURCE_H
