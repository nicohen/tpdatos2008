#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include "FileInfo.h"
#include "stdio.h"

class FileManager{
	public:
		FileManager();
		FILE* Open(char* fileName, char* mode);
		void Close(FILE* file);
		virtual ~FileManager();
};

#endif /*FILEMANAGER_H_*/
