#ifndef GTS_TESTRESOURCE_H
#define GTS_TESTRESOURCE_H

#include "GTS_Resource/GTS_Resource.h"

TTF_Font *gFont = NULL;

namespace GTS
{
	/// @@@ SINGLETON @@@
	class TestResource : public GTS::Resource
	{
		public:
			static int create();
			static TestResource* get();
			void destroy();

			~TestResource();

			enum TEST_IDS{
				TEST_TXE = 0,
				TEST_LAST
			};
			GTS::Texture* get(TEST_IDS index);

			int set();


			void free();

		protected:

		private:
			TestResource();
			static TestResource* sm_TestResource;

			/// textures
			GTS::Texture testTXE;
	};

	#include "GTS_TestResource.cpp"
}

#endif // GTS_TESTRESOURCE_H
