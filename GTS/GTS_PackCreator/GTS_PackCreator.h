#ifndef GTS_PACKCREATOR_H
#define GTS_PACKCREATOR_H

#include <stdio.h>
#include <fstream>
#include <string>
#include "iostring.cpp"
#include <map>

using namespace std;

/**
	* this structure saves the position of independent file data inside gtsPacks
	* it has nothing to do with c++ pointers!
	*/
typedef struct{
	long pos;
	long size;
} PackPointer;

namespace GTS
{
	class GTS_PackCreator
	{
		private:
			string mCurrentPackName;
			map<string, PackPointer> mFiles;
			string mCurrentFileName;
			fstream mFio;
			bool bPackOpen;
			bool bAutoDelete; // set to false by default

		public:
			GTS_PackCreator();
			~GTS_PackCreator();

				void set_autoDelete(bool flag);

			/** @@ create_pack exp. @@
				* this function opens new file with .gtsPACK extension
				* new pack is created in your main folder
				* must be closed by close_pack
				* returns -1 on error
				*/
				int create_pack(string packName);

			/** @@ open_pack exp. @@
				* mFio is opened with given path
					* if file is empty function returns -1
				* if file opening was successful all pointers to the data files and the names of files
				  inside pack are saved into map container...
					* if after this operation map container is empty function returns -1
				* ...that way you can call create_file(fileName) to create desired file from pack
				*/
				int open_pack(string path);

			/** @@ add_file exp. @@
				* don't use dots in extension, function will add it by itself
				* you can pass empty strings for path and extension but
				  empty fileName will cause the function to return -1
				*/
				int add_file(string path, string fileName, string extension);

			/** @@ create_file exp. @@
				* calls map container for pointer to data in opened pack
					* if fileName is not found, function returns -1
					* if you do not have opened any package yet function will return -1
				* mCurrentFileName is set to given fileName
				* if bAutoDelete is set to true, created file will be deleted on next
				  call for this function, or on pack closing stage
				*/
				int create_file(string fileName);

			/** @@ close_pack exp. @@
				* shuts down mFio
				* map container is erased
					* if map container was empty before, pack is deleted and function returns -1
				* if bAutoDelete is true - delete file with mCurrentFileName
				* mCurrentFileName is set to empty string
				*/
				int close_pack();


	};

	#include "GTS_PackCreator.cpp"
}

#endif // GTS_PACKCREATOR_H
