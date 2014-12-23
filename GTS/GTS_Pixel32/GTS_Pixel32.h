#ifndef GTS_PIXEL32_H
#define GTS_PIXEL32_H

namespace GTS
{
	class Pixel32
	{
		public:
			Pixel32()
			{
				r = 255;
				g = 255;
				b = 255;
				a = 255;
			}
			Pixel32(Uint8 _r, Uint8 _g, Uint8 _b, Uint8 _a)
			{
				r = _r;
				g = _g;
				b = _b;
				a = _a;
			}

			union
			{
				struct
				{
					#if LittleEndian_
					Uint8 a, r, g, b;

					#else
					Uint8 b, g, r, a;


					#endif
				};
				Uint32 u;
			};

		protected:
		private:
	};
}

#endif // GTS_PIXEL32_H
