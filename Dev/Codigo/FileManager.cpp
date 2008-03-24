#include "FileManager.h"

FILE* FileManager::Open(char* fileName, char* mode){
	return fopen(fileName,mode);
}

void FileManager::Close(FILE* file){
	fclose(file);
}

int FileManager::Read(void* dest,int count,FILE* source){
	return fread(dest,1,count,source);
}

void FileManager::Delete(char* fileName){
	remove(fileName);
}

void FileManager::Write(void* source, int count, FILE* dest){
	fwrite(source, 1, count, dest);
}
