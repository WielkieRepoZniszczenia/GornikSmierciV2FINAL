#ifndef TYPEDEFS_T
#define TYPEDEFS_T


typedef struct{ /// @@@ COLL_area @@@

    int x, y, w, h;
    int e;
} COLL_area;

/*
typedef struct
{
    //center
    char c;
    // up, down, left, right
    char u, d, l, r;
    //up-left, up-right, down-left, down-right
    char ul, ur, dl, dr;
} SDL_Chain;
*/

typedef struct{ /// @@@ Arrow_Vector @@@

    /**
        d - destination
        s - source

        flagi kierunku:

        1 2 3
        4 0 5
        6 7 8

        gdzie 0 oznacza brak celu/zrodla
    */
    char d, s;
} Arrow_Vector;


namespace GTS
{
	typedef struct{ /// @@@ long_Rect @@@
		long x, y;
		long w, h;
	} Long_Rect;

/*	typedef struct{ /// @@@ Pixel32 @@@
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
	}Pixel32; */
}


#endif
