#include "DataManager.h"
#include <stdio.h>
#include "Utils.h"
#include "string.h"

using namespace std;

DataManager::DataManager(char* basePath) {
	this->_basePath = cloneStr(basePath);
}

DataManager::~DataManager() {
	free(this->_basePath);
}

void DataManager::addFile(DataFile* dataFile) {
	dataFile->save(this->_basePath);
}

DataFile* DataManager::getFile(char* fileName) {
	DataFile* dataFile;
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
