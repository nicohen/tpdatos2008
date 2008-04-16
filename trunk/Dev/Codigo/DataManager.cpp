#include "DataManager.h"
#include <stdio.h>
#include "Utils.h"
#include "string.h"

using namespace std;

DataManager::DataManager(char* basePath) {
	this->_dataFiles = new vector<DataFile*>();
	this->_basePath = cloneStr(basePath);
}

void DataManager::clearFiles(vector<DataFile*>* dataFiles) {
	vector<DataFile*>::iterator iter;
	for (iter = dataFiles->begin(); iter != dataFiles->end(); iter++ ) {
		delete ((DataFile*)*iter);
	}
	dataFiles->clear();
}

DataManager::~DataManager() {
	this->clearFiles(this->_dataFiles);
	delete(_dataFiles);
	free(this->_basePath);
}

void DataManager::addFile(DataFile* dataFile) {
	//dataFile->create();
	dataFile->save(this->_basePath);
//	DEBUG("Hay que hacer Push Back en DataManager");
//	this->_dataFiles->push_back(dataFile);
}

DataFile* DataManager::getFile(char* fileName) {
	DataFile* dataFile;
	/*string* buffer = new string();
	char* absoluteFilePath;
	*/
	//Lo trae del vector
	vector<DataFile*>::iterator iter;
	for (iter = _dataFiles->begin(); iter != _dataFiles->end(); iter++ ) {
		dataFile = ((DataFile*)*iter);
		if (strcmp(dataFile->getFileName(),fileName)==0) {
			return dataFile;
		}
	}
/*
//	buffer->append(_basePath);
	buffer->append(fileName);
	absoluteFilePath = (char*) malloc(strlen(buffer->c_str()));
	strcpy(absoluteFilePath,buffer->c_str());*/

	//Si no esta en el vector, lo trae de disco
	dataFile = new DataFile(fileName);
	dataFile->load(this->_basePath);
	return dataFile;
	//throw "[Excepcion]:No se encontro el archivo en DataFile.getFile";
}

bool DataManager::removeFile(char* fileName) {
	string* buffer = new string();
	char* cadena;
	bool isRemoved = false;
	
	buffer->append(_basePath);
	buffer->append(fileName);
	
	cadena = (char*) malloc(strlen(buffer->c_str()));
	strcpy(cadena,buffer->c_str());
	
	isRemoved = hadSuccessRemoving(remove(cadena));
	
	delete buffer;
	free(cadena);
	return isRemoved;
}

char* DataManager::getBasePath() {
	return this->_basePath;
}
