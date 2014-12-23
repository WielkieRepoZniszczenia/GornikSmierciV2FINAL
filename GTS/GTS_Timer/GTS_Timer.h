#ifndef GTS_TIMER_H
#define GTS_TIMER_H

namespace GTS
{
	class Timer
	{
		public:
			Timer();

			void start();
			void stop();
			void pause();
			void unpause();

			long get_ticks();

			bool is_started();
			bool is_paused();

		private:
			long startTicks;
			long pausedTicks;
			bool paused;
			bool started;
	};

	#include "GTS_Timer.cpp"
}

#endif
