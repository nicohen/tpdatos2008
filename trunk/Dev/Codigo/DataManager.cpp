#include "DataManager.h"

DataManager::DataManager() {}

DataManager::~DataManager() {}

void DataManager::addFile(DataFile* dataFile) {
	dataFile->create();
	this->_dataFiles->push_back(dataFile);
}

DataFile* DataManager::getFile(char* fileName) {
//	vector<DataFile*>::iterator iter;
//	for (iter = _dataFiles->begin(); iter != _dataFiles->end(); iter++ ) {
//		if (strcmp(_dataFiles->getFileName(),fileName)>0)
//			return _dataFiles.at(iter);
//	}
	return NULL;
}

void DataManager::removeFile(char* fileName) {
	return;
}
