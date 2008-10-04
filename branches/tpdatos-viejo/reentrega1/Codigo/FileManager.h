#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include "FileInfo.h"

namespace FileManager{
		class FileInfo;
		class FileManager{
			public:
			FileManager();
			void Open(FileInfo* fileInfo, char* mode);
			int Read(void* dest, int count, FileInfo* fileInfo);
			void Write(void* source, int count, FileInfo* fileInfo);
			void Delete(FileInfo* fileInfo);
			void Close(FileInfo* fileInfo);
			FileInfo* CreateFileInfo(char* fileName);
			~FileManager();
		};
}

#endif /*FILEMANAGER_H_*/
