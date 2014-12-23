#ifndef GTS_TEXT_H
#define GTS_TEXT_H

#include <SDL_ttf.h>
#include <string>

namespace GTS
{
	class Text
	{
		public:
			Text();
			virtual ~Text();

			int set(std::string str, TTF_Font* font, SDL_Color color, GTS::Window* window = NULL);

			void free();

			int render(int x, int y, GTS::TexTrans* trans = NULL); // transformations

		protected:


		private:
			SDL_Texture* mTexture;
			std::string mRecentStr;
			SDL_Renderer* m_renderer;

			GTS::Vec2D<unsigned int> mDim;
	};

	#include "GTS_Text.cpp"
}

#endif // GTS_TEXT_H
