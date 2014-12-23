#ifndef GTS_WINDOW_H
#define GTS_WINDOW_H

#include <stdio.h>
#include <string>
#include <typedefs.cpp>


#include <SDL.h>

enum GTS_RESOLUTION
{
    RES_640x480 = 0,
    RES_800x600,
    RES_1024x768,
    //RES_1152x864,
    RES_1280x720,
    //RES_1280x800,
    //RES_1280x960,
    //RES_1360x768,
    RES_1600x900,
    //RES_1600x1024,
    //RES_1680x1050,
    RES_1920x1080

};

namespace GTS
{
	class Window
	{
		public:
			Window();
			~Window();

			int set(std::string title, int x, int y, unsigned int w = 1600, unsigned int h = 900); // window and renderer must be null to set them
			int resize(GTS_RESOLUTION resolution);
			int fullScreen(bool flag);

			// access
			SDL_Renderer* get_renderer();
			GTS::Vec2D<double> get_scale();
			SDL_Rect get_wdim();

			SDL_Rect align(SDL_Rect& rect);
			int apply_surface(int x, int y, SDL_Surface* source, SDL_Rect* clip = NULL);

			int clear(Pixel32* color = NULL);
			void update();

		private:
			std::string mTitle;
			GTS::Vec2D<unsigned int> mWDefDim;
			SDL_Rect mWDim;
			GTS_RESOLUTION mRes; // must be in the range of resolution
			GTS::Vec2D<double> mScale;

			SDL_Window* mWindow;
			SDL_Renderer* mRenderer;
			Pixel32 mDefColor;
	};

	#include "GTS_Window.cpp"
}

#endif // GTS_WINDOW_H
