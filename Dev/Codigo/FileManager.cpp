#include "FileManager.h"

FileManager::FileManager(){
}

FILE* FileManager::Open(char* fileName, char* mode){
	return fopen(fileName,mode);
}
void FileManager::Close(FILE* file){
	fclose(file);
}

FileManager::~FileManager(){
}
