#include "stdafx.h"
#include "BlockStructuredFile.h"
#include "Common.h"



BlockStructuredFile* BlockStructuredFile::Load(char* filename){
	BlockStructuredFile* res=NULL;
	res=new BlockStructuredFile(filename);
	res->load();
	return res;
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename,T_BLOCKSIZE blockSize){
	BlockStructuredFile* res=NULL;
	res=new BlockStructuredFile(filename);
	res->_blockSize=blockSize;
	res->create();
	return res;
}

BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_file=NULL;
	this->_filename=filename;
	this->_blockCount=0;
	this->_blockSize=0;
}

BlockStructuredFile::~BlockStructuredFile(){
	if(this->_file!=NULL){
		this->_file->close();
		delete this->_file;
	}
}

char* BlockStructuredFile::getBlockSizePosition(char* reference){
	return reference+0;
}

char* BlockStructuredFile::getBlockCountPosition(char* reference){
	return reference+0+sizeof(T_BLOCKSIZE);
}

void BlockStructuredFile::loadPropertiesFromBuffer(char* buffer){
	memcpy((char*)&this->_blockSize,this->getBlockSizePosition(buffer),sizeof(T_BLOCKSIZE));
	memcpy((char*)&this->_blockCount,this->getBlockCountPosition(buffer),sizeof(T_BLOCKCOUNT));

}

void BlockStructuredFile::load(){
	char* buffer;
	this->_file = new fstream(this->_filename,ios::app|ios::in|ios::out|ios::binary);
	T_BLOCKSIZE blockSize;

	//Me muevo a la posicion 0 del archivo
	this->_file->seekg (0, ios::beg);
	//Leo el primer campo (blockSize) para poder leer
	this->_file->read((char*)&blockSize,sizeof(T_BLOCKSIZE));
	
	
	//Cargo todo el bloque en un buffer y cargo las propiedades de ahí
	buffer=(char*)malloc(blockSize);	
	this->_file->seekg (0, ios::beg);
	this->_file->read(buffer,blockSize);	
	this->loadPropertiesFromBuffer(buffer);
	delete buffer;
}




void BlockStructuredFile::create(){
	char* buffer;
	char* it_buffer;
	T_BLOCKSIZE firstBlockFreeSpace=0;	
	
	this->_blockCount=1;
	firstBlockFreeSpace=this->_blockSize - sizeof(T_BLOCKSIZE) - sizeof(T_BLOCKCOUNT) - sizeof(T_BLOCKSIZE);
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
	memcpy(it_buffer,&this->_blockCount,sizeof(T_BLOCKCOUNT));	

	//Muevo el puntero hacia adelante
	it_buffer+=sizeof(T_BLOCKCOUNT);
	//Copio una variable local en el buffer
	memcpy(it_buffer,&firstBlockFreeSpace,sizeof(T_BLOCKSIZE));

	this->_file->seekg (0, ios::beg);
	this->_file->write(buffer,this->_blockSize);
	this->_file->flush();
	delete buffer;
}

T_BLOCKCOUNT BlockStructuredFile::getBlockCount(){
	return this->_blockCount;
}

T_BLOCKSIZE BlockStructuredFile::getBlockSize(){
	return this->_blockSize;
}




/*
	T_BLOCKSIZE startPos=0;
	Block* block=NULL;
	---^^Esto va arriba---^^

	block= new Block(this->_blockSize);
	startPos=0;
	block->set(startPos,(char*)&this->_blockSize,sizeof(T_BLOCKSIZE));
	startPos+=sizeof(T_BLOCKSIZE);
	block->set(startPos,(char*)&blockCount,sizeof(T_BLOCKCOUNT));
	startPos+=sizeof(T_BLOCKSIZE);
	block->set(startPos,(char*)&firstBlockFreeSpace,sizeof(T_BLOCKSIZE));


	this->_file->seekg (0, ios::beg);
	this->_file->write(block->getContent(),block->getSize());
	this->_file->flush();

	delete block;*/