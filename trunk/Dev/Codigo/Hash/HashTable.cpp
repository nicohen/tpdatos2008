#include "HashTable.h"
#include "stdio.h"
#include "../Utils.h"

HashTable::HashTable(){
	_hashFile=NULL;
}

HashTable::~HashTable(){
	if (_hashFile!=NULL){
		fclose(_hashFile);
	}
	free(_fileName);
}

void HashTable::create(char* filePath, int size){
	_size=size;
	_hashFile=fopen(filePath,"w+");
	_fileName= cloneStr(filePath);
	fwrite(&size,INT_SIZE,1,_hashFile);	
}

void HashTable::load(char* filePath){
	_fileName= cloneStr(filePath);
	_hashFile=fopen(filePath,"r+");
	fread(&_size,INT_SIZE,1,_hashFile);
}

int HashTable::getSize(){
	return _size;
}

int HashTable::getAt(int i){
	int content;
	fseek(_hashFile,(i+1)*INT_SIZE,SEEK_SET);
	fread(&content,INT_SIZE,1,_hashFile);
	return content;
}

void HashTable::update(int index, int value){
	fseek(_hashFile,(index+1)*INT_SIZE,SEEK_SET);
	fwrite(&value,INT_SIZE,1,_hashFile);
}

void HashTable::grow(){
	int* buffer= (int*) malloc(INT_SIZE*_size);
	fseek(_hashFile,INT_SIZE,SEEK_SET);
	fread(buffer,INT_SIZE,_size,_hashFile);
	//fseek(_hashFile,INT_SIZE*(_size+1),SEEK_SET);
	fwrite(buffer,INT_SIZE,_size,_hashFile);
	_size=_size+_size;
	fseek(_hashFile,0,SEEK_SET);
	fwrite(&_size,INT_SIZE,1,_hashFile);
	free(buffer);
}
