
const long Camera::sGap = 40; // miliseconds

Camera::Camera()
{
    mEdge = 40;
    mProjection.x = 0;
    mProjection.y = 0;
	mProjection.w = 0;
	mProjection.h = 0;

    mLastTime = 0;
}

void Camera::set_projection(GTS::Vec4D<long> &newProjection)
{
    mProjection = newProjection;
}
void Camera::set_projection(long x, long y)
{
	mProjection.x = x;
	mProjection.y = y;
}

GTS::Vec4D<long> Camera::get_projection()
{
    return mProjection;
}


void Camera::update(GTS::Window* windows, GTS::Vec2D<unsigned int> sectorsCount, GTS::Vec2D<unsigned int> tilesPerSector, GTS::Vec2D<unsigned int> tileSize)
{
    long currentTime = GTS::Engine::get_time();

    if(currentTime - mLastTime > sGap)
    {
        /// przewijanie ekranu
        int x = 0;
        int y = 0;

        SDL_GetRelativeMouseState(&x, &y);

        ///---- current window box ----///
            SDL_Rect box = windows->get_wdim();


        ///---- granice mapy ----///
            GTS::Vec2D<long> border;
            				 border.w = sectorsCount.x*tilesPerSector.x*tileSize.w;
							 border.h = sectorsCount.y*tilesPerSector.y*tileSize.h;


		/// prawa krawedz
		{
			if(x > box.x + box.w - mEdge && x < box.x + box.w
			&& y > box.y && y < box.y + box.h)
			{
				if(mProjection.x < border.w - mProjection.w)
				{
					mProjection.x += mEdge/2;
				}
				else
				{
					mProjection.x = border.w - mProjection.w;
				}
			}
		}
		/// lewa krawedz
		{
			if(x < box.x + mEdge && x >= box.x
			&& y > box.y && y < box.y + box.h)
			{
				if(mProjection.x > 0)
				{
					mProjection.x -= mEdge/2;
				}
				else
				{
					mProjection.x = 0;
				}
			}
		}
		/// gorna krawedz
		{
			if(y < box.y + mEdge && y >= box.y
			&& x > box.x && x < box.x + box.w)
			{
				if(mProjection.y > 0)
				{
					mProjection.y -= mEdge/2;
				}
				else
				{
					mProjection.x = 0;
				}
			}
		}
		/// dolna krawedz
		{
			if(y > box.y + box.h - mEdge && y < box.y + box.h
			&& x > box.x && x < box.x + box.w)
			{
				if(mProjection.y < border.h - mProjection.h)
				{
					mProjection.y += mEdge/2;
				}
				else
				{
					mProjection.x = border.h - mProjection.h;
				}
			}
		}
    }
}


GTS::Vec2D<int> Camera::filter_position(GTS::Vec2D<long> position)
{
    GTS::Vec2D<int> coordinates;
    				coordinates.x = (int)(position.x - mProjection.x);
    				coordinates.y = (int)(position.y - mProjection.y);

    return coordinates;
}

bool Camera::check_collision(GTS::Vec4D<long>& A, GTS::Vec4D<long>& B)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

    if( bottomA <= topB )
    {
        return false;
    }

    else if( topA >= bottomB )
    {
        return false;
    }

    else if( rightA <= leftB )
    {
        return false;
    }

    else if( leftA >= rightB )
    {
        return false;
    }
    return true;
}

bool Camera::check_collision(int x, int y, GTS::Vec4D<long>& A)
{
    if(x >= A.x && x < A.x + A.w
    && y >= A.y && y < A.y + A.h)
        return true;

    return false;
}


bool Camera::check_collision(GTS::Vec4D<long>& box)
{
    return check_collision(box, mProjection);
}
