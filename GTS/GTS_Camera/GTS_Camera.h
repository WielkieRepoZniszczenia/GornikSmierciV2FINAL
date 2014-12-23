#ifndef PTG_CAMERA_H
#define PTG_CAMERA_H

namespace GTS
{
	class Camera
	{
		public:
			Camera();

			/** @@ ODSWIERZANIE KAMERY @@
				* odswierza polozenie kamery i jej projekcji
				*/
				void update(GTS::Window* windows, GTS::Vec2D<unsigned int> sectorsCount, GTS::Vec2D<unsigned int> tilesPerSector, GTS::Vec2D<unsigned int> tileSize);

			/** @@ ZMIANA POLOZENIA PROJEKCJI @@
				*/
				void set_projection(GTS::Vec4D<long> &newProjection);
				void set_projection(long x, long y);

			/** @@ PROJEKCJA @@
				*/
				GTS::Vec4D<long> get_projection();

			/** FILTER POSITION
				* it subtract camera projection from object position
					which gives position on the screen
				*/
				GTS::Vec2D<int> filter_position(GTS::Vec2D<long> position);

			/** TEXTURE COLLISION DETECTION
				* it check whether or not texture is visible on the screen
				*/
				bool check_collision(GTS::Vec4D<long>& A, GTS::Vec4D<long>& B);
				bool check_collision(int x, int y, GTS::Vec4D<long>& A);

				bool check_collision(GTS::Vec4D<long>& box);

		private:

			GTS::Vec4D<long> mProjection;

			/** CAMERA MOVEMENT
				* mEdge - distance from the screen edge, between which user can move camera projection
				*/
				int mEdge;
				long mLastTime;

				static const long sGap;

	};

	#include "GTS_Camera.cpp"
}

#endif
