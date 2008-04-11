#include "stdafx.h"
#include "BlockStructuredFile.h"
#include "Common.h"


BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_filename=filename;
}
BlockStructuredFile::~BlockStructuredFile(){
	this->_file->close();
	delete this->_file;
}


void BlockStructuredFile::create(){
	char* buffer;
	char* it_buffer;	
	T_BLOCKCOUNT blockCount=1; 
	T_BLOCKSIZE firstBlockFreeSpace=506; 
	
	if(existsFile(this->_filename)){
		//ERROR
	}

	this->_file = new fstream(this->_filename,ios::trunc|ios::in|ios::out|ios::binary);

	buffer=(char*)malloc(this->_blockSize);
	
	//Muevo el puntero hacia adelante
	it_buffer=buffer;
	//Copio una variable local en el buffer
	memcpy(it_buffer,&this->_blockSize,sizeof(T_BLOCKSIZE));

	//Muevo el puntero hacia adelante
	it_buffer+=sizeof(T_BLOCKSIZE);
	//Copio una variable local en el buffer
	memcpy(it_buffer,&blockCount,sizeof(T_BLOCKCOUNT));	

	//Muevo el puntero hacia adelante
	it_buffer+=sizeof(T_BLOCKCOUNT);
	//Copio una variable local en el buffer
	memcpy(it_buffer,&firstBlockFreeSpace,sizeof(T_BLOCKSIZE));

	this->_file->seekg (0, ios::beg);
	this->_file->write(buffer,this->_blockSize);
	this->_file->flush();
	delete buffer;
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename,T_BLOCKSIZE blockSize){
	BlockStructuredFile* res=NULL;
	res=new BlockStructuredFile(filename);
	res->_blockSize=blockSize;
	res->create();
	return res;
}
