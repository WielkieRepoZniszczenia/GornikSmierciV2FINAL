

Command::Command()
{
	//ctor
}

Command::~Command()
{
	//dtor
}

std::string Command::get_type()
{
	return mTypeName;
}

std::string Command::get_dataString()
{
	return mDataString;
}


template<class cType>
int Command::encrypt(cType* structData)
{
	if(mTypeName.size() > 0)
	{
		return -1;
	}
	if(mDataString.size() > 0)
	{
		return -1;
	}

	mTypeName = typeid(cType).name();

	mDataString = cast_to<char*>(structData);

	return 0;
}

template<class cType>
const cType* Command::extract()
{
	const char* bytes = mDataString.c_str();

	const cType* structData = cast_to<const cType*>(bytes);

	return structData;
	//cType tmpStruct;
	//memcopy(&tmpStruct, bytes, sizeof(tmpStruct));

	//return tmpStruct;
}

void Command::close()
{
	mTypeName = "";

	mDataString = "";
}
