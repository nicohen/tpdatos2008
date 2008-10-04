#include "FileManager.h"

namespace FileManager{
	
	FileManager::FileManager(){
	}

	FileManager::~FileManager(){
	}

	void FileManager::Open(FileInfo *fileInfo, char* mode){
		fileInfo->setFile(fopen(fileInfo->getFileName(),mode));
	}

	void FileManager::Close(FileInfo *fileInfo){
		fclose(fileInfo->getFile());
	}

	int FileManager::Read(void* dest,int count,FileInfo *fileInfo){
		return fread(dest,1,count,fileInfo->getFile());
	}

	void FileManager::Delete(FileInfo *fileInfo){
		remove(fileInfo->getFileName());
	}

	void FileManager::Write(void* source, int count, FileInfo *fileInfo){
		fwrite(source, 1, count, fileInfo->getFile());
	}
	
	FileInfo* FileManager::CreateFileInfo(char* fileName){
		return new FileInfo(this,fileName);
	}
};
