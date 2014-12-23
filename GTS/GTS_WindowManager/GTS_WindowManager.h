#ifndef GTS_WINDOWMANAGER_H
#define GTS_WINDOWMANAGER_H

#include <string>
#include <map>
#include "GTS_Window/GTS_Window.h"

namespace GTS
{
	/// @@ SINGLETON @@
	class WindowManager
	{
		public:
			~WindowManager();

			/// SINGLETON METHODS
			static int create();
			static WindowManager* get();
			static void destroy();
			///


			int create_window(int windowID, std::string title, int x, int y, unsigned int w, unsigned int h);
			GTS::Window* get_window(int windowID);


		protected:
		private:
			WindowManager();
			static WindowManager* sm_windowManager;

			std::map<int, GTS::Window> m_windows;
	};

	#include "GTS_WindowManager.cpp"
}

#endif // GTS_WINDOWMANAGER_H
