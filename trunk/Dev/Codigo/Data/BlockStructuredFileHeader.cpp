#include "BlockStructuredFileHeader.h"

BlockStructuredFileHeader::BlockStructuredFileHeader()
{
	this->setBlockCount(0);
	this->setBlockSize(0);
}

BlockStructuredFileHeader::~BlockStructuredFileHeader()
{
}

void BlockStructuredFileHeader::setBlockSize(T_BLOCKSIZE size){
	this->_blockSize=size;	
}
void BlockStructuredFileHeader::setBlockCount(T_BLOCKCOUNT count){
	this->_blockCount=count;
}

T_BLOCKCOUNT BlockStructuredFileHeader::getBlockCount(){
	return this->_blockCount;
}

T_BLOCKSIZE BlockStructuredFileHeader::getBlockSize(){
	return this->_blockSize;
}

char* BlockStructuredFileHeader::getBlockSizePosition(char* reference){
	return reference+0;
}

char* BlockStructuredFileHeader::getBlockCountPosition(char* reference){
	return getBlockSizePosition(reference)+sizeof(T_BLOCKSIZE);
}

char* BlockStructuredFileHeader::getFirstFreeSpaceListItem(char* reference){
	return getBlockCountPosition(reference)+sizeof(T_BLOCKCOUNT);
}

void BlockStructuredFileHeader::loadPropertiesFromBuffer(char* buffer){
	memcpy((char*)&this->_bblockSize,this->getBlockSizePosition(buffer),sizeof(T_BLOCKSIZE));
	memcpy((char*)&this->_bblockCount,this->getBlockCountPosition(buffer),sizeof(T_BLOCKCOUNT));

}

void BlockStructuredFileHeader::saveHeaderToBuffer(char* buffer){
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