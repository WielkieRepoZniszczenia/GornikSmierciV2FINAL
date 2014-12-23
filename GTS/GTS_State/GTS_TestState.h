#ifndef GTS_TESTSTATE_H
#define GTS_TESTSTATE_H

#include "GTS_State/GTS_State.h"

namespace GTS
{
	class TestState : public GTS::State
	{
		public:
			TestState();
			~TestState();

			int set();
			int events(SDL_Event &event);
			int logic();
			int sounds();
			int render();
			int clear();

		private:
			GTS::TestButtons* mTestButtons;
			GTS::TestResource* mTestResources;

			GTS::Texture tx1;
			GTS::Texture tx2;

			GTS::Pawn pawn1;
			GTS::Pawn pawn2;
			GTS::Pawn pawn3;
			GTS::Vec2D<int> testPosition;
			bool reverse;
			double testAngle;
			long testTime;

			int FPS;
	};

	#include "GTS_TestState.cpp"
}

#endif // GTS_TESTSTATE_H
