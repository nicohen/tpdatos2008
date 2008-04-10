#include "stdafx.h"
#include "BlockStructuredFile.h"


BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_filename=filename;
}
BlockStructuredFile::~BlockStructuredFile(){
	this->_file->close();
	delete this->_file;
}

void BlockStructuredFile::create(){
	fstream* existingFile=NULL;
	existingFile = new fstream(this->_filename,ios::in|ios::binary);
	if(existingFile->is_open()){
		//Error, llamando al crear cuando ya existe el archivo
		existingFile->close();
	}
	delete existingFile;

	this->_file = new fstream(this->_filename,ios::trunc|ios::in|ios::out|ios::binary);
	this->_file->seekg (0, ios::beg);
	this->_file->write((char*)&this->_blockSize,sizeof(T_BLOCKSIZE));
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename,T_BLOCKSIZE blockSize){
	BlockStructuredFile* res=NULL;
	res=new BlockStructuredFile(filename);
	res->_blockSize=blockSize;
	res->create();
	return res;
}
