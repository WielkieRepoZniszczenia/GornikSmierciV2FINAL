#ifndef GTS_SKIN_H
#define GTS_SKIN_H

#include <vector>

namespace GTS
{
	class Skin
	{
		public:
			Skin();
			virtual ~Skin();

			void add_texture(GTS::Texture* texture);
			GTS::Texture* get_texture(unsigned int id);
			int replace(GTS::Texture* texture, unsigned int id);
			unsigned int size();

			int render(int x, int y, GTS::Skeleton* skeleton);

		protected:

		private:
			std::vector<GTS::Texture*> mTextures_;
	};
	#include "GTS_Skin.cpp"
}
#endif // GTS_SKIN_H
