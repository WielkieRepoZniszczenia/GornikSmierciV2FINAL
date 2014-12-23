#ifndef GTS_PATHFINDER_H
#define GTS_PATHFINDER_H

#include <list>
#include "GTS_Location/GTS_Location.h"

/// SINGLETON
namespace GTS
{
	class PathFinder
	{
		public:
			PathFinder();
			~PathFinder();


			void set(int max_steps, unsigned int cross_value, unsigned int diagonal_value = 0);

			/** FIND PATH
				* if max_steps is equal -1 returned list can grow to 12*grid_size( //3*pointer)
				* list must be deleted outside this class
				* if returned list is null it means that path was not found
				*/
				std::list<GTS::Location*>* find_path(GTS::Grid* grid, GTS::Location* currentLocation, GTS::Location* destination, bool underground);

		protected:
		private:
			int mMaxSteps;
			int mDiagonalValue;
			int mCrossValue;
			//GTS::StepCondition* mCondition;//function object that check if pawn can move to next location(need to be done)

			void check_step(int stepCost, std::list<GTS::Location*>::iterator OL_Locator, GTS::Location* location, GTS::Location* destination);
			void add_to_OL(std::list<GTS::Location*>& _openList_, GTS::Location* location);
	};

	#include "GTS_PathFinder.cpp"
}

#endif // GTS_PATHFINDER_H
