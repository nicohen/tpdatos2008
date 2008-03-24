#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include "FileInfo.h"
#include "stdio.h"

namespace FileManager{
		FILE* Open(char* fileName, char* mode);
		int Read(void* dest, int count, FILE* source);
		void Write(void* source, int count, FILE* dest);
		void Delete(char* fileName);
		void Close(FILE* file);
}

#endif /*FILEMANAGER_H_*/
