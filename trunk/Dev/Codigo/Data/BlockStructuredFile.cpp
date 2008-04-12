#include "BlockStructuredFile.h"
#include "../Utils.h"


BlockStructuredFile* BlockStructuredFile::Load(char* filename){
	BlockStructuredFile* res=NULL;
	res=new BlockStructuredFile(filename);
	res->load();
	return res;
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename,T_BLOCKSIZE blockSize){
	BlockStructuredFile* res=NULL;
	res=new BlockStructuredFile(filename);
	res->setBlockSize(blockSize);
	res->create();
	return res;
}

void BlockStructuredFile::setBlockSize(T_BLOCKSIZE size){
	this->_bblockSize=size;	
}
void BlockStructuredFile::setBlockCount(T_BLOCKCOUNT count){
	this->_bblockCount=count;
}

BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_file=NULL;
	this->_filename=filename;
	this->setBlockCount(0);
	this->setBlockSize(0);
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
	return getBlockSizePosition(reference)+sizeof(T_BLOCKSIZE);
}

char* BlockStructuredFile::getFirstFreeSpaceListItem(char* reference){
	return getBlockCountPosition(reference)+sizeof(T_BLOCKCOUNT);
}


//load header from buffer
void BlockStructuredFile::loadPropertiesFromBuffer(char* buffer){
	memcpy((char*)&this->_bblockSize,this->getBlockSizePosition(buffer),sizeof(T_BLOCKSIZE));
	memcpy((char*)&this->_bblockCount,this->getBlockCountPosition(buffer),sizeof(T_BLOCKCOUNT));

}

void BlockStructuredFile::load(){
	char* buffer;
	this->_file = new fstream(this->_filename,ios::app|ios::in|ios::out|ios::binary);
	T_BLOCKSIZE blockSize;

	//Me muevo a la posicion 0 del archivo
	this->_file->seekg (0, ios::beg);
	//Leo el primer campo (blockSize) para poder leer
	this->_file->read((char*)&blockSize,sizeof(T_BLOCKSIZE));
	
	
	//Cargo todo el bloque en un buffer y cargo las propiedades de ah�
	buffer=(char*)malloc(blockSize);	
	this->_file->seekg (0, ios::beg);
	this->_file->read(buffer,blockSize);
	
	this->loadPropertiesFromBuffer(buffer);
	
	delete buffer;
}


void BlockStructuredFile::saveHeaderToBuffer(char* buffer){
	T_BLOCKSIZE firstBlockFreeSpace=0;
	T_BLOCKSIZE blockSize;
	T_BLOCKCOUNT blockCount;
	blockSize=this->getBlockSize();
	blockCount=this->getBlockCount();
	firstBlockFreeSpace=this->getBlockSize() - sizeof(T_BLOCKSIZE) - sizeof(T_BLOCKCOUNT) - sizeof(T_BLOCKSIZE);
	//Grabo el tamaño de bloque
	memcpy(getBlockSizePosition(buffer),&blockSize,sizeof(T_BLOCKSIZE));

	//Grabo la cantidad de bloques
	memcpy(getBlockCountPosition(buffer),&blockCount,sizeof(T_BLOCKCOUNT));	

	//Grabo el primer elemento de la lista de espacios libres
	memcpy(getFirstFreeSpaceListItem(buffer),&firstBlockFreeSpace,sizeof(T_BLOCKSIZE));

}

void BlockStructuredFile::create(){
	char* buffer;
	this->setBlockCount(1);
	if(existsFile(this->_filename)){
		//ERROR
	}
	this->_file = new fstream(this->_filename,ios::trunc|ios::in|ios::out|ios::binary);
	
	
	buffer=(char*)malloc(this->getBlockSize());
	this->saveHeaderToBuffer(buffer);

	this->_file->seekg (0, ios::beg);
	this->_file->write(buffer,this->getBlockSize());
	this->_file->flush();
	delete buffer;
}

T_BLOCKCOUNT BlockStructuredFile::getBlockCount(){
	return this->_bblockCount;
}

T_BLOCKSIZE BlockStructuredFile::getBlockSize(){
	return this->_bblockSize;
}

void BlockStructuredFile::appendBlock(char* content){
	char* buffer;
	buffer=(char*)malloc(this->getBlockSize());
	memcpy(buffer,content,this->getBlockSize());
	this->setBlockCount(this->getBlockCount()+1);
	free (buffer);
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


