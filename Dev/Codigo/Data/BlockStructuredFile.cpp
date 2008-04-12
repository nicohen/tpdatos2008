#include "BlockStructuredFile.h"
#include "../Utils.h"


void BlockStructuredFile::setBlockSize(T_BLOCKSIZE size){
	//this->_bblockSize=size;
	this->_header->setBlockSize(size);
}
void BlockStructuredFile::setBlockCount(T_BLOCKCOUNT count){
	//this->_bblockCount=count;
	this->_header->setBlockCount(count);	
}
T_BLOCKCOUNT BlockStructuredFile::getBlockCount(){
	return this->_header->getBlockCount();
}

T_BLOCKSIZE BlockStructuredFile::getBlockSize(){
	return this->_header->getBlockSize();
}

BlockStructuredFile* BlockStructuredFile::Load(char* filename){
	BlockStructuredFile* res=NULL;
	T_BLOCKSIZE blockSize;
	fstream* file=NULL;
	
	file = new fstream(filename,ios::in|ios::binary);
	//Me muevo a la posicion 0 del archivo
	file->seekg (0, ios::beg);	
	//Leo el primer campo (blockSize) para poder leer
	file->read((char*)&blockSize,sizeof(T_BLOCKSIZE));
	delete file;
	
	res=new BlockStructuredFile(filename);
	res->load(blockSize);
	return res;
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename,T_BLOCKSIZE blockSize){
	BlockStructuredFile* res=NULL;
	fstream* file=NULL;
	file = new fstream(filename,ios::trunc|ios::in|ios::out|ios::binary);
	file->close();
	delete file;
	
	res=new BlockStructuredFile(filename);
	res->setBlockSize(blockSize);
	res->setBlockCount(1);
	res->saveHeader();
	return res;
}


BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_file=NULL;
	this->_filename=filename;
	if(!existsFile(this->_filename)){
		//ERROR
	}
	//this->_file = new fstream(this->_filename,ios::app|ios::in|ios::out|ios::binary);
	this->_file = new fstream(this->_filename,ios::in|ios::out|ios::binary);
	this->_header=new BlockStructuredFileHeader();
	this->setBlockCount(0);
	this->setBlockSize(0);
}

BlockStructuredFile::~BlockStructuredFile(){
	if(this->_file!=NULL){
		this->_file->close();
		delete this->_file;
	}
	delete this->_header;
}

void BlockStructuredFile::load(T_BLOCKSIZE blockSize){
	char* buffer;
	//Cargo todo el bloque en un buffer y cargo las propiedades de ah�
	buffer=(char*)malloc(blockSize);
	this->_file->seekg (0, ios::beg);
	this->_file->read(buffer,blockSize);	
	this->_header->loadPropertiesFromBuffer(buffer);	
	delete buffer;
}

void BlockStructuredFile::saveHeader(){
	char* buffer;
	
	buffer=(char*)malloc(this->getBlockSize());

	this->_header->saveHeaderToBuffer(buffer);

	this->_file->seekg (0, ios::beg);
	this->_file->write(buffer,this->getBlockSize());
	this->_file->flush();
	delete buffer;
}

void BlockStructuredFile::appendBlock(char* content){
	char* buffer;
	buffer=(char*)malloc(this->getBlockSize());
	memcpy(buffer,content,this->getBlockSize());
	this->setBlockCount(this->getBlockCount()+1);
	free (buffer);
}

void BlockStructuredFile::updateBlock(T_BLOCKCOUNT blockNumber,char* content){
	this->_file->seekg(this->getBlockSize()*(blockNumber+1),ios::beg);
	this->_file->write(content,this->getBlockSize());
	
	if(blockNumber+1>=this->getBlockCount()){
		this->setBlockCount(this->getBlockCount()+1);
		this->saveHeader();
	}	
}

