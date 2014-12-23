#ifndef GTS_SQTILE_H
#define GTS_SQTILE_H

#include "GTS_Tile/GTS_Tile.h"

namespace GTS
{
	class SQTile : public GTS::Tile
	{
		public:
			SQTile();
			virtual ~SQTile();

			virtual void set_tileDim(unsigned int w, unsigned int h) = 0;
			virtual GTS::Vec2D<unsigned int> get_tileDim() = 0;

			void set_flags(char* a, char* b, char* c, char* d);
			const char* get_flags();

			void set_variant(char v);

			virtual int renderBG();
			virtual int renderFG();

		protected:
			static void set_tileDimS(unsigned int w, unsigned int h);
			static GTS::Vec2D<unsigned int> get_tileDimS();

		private:
			static GTS::Vec2D<unsigned int> sm_tileDim;
			static bool bSet;

			char m_tFlags[4]; // terrain type matrix
			char m_variant; // variants of the same terrain type
	};

	#include "GTS_SQTile.cpp"
}
#endif // GTS_SQTILE_H
