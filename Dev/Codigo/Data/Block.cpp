#include "Block.h"
#include "../Utils.h"
#include "ContentOverflowBlockException.h"
 
Block::Block(T_BLOCKSIZE size){
	this->_size=size;
	this->_freeSpace=size;
	this->_content=(char*)malloc(this->_size);
	
	char clean='\0';
	for (int i=0;i<this->_size;i++){
		this->setFragment(&clean,i,1);	
	}
} 

Block::~Block(){
	free(this->_content);
}

Block::Block(char* content,T_BLOCKSIZE size){
	char clean='\0';	
	this->_size=size;
	this->_freeSpace=0;
	this->_content=(char*)malloc(this->_size);
	for (int i=0;i<this->_size;i++){
		this->setFragment(&clean,i,1);	
	}
	this->setContent(content);
}

void Block::setFragment(char* content,T_BLOCKSIZE offset,T_BLOCKSIZE size){
	memcpy(this->_content+offset,content,size);
}

char* Block::getContent(){
	if(this->getSize()<this->getUsedSpace()){
		throw new ContentOverflowBlockException();
	}
	return this->_content;
}

T_BLOCKSIZE Block::getSize(){
	return this->_size;
} 

T_BLOCKSIZE Block::getUsedSpace(){
	return this->_size;
} 

void Block::setContent(char* content){
	char clean='\0';
	for (int i=0;i<this->_size;i++){
		this->setFragment(&clean,i,1);	
	}
	this->setFragment(content,0,this->_size);
}


