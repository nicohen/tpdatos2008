#include "FileInfo.h"
/*
	// GETERS y SETERS NECESARIOS
	//char* getFileName(void){return _name;};
	//void setFile(FILE* file){_file = file;};
	//FILE* getFile(void){return _file;};
	
	void write(void* source, int size);
*/
FileInfo::FileInfo(char* fileName){
	_file= NULL;
	_name= cloneStr(fileName);
}

FileInfo::~FileInfo(){
	free(_name);
	if (_file!=NULL){
		fclose(_file);
		_file=NULL;
	}
}

void FileInfo::close(void){
	if (_file!=NULL){
		FileManager::Close(_file);
		_file=NULL;
	}
}

void FileInfo::open(char* mode){
	_file=FileManager::Open(_name,mode);
}

int FileInfo::read(void* place, int size){
	return FileManager::Read(place,size,_file);	
}

void FileInfo::create(char* mode){
	FileManager::Open(_name,mode);
}

void FileInfo::delet(void){
	if (_file!=NULL){
		FileManager::Close(_file);
		_file=NULL;
	}
	FileManager::Delete(_name);
}

void FileInfo::write(void* source, int size){
	FileManager::Write(source,size,_file);
}
