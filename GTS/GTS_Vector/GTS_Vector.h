#ifndef GTS_VECTOR_H
#define GTS_ACTION_H

#include <stdio.h>
#include <cmath>

namespace GTS
{
	/// ----- VEC2D ----- ///

	template<typename T>
	class Vec2D
	{
		public:
			Vec2D()
			{
				x = 0;
				y = 0;
			}
			Vec2D(T _X, T _Y)
			{
				x = _X;
				y = _Y;
			}
			~Vec2D()
			{
				//dtor
			}
			bool operator==(const Vec2D& rhs)
			{
				if(this->x == rhs.x && this->y == rhs.y)
					return true;

				return false;
			}
			bool operator!=(const Vec2D& rhs)
			{
				if(this->x != rhs.x || this->y != rhs.y)
					return true;

				return false;
			}
			Vec2D operator+(const Vec2D& rhs)
			{
				Vec2D<T> n;
				n.x = this->x + rhs.x;
				n.y = this->y + rhs.y;

				return n;
			}
			Vec2D& operator+=(const Vec2D& rhs)
			{
				x += rhs.x;
				y += rhs.y;

				return *this;
			}
			Vec2D& operator-=(const Vec2D& rhs)
			{
				x -= rhs.x;
				y -= rhs.y;

				return *this;
			}
			Vec2D& operator*=(const Vec2D& rhs)
			{
				x *= rhs.x;
				y *= rhs.y;

				return *this;
			}
			Vec2D& operator/=(const Vec2D& rhs)
			{
				if(rhs.x != 0)
					x /= rhs.x;

				if(rhs.y != 0)
					y /= rhs.y;

				return *this;
			}
			Vec2D& operator=(const Vec2D& rhs)
			{
				x = rhs.x;
				y = rhs.y;

				return *this;
			}
			Vec2D operator-(const Vec2D& rhs)
			{
				Vec2D<T> n;
				n.x = this->x - rhs.x;
				n.y = this->y - rhs.y;

				return n;
			}
			Vec2D operator*(const double& rhs)
			{
				Vec2D<T> n;
				n.x = this->x*rhs;
				n.y = this->y*rhs;

				return n;
			}

			union
			{
				struct
				{
					T x;
					T y;
				};

				struct
				{
					T w;
					T h;
				};
			};

			static const Vec2D<T> ZERO;

			static const double PI;

			double get_angleRAD()
			{
				// handle division by zero
				if(x == 0 && y == 0)
				{
					return 0;
				}
				else if(x == 0)
				{
					if(y > 0)
						return PI/2;
					else if(y < 0)
						return 3*PI/2;
				}
				else if(y == 0)
				{
					if(x > 0)
						return 0;
					else //(x < 0)
						return PI;
				}
				//

				double dx = x;
				double dy = y;
				return atan((double)(dy/dx));
			}
			double get_angleDEG()
			{
				double angle = get_angleRAD();
				return (double)(360*angle/(2*PI)); //convert to degrees
			}

			void rotDEG(double dA)
			{
				double r = sqrt(pow(x, 2) + pow(y, 2));
				double angle = (double)(2*PI)*(double)(dA/360) + get_angleRAD();

				double nx = (double)r*cos(angle);
				double ny = (double)r*sin(angle);

				x = nx;
				if(nx - x > 0.5)
					x+=1;

				y = ny;
				if(ny - y > 0.5)
					y+=1;

			}
			void rotRAD(double dA)
			{
				double r = sqrt(pow(x, 2) + pow(y, 2));
				double angle = dA + get_angleRAD();

				x = r*cos(angle);
				y = r*sin(angle); // in SDL, Y axis is reversed
			}
			static Vec2D<T> create(double radius, double dAngle)
			{
				Vec2D<T> point(radius, 0);

				point.rotDEG(dAngle);

				return point;
			}
	};

	template<typename T>
	const Vec2D<T> Vec2D<T>::ZERO(0, 0);

	template<typename T>
	const double Vec2D<T>::PI = 3.14;


	/// ----- VEC3D ----- ///

	template<typename T>
	class Vec3D
	{
		public:
			Vec3D()
			{
				x = 0;
				y = 0;
				z = 0;
			}
			Vec3D(T _X, T _Y, T _Z)
			{
				x = _X;
				y = _Y;
				z = _Z;
			}
			~Vec3D()
			{
				//dtor
			}
			bool operator==(const Vec3D& rhs)
			{
				if(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z)
					return true;

				return false;
			}
			bool operator!=(const Vec3D& rhs)
			{
				if(this->x != rhs.x || this->y != rhs.y || this->z != rhs.z)
					return true;

				return false;
			}

			T x;
			T y;
			T z;

			static const Vec3D<T> ZERO;
	};

	template<typename T>
	const Vec3D<T> Vec3D<T>::ZERO(0, 0, 0);


	/// ----- VEC4D ----- ///
	template<typename T>
	class Vec4D
	{
		public:
			Vec4D()
			{
				x = 0;
				y = 0;
				z = 0;
				t = 0;
			}
			Vec4D(T _X, T _Y, T _Z, T _T)
			{
				x = _X;
				y = _Y;
				z = _Z;
				t = _T;
			}
			~Vec4D()
			{
				//dtor
			}
			bool operator==(const Vec4D& rhs)
			{
				if(this->x == rhs.x && this->y == rhs.y && this->z == rhs.z && this->t == rhs.t)
					return true;

				return false;
			}
			bool operator!=(const Vec4D& rhs)
			{
				if(this->x != rhs.x || this->y != rhs.y || this->z != rhs.z || this->t != rhs.t)
					return true;

				return false;
			}

			T x;
			T y;
			union
			{
				struct
				{
					T z;
					T t;
				};

				struct
				{
					T w;
					T h;
				};
			};

			static const Vec4D<T> ZERO;
	};

	template<typename T>
	const Vec4D<T> Vec4D<T>::ZERO(0, 0, 0, 0);
}

#endif // GTS_VECTOR_H
