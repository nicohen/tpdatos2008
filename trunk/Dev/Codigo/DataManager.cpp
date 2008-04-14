#include "DataManager.h"

DataManager::DataManager() {
	this->_dataFiles = new vector<DataFile*>();
}

DataManager::~DataManager() {}

void DataManager::addFile(DataFile* dataFile) {
	dataFile->create();
	DEBUG("Hay que hacer Push Back en DataManager");
	this->_dataFiles->push_back(dataFile);
}

DataFile* DataManager::getFile(char* fileName) {
	DataFile* dataFile;
	vector<DataFile*>::iterator iter;
	for (iter = _dataFiles->begin(); iter != _dataFiles->end(); iter++ ) {
		dataFile = ((DataFile*)*iter);
		if (strcmp(dataFile->getFileName(),fileName)==0)
			return dataFile;
	}
	throw "[Excepcion]:No se encontro el archivo en DataFile.getFile";
}

void DataManager::removeFile(char* fileName) {
	return;
}
