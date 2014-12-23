

PathFinder::PathFinder()
{
	mMaxSteps = 50;
	mCrossValue = 10;
	mDiagonalValue = 14;
}
PathFinder::~PathFinder()
{
	//dtor
}



void PathFinder::set(int max_steps, unsigned int cross_value, unsigned int diagonal_value)
{
	mMaxSteps = max_steps;
	mCrossValue = cross_value;
	mDiagonalValue = diagonal_value;
}


void PathFinder::check_step(int stepCost, std::list<GTS::Location*>::iterator OL_Locator, GTS::Location* location, GTS::Location* destination)
{
	GTS::Vec2D<unsigned short> destID = destination->get_id();
	GTS::Vec2D<unsigned short> locationID = location->get_id();

	long HVal = destID.x - locationID.x + destID.y - locationID.y;
	if(HVal < 0)
		HVal *= -1;
	unsigned long newValue = (*OL_Locator)->get_gVal() + stepCost +HVal;
	if(newValue < location->get_gVal())
	{
		location->set_gVal(newValue);
		location->set_hVal(HVal);
		location->set_parent(*OL_Locator);
	}
}
void PathFinder::add_to_OL(std::list<GTS::Location*>& _openList_, GTS::Location* location)
{
	if(location->get_checked() == false)
	{
		std::list<GTS::Location*>::iterator OL_Sorted;
		OL_Sorted = _openList_.begin();
		bool bDone = false;
		while(OL_Sorted != _openList_.end() && bDone != true)
		{
			if(location->get_hVal() < (*OL_Sorted)->get_hVal())
			{
				_openList_.insert(OL_Sorted, location);
				bDone = true;
			}
			++OL_Sorted;
		}
		if(bDone != true)
		{
			_openList_.push_back(location);
		}
	}
}

std::list<GTS::Location*>* PathFinder::find_path(GTS::Grid* grid, GTS::Location* currentLocation, GTS::Location* destination, bool underground)
{
	if(currentLocation == destination || currentLocation == NULL || destination == NULL)
	{
		return NULL;
	}

	bool bPathFound = false;
	GTS::Location* location = NULL;
	std::list<GTS::Location*>* _path_ = NULL;

	std::list<GTS::Location*> _openList_;
	std::list<GTS::Location*>::iterator OL_Locator; // open list iterator

	std::list<GTS::Location*> _closedList_;
	std::list<GTS::Location*>::iterator CL_Locator; // closed list iterator

	/** forward checking*/{
		_openList_.push_front(currentLocation);

		int step_counter = 0;
		while(bPathFound == false)
		{
			/** step checking */{
				if(step_counter == mMaxSteps)
				{
					return NULL;
				}
				++step_counter;
			}

			OL_Locator = _openList_.begin();
			// if there is nothing on the open list, and bPathFound is still false, something is wrong
			if(OL_Locator == _openList_.end())
			{
				return NULL;
			}

			/** calculating path */{

				GTS::Vec2D<unsigned short> ID = (*OL_Locator)->get_id();

				/** check all location around */
				for(int y = -1; y <= 1; ++y)
				{
					for(int x = -1; x <= 1; ++x)
					{
						if(x == 0 && y == 0)
							continue;

						location = grid->get_location(ID.x + x, ID.y + y, underground);
						if(location == NULL)
							continue;

						if(location == destination)
						{
							location->set_parent(*OL_Locator);
							bPathFound = true;
							break;
						}

						if(x == 0 || y == 0)
						{
							if(mCrossValue != 0)
								check_step(mCrossValue, OL_Locator, location, destination);
						}
						else
						{
							if(mDiagonalValue != 0)
								check_step(mDiagonalValue, OL_Locator, location, destination);
						}

						add_to_OL(_openList_, location);

					}// for(x)
					if(bPathFound == true)
						break;
				}// for(y)
				/** add to closed list */{
					(*OL_Locator)->set_checked(true);
					_closedList_.push_back(*OL_Locator);
					_openList_.erase(OL_Locator);
				}
			}
		}
	}
	/** back checking*/{
		if(bPathFound == true)
		{
			_path_ = new std::list<GTS::Location*>;
			location = destination;
			while(location != NULL)
			{
				_path_->push_front(location);
				location = location->get_parent();
			}
		}
	}
	/** clear grid */{
		for(OL_Locator = _openList_.begin(); OL_Locator != _openList_.end(); ++OL_Locator)
		{
			(*OL_Locator)->clear_path_data();
		}
		for(CL_Locator = _closedList_.begin(); CL_Locator != _closedList_.end(); ++CL_Locator)
		{
			(*CL_Locator)->clear_path_data();
		}
	}

	return _path_;
}
