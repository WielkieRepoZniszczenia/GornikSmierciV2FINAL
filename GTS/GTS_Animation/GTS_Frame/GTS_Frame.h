#ifndef GTS_FRAME_H
#define GTS_FRAME_H

#include <fstream>

namespace GTS
{
	class Frame
	{
		public:
			Frame();
			~Frame();

			void set_skeleton(GTS::Skeleton& skeleton);
			void set_timeGap(long timeGap);

			GTS::Skeleton* get_skeleton();
			long get_timeGap();

			int bonesCount();

			int save(std::ofstream& fout);
			int load(std::ifstream& fin);

		protected:

		private:
			GTS::Skeleton mSkeleton;
			long mTimeGap;
	};

	#include "GTS_Frame.cpp"
}

#endif // GTS_FRAME_H
