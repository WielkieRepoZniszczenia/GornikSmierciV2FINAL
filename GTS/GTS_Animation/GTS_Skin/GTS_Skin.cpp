

Skin::Skin()
{
	//ctor
}

Skin::~Skin()
{
	//dtor
}


void Skin::add_texture(GTS::Texture* texture)
{
	mTextures_.push_back(texture);
}
GTS::Texture* Skin::get_texture(unsigned int id)
{
	if(id >= size())
	{
		printf("Could not get texture from skin. Wrong ID.\n");
		return NULL;
	}

	return mTextures_.at(id);
}

int Skin::replace(GTS::Texture* texture, unsigned int id)
{
	if(id >= size())
	{
		printf("Could not replace texture in skin. Wrong ID.\n");
		return -1;
	}

	mTextures_.at(id) = texture;

	return 0;
}

unsigned int Skin::size()
{
	return mTextures_.size();
}


int Skin::render(int x, int y, GTS::Skeleton* skeleton)
{
	if(skeleton == NULL)
	{
		printf("Error! Skeleton can't be null pointer.\n");
		return -1;
	}
	unsigned int nBones = skeleton->bonesCount();
	if(mTextures_.size() != nBones)
	{
		int a = nBones;
		int b = mTextures_.size();

		printf("Error! There is a difference between bones count and number of skin elements:\n bones:%d != skin elements:%d.\n", a, b);
		return -1;
	}

	GTS::TextureTransformation transformation;

	std::list<GTS::Bone>::iterator nLocator;
	for(unsigned int n = 0; n < nBones; ++n)
	{
		GTS::Bone* bone = skeleton->get_bone(n);
		if(bone == NULL)
		{
			printf("Could not extract bone from given skeleton.\n");
			return -1;
		}
		transformation.mAngle = bone->get_angle();
		transformation.mCenter.x = bone->get_center().x;
		transformation.mCenter.y = bone->get_center().y;
		transformation.mClip = NULL;
		transformation.mFlip = bone->get_flip();
		transformation.mScale = bone->get_skale();

		GTS::Vec2D<int> offset = bone->get_center();

		unsigned int textureID = bone->get_textureID();
		if(textureID >= mTextures_.size())
		{
			printf("Could not render texture. Given bone has wrong texture ID.\n");
			return -1;
		}
		GTS::Texture* texture = mTextures_.at(textureID);
		if(texture != NULL)
			if(texture->render(x - offset.x, y - offset.y, &transformation) != 0)
				return -1;
	}
	return 0;
}
