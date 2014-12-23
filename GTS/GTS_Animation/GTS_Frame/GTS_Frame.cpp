

Frame::Frame()
{
	mTimeGap = 0;
}

Frame::~Frame()
{
	//dtor
}


void Frame::set_skeleton(GTS::Skeleton& skeleton)
{
	mSkeleton = skeleton;
}
void Frame::set_timeGap(long timeGap)
{
	mTimeGap = timeGap;
}

GTS::Skeleton* Frame::get_skeleton()
{
	return &mSkeleton;
}
long Frame::get_timeGap()
{
	return mTimeGap;
}


int Frame::bonesCount()
{
	return mSkeleton.bonesCount();
}


int Frame::save(std::ofstream& fout)
{
	fout.write((char*) &mTimeGap, sizeof(mTimeGap));
	mSkeleton.save(fout);

	return 0;
}
int Frame::load(std::ifstream& fin)
{
	fin.read((char*) &mTimeGap, sizeof(mTimeGap));
	mSkeleton.load(fin);

	return 0;
}
