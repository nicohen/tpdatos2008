#include "DataFilesBuffer.h"

DataFilesBuffer::DataFilesBuffer(int size):_systemBuffer(size){
}

DataFilesBuffer::~DataFilesBuffer(){
}

//bool DataFilesBuffer::isInBuffer(char* fileName){
//	DataFilesBufferKey* bk= new DataFilesBufferKey(fileName);
//	bool found= this->_systemBuffer.isInBuffer(bk);
//	delete bk;
//	return found;
//}

void DataFilesBuffer::addFile(char* filename,DataFile* aDataFile){
	DataFilesBufferKey* bk= new DataFilesBufferKey(filename);
	this->_systemBuffer.addElement(bk,aDataFile);
}

DataFile* DataFilesBuffer::getFile(char* fileName){
	DataFilesBufferKey* bk= new DataFilesBufferKey(fileName);
	IBuffereable* element=	this->_systemBuffer.getElement(bk);
	delete bk;
	return (DataFile*)element; 
}

void DataFilesBuffer::removeFile(char* filename){
	DataFilesBufferKey* bk= new DataFilesBufferKey(filename);
	this->_systemBuffer.removeElement(bk);
	delete(bk);
}

unsigned int DataFilesBuffer::getHits() {
	return _systemBuffer.getHits();
}

unsigned int DataFilesBuffer::getMiss() {
	return _systemBuffer.getMiss();
}

unsigned int DataFilesBuffer::getTotalSize() {
	return _systemBuffer.getTotalSize();
}

unsigned int DataFilesBuffer::getCurrentSize() {
	return _systemBuffer.getCurrentSize();
}

unsigned int DataFilesBuffer::getBlocksCount() {
	return _systemBuffer.getElementsCount();
}
