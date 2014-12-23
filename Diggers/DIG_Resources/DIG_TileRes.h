#ifndef DIG_TILERES_H
#define DIG_TILERES_H

#include "GTS_Resource/GTS_Resource.h"


namespace DIG
{
	class TileRes : public GTS::Resource
	{
		public:
			enum DIG_TERRAIN
			{
				DIG_HARD_ROCK = 0,
				DIG_SOIL_01,
				DIG_SOIL_DARK_01,

				DIG_TERRAIN_LAST
			};
			~TileRes();

			static int create();
			static TileRes* get();
			static void destroy();


			GTS::Texture* get_txFuser();
			GTS::Texture* get_CTmask();
			GTS::Texture* get_texture(int index);

			int set();

			void free();

		protected:
		private:
			TileRes();
			static TileRes* sm_tileoRes;

			GTS::Texture m_txFuser; // texture that will fuse terrain texture and mask
			GTS::Texture m_cave_tunnel_mask;
			GTS::Texture m_terrain[DIG_TERRAIN_LAST];
	};

	#include "DIG_TileRes.cpp"
}

#endif // DIG_TILERES_H
