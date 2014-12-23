#ifndef GTS_TESTBUTTONS_H
#define GTS_TESTBUTTONS_H

#include "GTS_Resource/GTS_Resource.h"


namespace GTS
{
	/// @@@ SINGLETON @@@
	class TestButtons : public GTS::Resource
	{
		public:
			static int create();
			static TestButtons* get();
			void destroy();

			~TestButtons();


			int set();


			void free();


			enum TEST_BUTTONS{
				BUTTON_0 = 0,
				BUTTON_LAST
			};
			GTS::Button* get(TEST_BUTTONS index);

		protected:

		private:
			TestButtons();
			static TestButtons* sm_TestButtons;

			/// textures
			GTS::Texture unpressed;
			GTS::Texture pressed;
			GTS::Texture highlighted;

			GTS::Button button;
	};

	#include "GTS_TestButtons.cpp"
}

#endif // GTS_TESTBUTTONS_H
