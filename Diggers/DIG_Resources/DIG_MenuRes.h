#ifndef DIG_MENURES_H
#define DIG_MENURES_H

#include "GTS_Resource/GTS_Resource.h"

namespace DIG
{
	class MenuRes : public GTS::Resource
	{
		public:
			~MenuRes();

			static int create();
			static MenuRes* get();
			static void destroy();


			GTS::Texture* get_texture(int index);

			int set();

			void free();

		protected:
		private:
			MenuRes();
			static MenuRes* sm_menuRes;

	};

	#include "DIG_MenuRes.cpp"
}

#endif // DIG_MENURES_H
