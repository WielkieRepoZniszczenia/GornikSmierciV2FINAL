

Animation::Animation()
{
	bLoop = true;
}

Animation::~Animation()
{
	//dtor
}


int Animation::add_frame(GTS::Skeleton& skeleton, long timeGap)
{
	GTS::Frame frame;
			   frame.set_skeleton(skeleton);
			   frame.set_timeGap(timeGap);

	_mFrames_.push_back(frame);

	return 0;
}



void Animation::set_loop(bool loop)
{
	bLoop = loop;
}
bool Animation::get_loop()
{
	return bLoop;
}


GTS::Skeleton* Animation::get_momentary_skeleton(long time_offset)
{
	GTS::Skeleton* skeleton = new GTS::Skeleton;

	// bone and skin transformations

	//test
	std::list<GTS::Frame>::iterator nLocator;
	nLocator = _mFrames_.begin();
	*skeleton = *nLocator->get_skeleton();

	return skeleton;
}

int Animation::bonesCount()
{
	std::list<GTS::Frame>::iterator nLocator;
	if(_mFrames_.size() != 0)
	{
		nLocator = _mFrames_.begin();
		return nLocator->bonesCount();
	}

	return 0;
}

int Animation::save(std::ofstream& fout)
{
	int number_of_frames_ = _mFrames_.size();
	fout.write((char*) &number_of_frames_, sizeof(number_of_frames_));

	std::list<GTS::Frame>::iterator nLocator;
    for(nLocator = _mFrames_.begin(); nLocator != _mFrames_.end(); ++nLocator)
	{
		nLocator->save(fout);
	}
	return 0;
}
int Animation::load(std::ifstream& fin)
{
	int number_of_frames_ = 0;
	fin.read((char*) &number_of_frames_, sizeof(number_of_frames_));

	for(int n = 0; n < number_of_frames_; ++n)
	{
		GTS::Frame newFrame;
		newFrame.load(fin);
		_mFrames_.push_back(newFrame);
	}

	return 0;
}
