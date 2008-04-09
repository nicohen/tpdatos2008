#include "stdafx.h"
#include "DataBlock.h"

#include <iostream>
#include <fstream>

using namespace std;

DataBlock::DataBlock(char* filename,int size){
	this->_filename=filename;
	this->_size=size;
	this->_buffer=(char*)malloc(size);
}
	
DataBlock::~DataBlock(){
	free(this->_buffer);
}


void DataBlock::writeRecord(char* recordContent){
	this->update();
	(*this->_buffer)++;
}

void DataBlock::update(){
	fstream file (this->_filename,ios::in|ios::out|ios::binary);	
	if(file.is_open()){		
		file.seekg(0,ios::beg);
		file.read(this->_buffer,this->_size);
	}	
	file.close();
}

void DataBlock::clear(){
	for(int i=0;i<this->_size;i++){
		*(this->_buffer+i)='\0';
	}
}

void DataBlock::flush(){
	fstream file (this->_filename,ios::trunc|ios::in|ios::binary|ios::out);
	file.seekg (0, ios::beg);
	file.write(this->_buffer,this->_size);
	file.close();	
}
