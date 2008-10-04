#include "Block.h"
#include "../Utils.h"



Block::Block(T_BLOCKSIZE size){
	this->_size=size;
	this->_freeSpace=size;
	this->_content=(char*)malloc(this->_size);
}


Block::~Block(){
	free(this->_content);
}

Block::Block(char* content,T_BLOCKSIZE size){
	this->_size=size;
	this->_freeSpace=0;
	this->_content=(char*)malloc(this->_size);
	this->setContent(content);
}

void Block::setFragment(char* content,T_BLOCKSIZE offset,T_BLOCKSIZE size){
	memcpy(this->_content+offset,content,size);
}

char* Block::getContent(){
	return this->_content;
}

T_BLOCKSIZE Block::getSize(){
	return this->_size;
}

T_BLOCKSIZE Block::getFreeSpace(){
	return this->_freeSpace;
}

T_BLOCKSIZE Block::getUsedSpace(){
	return (this->getSize()-this->getFreeSpace());
}

void Block::setFreeSpace(T_BLOCKSIZE space){
	this->_freeSpace=space;
}

void Block::setContent(char* content){
	this->setFragment(content,0,this->_size);
}

