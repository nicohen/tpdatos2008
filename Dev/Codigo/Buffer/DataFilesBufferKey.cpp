#include "DataFilesBufferKey.h"
#include "../Utils.h"
#include "stdio.h"

DataFilesBufferKey::DataFilesBufferKey(char* filename){
	this->_filename=cloneStr(filename);
}

bool DataFilesBufferKey::isLowerThan(IComparable* other){
	DataFilesBufferKey* key2= (DataFilesBufferKey*)other;
	return (strcmp(this->_filename, key2->_filename) < 0);
}

char* DataFilesBufferKey::toString(){
	char* cadena = (char*)malloc(strlen(this->_filename)+70);		
	sprintf(cadena,"FILE DESCRIPTOR BUFFER: [FileName:%s]",this->_filename);
	return cadena;
}

DataFilesBufferKey::~DataFilesBufferKey(){
	free(_filename);
}
