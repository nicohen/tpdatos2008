#include "FileInfo.h"

namespace FileManager{

	FileInfo::FileInfo(FileManager* fileManager, char* fileName){
		_file= NULL;
		_name= cloneStr(fileName);
		_fileManager = fileManager;
	}
	
	FileInfo::~FileInfo(){
		free(_name);
		if (_file!=NULL){
			_fileManager->Close(this);
			_file=NULL;
		}
	}
	
	void FileInfo::close(void) throw (IOException){
		if (_file!=NULL){
			_fileManager->Close(this);
			_file=NULL;
		}
	}
	
	void FileInfo::open(void) throw (IOException){
		_fileManager->Open(this,"r+b");
		if (_file == NULL){
			throw IOException();
		}
	}
	
	int FileInfo::read(void* place, int size) throw (IOException){
		if (_file == NULL){
			throw IOException();
		}
		return _fileManager->Read(place,size,this);	
	}
	
	void FileInfo::create(void) throw (IOException){
		_fileManager->Open(this,"w+b");
		if (_file == NULL){
			throw IOException();
		}
	}
	
	void FileInfo::delet(void) throw (IOException){
		if (_file!=NULL){
			_fileManager->Close(this);
			_file=NULL;
		}
		_fileManager->Delete(this);
	}
	
	void FileInfo::write(void* source, int size) throw (IOException){
		if (_file == NULL){
			throw IOException();
		}
		_fileManager->Write(source,size,this);
	}
}
