

GTS_PackCreator::GTS_PackCreator()
{
	bPackOpen = false;
	bAutoDelete = false;
}

GTS_PackCreator::~GTS_PackCreator()
{
	//dtor
}

void GTS_PackCreator::set_autoDelete(bool flag)
{
	bAutoDelete = flag;
}

int GTS_PackCreator::create_pack(string packName)
{
	if(bPackOpen == true)
	{
		printf("Could not create new pack. You must first close current pack.\n");
		return -1;
	}

	/// file creation
	mFio.open(packName.c_str(), ios::binary | ios::out);
	if(!mFio)
	{
		printf("Could not create new pack.\n"); // need to add message !!
		return -1;
	}
	mFio.close();
	///

	mFio.open(packName.c_str(), ios::binary | ios::in | ios::out);
	if(!mFio)
	{
		printf("Could not open new pack.\n"); // need to add message !!
		return -1;
	}

	mCurrentPackName = packName;

	mFio.seekg(0, mFio.end);
	mFio.seekp(0, mFio.end);
	long size = mFio.tellp();
	if(size != 0)
	{
		printf("Could not create new pack. File already exist! %ld\n", size);
		mFio.close();
		return -1;
	}

	bPackOpen = true;

	return 0;
}

int GTS_PackCreator::open_pack(string path)
{
	if(bPackOpen == true)
	{
		printf("Could not open pack. You must first close current pack.\n");
		return -1;
	}
	mFio.open(path.c_str(), ios::binary | ios::in | ios::out);
	if(!mFio)
	{
		printf("Could not open pack.\n"); // need to add message !!
		return -1;
	}
	mCurrentPackName = path;

	mFio.seekg(mFio.beg);
	mFio.seekp(mFio.beg);

	string str = "";
	do
	{
		loadString(str, &mFio);
		if(str != "")
		{
			PackPointer packPointer;
			mFio.read((char*)&packPointer.size, sizeof(packPointer.size));
			packPointer.pos = mFio.tellg();
			mFiles.insert(make_pair(str, packPointer));
		}
	}
	while(str != "");

	if(mFiles.size() == 0)
	{
		printf("Pack opening error. Pack was empty?\n");
		return -1;
	}

	bPackOpen = true;

	return 0;
}

int GTS_PackCreator::add_file(string path, string fileName, string extension)
{
	if(bPackOpen == false)
	{
		printf("There is no open pack to add file in.\n");
		return -1;
	}
	if(fileName == "")
	{
		printf("You can't add file with no name.\n");
		return -1;
	}

	string strToFind = fileName + "." + extension;

	map<string, PackPointer>::iterator mLoc;
	mLoc = mFiles.find(strToFind);
	if(mLoc != mFiles.end())
	{
		printf("File already exist in pack.\n");
		return -1;
	}

    mFio.seekg(0, mFio.end);
    mFio.seekp(0, mFio.end);

	/// save file name
		saveString(strToFind, &mFio);

	/// save file size
		ifstream fin;
		fin.open((path + fileName + "." + extension).c_str(), ios::binary);
		if(!fin)
		{
			printf("Could not add file to pack. File does not exist.\n");
			return -1;
		}
		fin.seekg(0, fin.end);
		long length = fin.tellg();
		fin.seekg(0);

		PackPointer dummy;

		mFio.write((char*) &length, sizeof(dummy.size));

		dummy.size = length;
		dummy.pos = mFio.tellg();

		mFiles.insert(make_pair(strToFind, dummy));

	/// save file data
		int bufSize = 1024;
		long bSeg_num = length/bufSize; //ilosc buforow 1024bytes
		long rest = length%bufSize; // reszta danych z dzielenia przez 1024

		char* buffer = new char[bufSize];
		char* rbuf = new char[rest];

		for(int nSeg = 0; nSeg < bSeg_num; ++nSeg)
		{
			fin.read(buffer, bufSize);
			mFio.write(buffer, bufSize);
		}

		fin.read(rbuf, rest);
		mFio.write(rbuf, rest);

		fin.close();


	return 0;
}

int GTS_PackCreator::create_file(string fileName)
{
	if(bPackOpen == false)
	{
		printf("Could not create file. No pack is open.\n");
		return -1;
	}

	map<string, PackPointer>::iterator iLoc;
	iLoc = mFiles.find(fileName);
	if(iLoc == mFiles.end())
	{
		printf("Could not create file. File does not exist in the pack.\n");
		return -1;
	}

	mCurrentFileName = iLoc->first;

	ofstream fout;
	fout.open(mCurrentFileName.c_str(), ios::binary);
	if(!fout)
	{
		printf("Could not create file. File opening error.\n");
		return -1;
	}

	mFio.seekp(iLoc->second.pos);
	mFio.seekg(iLoc->second.pos);

	int bufSize = 1024;
	long bSeg_num = iLoc->second.size/bufSize; //ilosc buforow 1024bytes
	long rest = iLoc->second.size%bufSize; // reszta danych z dzielenia przez 1024

	char* buffer = new char[bufSize];
	char* rbuf = new char[rest];
	for(int nSeg = 0; nSeg < bSeg_num; ++nSeg)
	{
		mFio.read(buffer, bufSize);
		fout.write(buffer, bufSize);
	}

	mFio.read(rbuf, rest);
	fout.write(rbuf, rest);

	fout.close();

	return 0;
}

int GTS_PackCreator::close_pack()
{
	if(bPackOpen != true)
	{
		printf("Could not close the pack, because it is already closed.\n");
		return -1;
	}
	mFio.close();

	if(mFiles.size() == 0)
	{
		printf("You trying to create empty pack.\n");
		remove(mCurrentPackName.c_str());

		return -1;
	}

	mFiles.clear();

	if(mCurrentFileName != "")
	{
		if(bAutoDelete == true)
		{
			remove(mCurrentFileName.c_str());
		}
		mCurrentFileName = "";
	}
	return 0;
}
