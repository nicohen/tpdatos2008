#include "stdafx.h"
#include "Block.h"
#include "stdlib.h"


Block::Block(T_BLOCKSIZE size){
	this->_size=size;
	this->_content=(char*)malloc(this->_size);
}


Block::Block(char* content,T_BLOCKSIZE size){
	this->_size=size;
	this->_content=(char*)malloc(this->_size);
	memcpy(this->_content,&content,sizeof(T_BLOCKSIZE));
}

void Block::set(T_BLOCKSIZE startPos,char* content,int size){
	memcpy(this->_content+startPos,&content,sizeof(T_BLOCKSIZE));
}

char* Block::getContent(){
	return this->_content;
}


Block::~Block(void){
	free(this->_content);
}
int Block::getSize(){
	return 0;
}