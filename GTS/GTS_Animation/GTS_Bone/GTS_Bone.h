#ifndef GTS_BONE_H
#define GTS_BONE_H

#include <fstream>

namespace GTS
{
	class BoneSwapData
	{
		public:
			BoneSwapData();
			~BoneSwapData();
		protected:
		private:
	};

	class Bone
	{
		public:
			Bone();
			~Bone();

			void set_position(int x, int y);
			void set_skale(double sx, double sy);
			void set_angle(double angle);
			void set_center(int x, int y);
			void set_flip(SDL_RendererFlip flip);
			void set_textureID(int id);
			void set_parentID(int id);

			GTS::Vec2D<int> get_position();
			GTS::Vec2D<double> get_skale();
			double get_angle();
			GTS::Vec2D<int> get_center();
			SDL_RendererFlip get_flip();
			int get_textureID();
			int get_parentID();

			int save(std::ofstream& fout);
			int load(std::ifstream& fin);

		protected:
		private:
			GTS::Vec2D<int> mPosition;
			GTS::Vec2D<double> mScale;
			double mAngle;
			GTS::Vec2D<int> mCenter;
			SDL_RendererFlip mFlip; // if flip != none all bone data have to be properly transformed
			int mTextureID;
			int mParentID;
	};

	#include "GTS_Bone.cpp"
}
/* SPRAWDZIC CZEMU NIE DZIALA
namespace GTS
{
	SDL_Point operator=(GTS::Vec2D<int>& vec2d)
	{
		SDL_Point point;
		point.x = vec2d.x;
		point.y = vec2d.y;

		return point;
	}
}
*/
#endif // GTS_BONE_H
