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
	
	void FileInfo::open(char* openMode) throw (IOException){
		_fileManager->Open(this,openMode);
		if (_file == NULL){
			throw IOException();
		}
	}

	void FileInfo::read(void* place, int size) throw (IOException){
		int count;
		if (_file == NULL){
			throw IOException();
		}
		count = _fileManager->Read(place,size,this);
		if (count==0){
			throw IOException();
		}
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
