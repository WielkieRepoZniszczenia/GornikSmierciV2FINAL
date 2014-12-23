#ifndef GTS_ACTOR_H
#define GTS_ACTOR_H

#include "GTS_Object/GTS_Object.h"


namespace GTS /// class declaration
{
	class Actor : public GTS::Object
	{
		public:
			Actor();
			virtual ~Actor();

			virtual int order(GTS::Command command, GTS::Command* response = NULL); // look in .cpp file


			virtual int update(long currentTime) = 0;
			virtual int show() = 0;

			//virtual int save(std::ofstream* fout){return 0;}
			//virtual int load(std::ifstream* fin){return 0;}

		protected:
			/** Move
				*
				*/
				virtual bool move(){return false;}

			/** Movement data

				*/
				bool bMoving;
				GTS::Vec3D<long> mNewPosition;
				GTS::Vec3D<double> mVelocity; // it must be scaled by grid projection angle()

		private:

	};

	#include "GTS_Actor.cpp"

}

#endif // GTS_ACTOR_H
