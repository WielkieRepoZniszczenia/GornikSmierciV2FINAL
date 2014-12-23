#ifndef GTS_HUMAN_H
#define GTS_HUMAN_H

#include <GTS_Player/GTS_Player.cpp>

namespace GTS
{
	class Human : public Player
	{
		public:
			Human();
			virtual ~Human();

			virtual int poll_events(SDL_Event &event);
			virtual int state_events(SDL_Event &event);
			virtual int logic();

		protected:
		private:
	};

	#include "GTS_Human.h"
}

#endif // GTS_HUMAN_H
