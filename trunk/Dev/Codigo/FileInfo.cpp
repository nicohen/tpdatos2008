#include "FileInfo.h"

namespace FileManager{

	FileInfo::FileInfo(char* fileName){
		_file= NULL;
		_name= cloneStr(fileName);
	}
	
	FileInfo::~FileInfo(){
		free(_name);
		if (_file!=NULL){
			FileManager::Close(this);
			_file=NULL;
		}
	}
	
	void FileInfo::close(void) throw (IOException){
		if (_file!=NULL){
			FileManager::Close(this);
			_file=NULL;
		}
	}
	
	void FileInfo::open(void) throw (IOException){
		FileManager::Open(this,"r+b");
		if (_file == NULL){
			throw IOException();
		}
	}
	
	int FileInfo::read(void* place, int size) throw (IOException){
		if (_file == NULL){
			throw IOException();
		}
		return FileManager::Read(place,size,this);	
	}
	
	void FileInfo::create(void) throw (IOException){
		FileManager::Open(this,"w+b");
		if (_file == NULL){
			throw IOException();
		}
	}
	
	void FileInfo::delet(void) throw (IOException){
		if (_file!=NULL){
			FileManager::Close(this);
			_file=NULL;
		}
		FileManager::Delete(this);
	}
	
	void FileInfo::write(void* source, int size) throw (IOException){
		if (_file == NULL){
			throw IOException();
		}
		FileManager::Write(source,size,this);
	}
}
