#ifndef DIG_INITRES_H
#define DIG_INITRES_H

#include "GTS_Resource/GTS_Resource.h"

namespace DIG
{
	/// SINGLETON
	class InitRes : public GTS::Resource
	{
		public:
			~InitRes();

			static int create();
			static InitRes* get();
			static void destroy();


			GTS::Texture* get_texture(int index);

			int set();

			void free();

		protected:
		private:
			InitRes();
			static InitRes* sm_initRes;

			GTS::Texture m_initTex;
	};

	#include "DIG_InitRes.cpp"
}

#endif // DIG_INITRES_H
