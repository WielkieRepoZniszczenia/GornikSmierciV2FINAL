#ifndef GTS_ANIMATION_H
#define GTS_ANIMATION_H

#include <list>
#include <fstream>

#include "GTS_Bone/GTS_Bone.h"
#include "GTS_Skeleton/GTS_Skeleton.h"
#include "GTS_Frame/GTS_Frame.h"

#include "GTS_Texture/GTS_Texture.h"
#include "GTS_Skin/GTS_Skin.h"


namespace GTS
{
	class Animation
	{
		public:
			Animation();
			~Animation();

			int add_frame(GTS::Skeleton& skeleton, long timeGap);

			void set_loop(bool loop);
			bool get_loop();

			GTS::Skeleton* get_momentary_skeleton(long time_offset);

			int bonesCount();

			int save(std::ofstream& fout);
			int load(std::ifstream& fin);

		protected:
			int transform_bone(GTS::Bone& boneToTransform, int newSkinID = -1, double angle = 0.0,
							   GTS::Vec2D<double>* scale = NULL, GTS::Vec2D<int>* position = NULL); // relative to old data

		private:
			std::list<GTS::Frame> _mFrames_;
			bool bLoop;

	};

	#include "GTS_Animation.cpp"
}

#endif // GTS_ANIMATION_H
