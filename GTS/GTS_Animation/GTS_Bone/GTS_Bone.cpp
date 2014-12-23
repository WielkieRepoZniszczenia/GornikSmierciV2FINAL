

Bone::Bone()
{
	mPosition.x = 0;
	mPosition.y = 0;
	mScale.x = 1.0;
	mScale.y = 1.0;
	mAngle = 0.0;
	mCenter.x = 0;
	mCenter.y = 0;
	mTextureID = -1; // no texture
	mParentID = -1; // no parent
}

Bone::~Bone()
{
	//dtor
}


void Bone::set_position(int x, int y)
{
	mPosition.x = x;
	mPosition.y = y;
}
void Bone::set_skale(double sx, double sy)
{
	mScale.x = sx;
	mScale.y = sy;
}
void Bone::set_angle(double angle)
{
	mAngle = angle;
}
void Bone::set_center(int x, int y)
{
	mCenter.x = x;
	mCenter.y = y;
}
void Bone::set_flip(SDL_RendererFlip flip)
{
	mFlip = flip;
}
void Bone::set_textureID(int id)
{
	mTextureID = id;
}
void Bone::set_parentID(int id)
{
	mParentID = id;
}





GTS::Vec2D<int> Bone::get_position()
{
	return mPosition;
}
GTS::Vec2D<double> Bone::get_skale()
{
	return mScale;
}
double Bone::get_angle()
{
	return mAngle;
}
GTS::Vec2D<int> Bone::get_center()
{
	return mCenter;
}
SDL_RendererFlip Bone::get_flip()
{
	return mFlip;
}
int Bone::get_textureID()
{
	return mTextureID;
}
int Bone::get_parentID()
{
	return mParentID;
}





int Bone::save(std::ofstream& fout)
{
	fout.write((char*) &mPosition, sizeof(mPosition));
	fout.write((char*) &mCenter, sizeof(mCenter));
	fout.write((char*) &mScale, sizeof(mScale));
	fout.write((char*) &mAngle, sizeof(mAngle));
	fout.write((char*) &mFlip, sizeof(mFlip));
	fout.write((char*) &mTextureID, sizeof(mTextureID));
	fout.write((char*) &mParentID, sizeof(mParentID));

	return 0;
}
int Bone::load(std::ifstream& fin)
{
	fin.read((char*) &mPosition, sizeof(mPosition));
	fin.read((char*) &mCenter, sizeof(mCenter));
	fin.read((char*) &mScale, sizeof(mScale));
	fin.read((char*) &mAngle, sizeof(mAngle));
	fin.read((char*) &mFlip, sizeof(mFlip));
	fin.read((char*) &mTextureID, sizeof(mTextureID));
	fin.read((char*) &mParentID, sizeof(mParentID));

	return 0;
}
