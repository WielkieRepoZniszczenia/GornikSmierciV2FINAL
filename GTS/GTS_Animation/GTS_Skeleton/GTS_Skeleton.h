#ifndef GTS_SKELETON_H
#define GTS_SKELETON_H

#include <vector>

namespace GTS
{
	class Skeleton
	{
		public:
			Skeleton();
			~Skeleton();

			/** add bone
				* first added => first rendered
				*/
				void add_bone(GTS::Bone& bone);
				GTS::Bone* get_bone(unsigned int id);
				unsigned int bonesCount();


			/** Render
				* bones are rendered in list order
				*/
				int render(int x, int y);


			int save(std::ofstream& fout);
			int load(std::ifstream& fin);

		protected:
		private:
			std::vector<GTS::Bone> mBones_;

	};

	#include "GTS_Skeleton.cpp"
}

#endif // GTS_SKELETON_H
