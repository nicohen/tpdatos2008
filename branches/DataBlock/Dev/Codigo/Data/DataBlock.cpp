#include "stdafx.h"
#include "DataBlock.h"

#include <iostream>
#include <fstream>

using namespace std;

DataBlock::DataBlock(char* filename,int size){
	this->_filename=filename;
	this->_size=size;
}
	
DataBlock::~DataBlock(){
}


void DataBlock::allocateSpace(){
	char* buffer = NULL;
	fstream file (this->_filename,ios::trunc|ios::in|ios::binary|ios::out);
	file.seekg (0, ios::beg);

	buffer=new char [this->_size];
	for(int i=0;i<this->_size;i++){
		*(buffer+i)='\0';
	}
	file.write(buffer,this->_size);
	file.close();
	delete[] buffer;	
}