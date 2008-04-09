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
	fstream file (this->_filename,ios::trunc|ios::in|ios::binary|ios::out);
	file.clear();
	file.close();
	
}