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

void DataBlock::writeRecord(char* recordContent){
	char recordCount=0;//Refactor here -->"char"

	fstream file (this->_filename,ios::in|ios::out|ios::binary);	
	if(file.is_open()){
		
		/*
		recordCount=(char)4;
		file.write(&recordCount,1);
		*/
		
		file.seekg(0,ios::beg);
		file.read(&recordCount,1);//Refactor here -->"1"
		recordCount++;
		//recordCount=(char)4;
		file.seekg(0,ios::beg);
		file.write(&recordCount,1);


		/*
		file->seekg(0,ios::beg);
		file->read(&recordCount,1);//Refactor here -->"1"

		file->write(&length,1);
		file->write(content,strlen(content));
		*/
	}	
	file.close();
}

