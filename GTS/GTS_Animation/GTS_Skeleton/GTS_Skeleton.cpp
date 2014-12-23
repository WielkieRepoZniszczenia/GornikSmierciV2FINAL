

Skeleton::Skeleton()
{
	//ctor
}

Skeleton::~Skeleton()
{
	//dtor
}



void Skeleton::add_bone(GTS::Bone& bone)
{
	mBones_.push_back(bone);
}
GTS::Bone* Skeleton::get_bone(unsigned int id)
{
	if(id >= mBones_.size())
	{
		printf("Could not get bone from skeleton. Wrong bone ID.\n");
		return NULL;
	}

	return &mBones_.at(id);
}
unsigned int Skeleton::bonesCount()
{
	return mBones_.size();
}



int Skeleton::render(int x, int y)
{
	return 0;
}



int Skeleton::save(std::ofstream& fout)
{
	int number_of_bones = mBones_.size();
	fout.write((char*) &number_of_bones, sizeof(number_of_bones));

	for(int n = 0; n < number_of_bones; ++n)
	{
		if(mBones_.at(n).save(fout) != 0)
		{
			printf("Could not save bone data.\n");
			return -1;
		}
	}

	return 0;
}
int Skeleton::load(std::ifstream& fin)
{
	int number_of_bones = 0;
	fin.read((char*) &number_of_bones, sizeof(number_of_bones));

	for(int n = 0; n < number_of_bones; ++n)
	{
		GTS::Bone newBone;
		if(newBone.load(fin) != 0)
		{
			printf("Could not load bone data.\n");
			return -1;
		}
		mBones_.push_back(newBone);
	}

	return 0;
}
