#include "DataManager.h"
#include <stdio.h>
#include "Utils.h"
#include "string.h"
#include "Data/FileNotFoundException.h"

using namespace std;

DataManager::DataManager(char* basePath, int bufferSize):_blocksBuffer(bufferSize) {
	this->_basePath = cloneStr(basePath);
	
	this->_dataFilesBuffer=new DataFilesBuffer(5);
	
}

DataManager::~DataManager() {
	free(_dataFilesBuffer);
	free(this->_basePath);
}

void DataManager::addFile(DataFile* dataFile) {
	dataFile->save(this->_basePath);
	_dataFilesBuffer->addFile(dataFile->getFileName(),dataFile);
}

DataFile* DataManager::getFile(char* fileName) {
	DataFile* dataFile=_dataFilesBuffer->getFile(fileName);
	if(dataFile==NULL){
		dataFile = new DataFile(fileName);
		dataFile->load(this->_basePath);
		dataFile->setBlocksBuffer(&_blocksBuffer);
		_dataFilesBuffer->addFile(fileName,dataFile);
	}
	return dataFile;
	//throw "[Excepcion]:No se encontro el archivo en DataFile.getFile";
}

bool DataManager::removeFile(char* fileName) {
	try{
		this->getFile(fileName)->deleTe();
		return true;	
	}catch(FileNotFoundException* ex){
		delete ex;
		return false;
	}
}

char* DataManager::getBasePath() {
	return this->_basePath;
}

unsigned int DataManager::getBufferHitsCount() {
	return this->_blocksBuffer.getHits();
}

unsigned int DataManager::getBufferMissCount() {
	return this->_blocksBuffer.getMiss();
}

unsigned int DataManager::getBufferTotalSize() {
	return this->_blocksBuffer.getTotalSize();
}

unsigned int DataManager::getBufferCurrentSize() {
	return this->_blocksBuffer.getCurrentSize();
}

unsigned int DataManager::getBufferBlocksCount() {
	return this->_blocksBuffer.getBlocksCount();
}

unsigned int DataManager::getFilesBufferHitsCount() {
	return this->_dataFilesBuffer->getHits();
}

unsigned int DataManager::getFilesBufferMissCount() {
	return this->_dataFilesBuffer->getMiss();
}

unsigned int DataManager::getFilesBufferTotalSize() {
	return this->_dataFilesBuffer->getTotalSize();
}

unsigned int DataManager::getFilesBufferCurrentSize() {
	return this->_dataFilesBuffer->getCurrentSize();
}

unsigned int DataManager::getFilesBufferBlocksCount() {
	return this->_dataFilesBuffer->getBlocksCount();
}
