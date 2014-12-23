

/// CTOR / DTOR
Pawn::Pawn()
{
	m_renderOrder = BOTTOM;
	bScaleOffset = true;

	m_parent = NULL;
}
Pawn::Pawn(PawnFrame& defaultFrame, RENDER_ORDER order, bool scaleOffset)
{
	m_frames.push_back(defaultFrame);
	m_renderOrder = order;
	bScaleOffset = scaleOffset;
}
Pawn::~Pawn()
{
	//dtor
}
///



/// PAWN SETTINGS
void Pawn::set_renderOrder(RENDER_ORDER order)
{
	m_renderOrder = order;
}
int Pawn::get_renderOrder()
{
	return m_renderOrder;
}
void Pawn::set_offsetScaling(bool scale)
{
	bScaleOffset = scale;
}
bool Pawn::get_offsetScaling()
{
	return bScaleOffset;
}

int Pawn::set_parent(Pawn* parent)
{
	if(parent == NULL)
	{
		printf("Error.\n");
		return -1;
	}

	if(check_root(parent) == true)
	{
		printf("Error! Given parent is already in this pawn root.\n");
		return -1;
	}

	m_parent = parent;

	return 0;
}
Pawn* Pawn::get_parent()
{
	return m_parent;
}

int Pawn::add_child(Pawn* child)
{
	if(child == NULL)
	{
		printf("Error.\n");
		return 0;
	}

	std::list<Pawn*>::iterator iLocator;
	for(iLocator = m_children.begin(); iLocator != m_children.end(); ++iLocator)
	{
		if(*iLocator == child)
		{
			printf("Can't add child to pawn. Child already on the list.\n");
			return -1;
		}
	}

	if(check_root(child) == true)
	{
        printf("Error! Given child is already in this pawn root.\n");
		return -1;
	}

	m_children.push_front(child);

	if(child->set_parent(this) != 0)
	{
		for(iLocator = m_children.begin(); iLocator != m_children.end(); ++iLocator)
		{
			if(*iLocator == child)
			{
				m_children.erase(iLocator);
				return -1;
			}
		}
	}

	return 0;
}
std::list<Pawn*> Pawn::get_children()
{
	return m_children;
}
///



/// ANIMATION SETTINGS
int Pawn::add_frame(GTS::PawnFrame frame)
{
	m_frames.push_back(frame);

	return 0;
}
GTS::PawnFrame* Pawn::get_frame(unsigned int id)
{
	if(id >= m_frames.size())
	{
		return NULL;
	}

	return &m_frames.at(id);
}

long Pawn::get_timeLine()
{
	long time = 0;

	unsigned int size = m_frames.size();
	for(unsigned int n = 0; n < size; ++n)
	{
		time += m_frames.at(n).timeGap;
	}

	return time;
}
///



/// RENDER
int Pawn::render(GTS::Vec2D<int> dPos, GTS::TexTrans dTexTrans, long timeFromStart)
{
	if(m_frames.size() == 0)
	{
		printf("Could not render pawn. PawnFrame was not set.\n");
		return -1;
	}

	/// time and frame control
	long timeLine = get_timeLine(); // sum of all frames time
	long gap = 0; // some time between 0 and timeLine ("inside" animation)
	if(timeLine != 0)
	{
		gap = timeFromStart%timeLine;
	}

	int currentID = get_currentID(gap); // gap is updated
	if(currentID < 0)
	{
		printf("Error! Can't chose current frame.\n");
		return -1;
	}

	PawnFrame* current = &m_frames.at(currentID);
	PawnFrame* next = NULL;
	if(currentID+1 < (int)m_frames.size())
		next = &m_frames.at(currentID+1);

	PawnFrame* appFrame = approx(current, next, dPos, dTexTrans, gap);
	if(appFrame == NULL)
	{
		return -1;
	}

	if(renderB(appFrame, dPos, dTexTrans, timeFromStart) != 0)
	{
		return -1;
	}

	delete appFrame;

	return 0;
}
int Pawn::renderB(GTS::PawnFrame* appFrame, GTS::Vec2D<int> dPos, GTS::TexTrans& dTrans, long timeFromStart)
{
	std::vector<Pawn*> pre_list;
	std::vector<Pawn*> post_list;

	std::list<Pawn*>::iterator iLocator;
	for(iLocator = m_children.begin(); iLocator != m_children.end(); ++iLocator)
	{
		if((*iLocator)->get_renderOrder() == BOTTOM)
		{
			pre_list.push_back(*iLocator);
		}
		else // TOP
		{
			post_list.push_back(*iLocator);
		}
	}

	/// RENDER BOTTOM
	for(unsigned int i = 0; i < pre_list.size(); ++i)
	{
		if(pre_list.at(i)->render(dPos, dTrans, timeFromStart) != 0)
			return -1;
	}

	/// RENDER PAWN
	if(appFrame->texture != NULL)
	{
		if(appFrame->texture->render(appFrame->offset.x, appFrame->offset.y, &appFrame->trans) != 0)
			return -1;
	}

	/// RENDER TOP
	for(unsigned int i = 0; i < post_list.size(); ++i)
	{
		if(post_list.at(i)->render(dPos, dTrans, timeFromStart) != 0)
			return -1;
	}

	return 0;
}
///



/// CURRENT FRAME
int Pawn::get_currentID(long& gap)
{
	unsigned int size = m_frames.size();
	for(unsigned int n = 0; n < size; ++n)
	{
		long frameGap = m_frames.at(n).timeGap;
		if(frameGap >= gap || frameGap == 0)
		{
			return n;
		}
		else
		{
			gap -= frameGap;
		}
	}

	return -1;
}
///



/// APPROXIMATION
PawnFrame* Pawn::approx(PawnFrame* current, PawnFrame* next, GTS::Vec2D<int>& dOff, GTS::TexTrans& dTexTrans, long dt)
{
	PawnFrame* appFrame = new PawnFrame(current->offset, current->trans, 0, current->texture);
	if(appFrame == NULL)
	{
		printf("Error during frame copying.\n");
		return NULL;
	}

	GTS::Vec2D<int> dFrameOffset;
	double dFrameAngle = 0;
	GTS::Vec2D<double> dFrameScale;

	/// approximate pawn frame
	if(next != NULL)
	{
		/// change %
		double div = 0;
		if(current->timeGap != 0)
		{
			div = (double)dt/(double)current->timeGap;
		}

		/// offset
		dFrameOffset = (next->offset - current->offset)*div;
		appFrame->offset = current->offset + dFrameOffset;

		/// angle
		dFrameAngle = (next->trans.angle - current->trans.angle)*div;
		appFrame->trans.angle = current->trans.angle + dFrameAngle;

		/// scale
		dFrameScale = (next->trans.scale - current->trans.scale)*div;
		appFrame->trans.scale = current->trans.scale + dFrameScale;

	}

	GTS::Vec2D<int> temp1 = appFrame->offset;
	if(bScaleOffset == true)
	{
		appFrame->offset.x *= dTexTrans.scale.x*appFrame->trans.scale.x;
		appFrame->offset.y *= dTexTrans.scale.y*appFrame->trans.scale.y;
	}
	appFrame->offset.rotDEG(dTexTrans.angle);
	GTS::Vec2D<int> temp2 = appFrame->offset;
	appFrame->offset += dOff;


	appFrame->trans.angle += dTexTrans.angle;

	appFrame->trans.scale *= dTexTrans.scale;

	dOff += temp2 - temp1;


	/// propagate transformation
		dOff += current->offset;// - m_frames.at(0).offset;
		dOff += dFrameOffset;

		dTexTrans.angle += current->trans.angle - m_frames.at(0).trans.angle; // difference between current, and original frame angle
		dTexTrans.angle += dFrameAngle; // approx. change

		dTexTrans.scale += current->trans.scale - m_frames.at(0).trans.scale;
		dTexTrans.scale += dFrameScale; // approx. change

	return appFrame;
}
///



/// CHECK PAWN
bool Pawn::check_root(Pawn* pawn)
{
	// go to root
	if(m_parent != NULL)
		return m_parent->check_root(pawn);

	// if root
	return this->check(pawn);
}
bool Pawn::check(Pawn* pawn)
{
	// check this
	if(pawn == this)
		return true;

	// check children
	std::list<Pawn*>::iterator iLocator;
	for(iLocator = m_children.begin(); iLocator != m_children.end(); ++iLocator)
	{
		if((*iLocator)->check(pawn) == true)
			return true;
	}

	return false;
}
///
