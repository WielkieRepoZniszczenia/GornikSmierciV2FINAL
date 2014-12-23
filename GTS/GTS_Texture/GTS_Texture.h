#ifndef GTS_TEXTURE_H
#define GTS_TEXTURE_H


#include <string>
#include <vector>

namespace GTS
{
	class TexTrans
	{
		public:
			TexTrans()
			{
				angle = 0.0;
				scale.x = 1.0;
				scale.y = 1.0;
				flip = SDL_FLIP_NONE;
				mod.r = 255;
				mod.g = 255;
				mod.b = 255;
				mod.a = 255;
				clip = NULL;
			}
			TexTrans(double _angle, GTS::Vec2D<double> _scale, GTS::Pixel32 _mod = GTS::Pixel32(), SDL_RendererFlip _flip = SDL_FLIP_NONE, SDL_Rect* _clip = NULL)
			{
				angle = _angle;
				scale = _scale;
				flip = _flip;
				mod = _mod;
				clip = _clip;
			}
			/// DATA
			double angle;
			GTS::Vec2D<double> scale;
			SDL_RendererFlip flip;
			SDL_Rect* clip;
			GTS::Pixel32 mod;

	};
}

namespace GTS
{
	typedef struct{
		SDL_Rect box;
		long gap;
	}TextureFrame;

	class Texture
	{
		public:
			Texture();
			~Texture();

			/** @@ CREATE TEXTURE @@
				@tex access:
					SDL_TEXTUREACCESS_STATIC
					SDL_TEXTUREACCESS_STREAMING
					SDL_TEXTUREACCESS_TARGET
				*/
				int createBlank(int width, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);
				int load(std::string path, SDL_TextureAccess access = SDL_TEXTUREACCESS_STATIC);
				int load(SDL_Surface* surface, SDL_Rect* box = NULL, SDL_TextureAccess access = SDL_TEXTUREACCESS_STATIC);

			/** @@ TEXTURE SETTINGS @@
				SDL_BLENDMODE_NONE   ->   dstRGBA = srcRGBA
				SDL_BLENDMODE_BLEND  ->   dstRGB = (srcRGB * srcA) + (dstRGB * (1-srcA))
										  dstA = srcA + (dstA * (1-srcA))
				SDL_BLENDMODE_ADD 	 ->   dstRGB = (srcRGB * srcA) + dstRGB
										  dstA = dstA
				SDL_BLENDMODE_MOD 	 ->   dstRGB = srcRGB * dstRGB
										  dstA = dstA

				*/
				void setBlendMode(SDL_BlendMode blending);
				int set_outputWindow(GTS::Window* window);


			/// DIMENSIONS
			void set_center(int x, int y);
			GTS::Vec2D<int> get_dim();


			/// USER RENDER
			virtual int render(int x, int y, GTS::Vec4D<long>* border = NULL, GTS::TexTrans* trans = NULL, GTS::Texture* target = NULL);


		private:
			void setAsRenderTarget();

			/// RENDER MODS
			int renderNormal(int x, int y, GTS::Vec4D<long>* border = NULL, GTS::TexTrans* transformation);

		protected:
			SDL_Texture* m_texture; //Hardware texture
			GTS::Vec2D<int> m_dim;
			SDL_Point* m_center;
			bool bSet; // it is set to true after first use of load method
			bool bLockable;

			/// OUTPUT WINDOW
			GTS::Window* m_window;

	};

	/// IMPLEMENTATION
	#include "GTS_Texture.cpp"
}

#endif // GTS_TEXTURE_H
