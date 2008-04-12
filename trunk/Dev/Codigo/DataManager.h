#ifndef DATAMANAGER_H_
#define DATAMANAGER_H_

#include "DataFile.h"
#include <vector>

class DataManager{
	
private:
	vector<DataFile*>* _dataFiles;
	
public:
	DataManager();
	virtual ~DataManager();
	void addFile(DataFile* file);
	DataFile* getFile(char* fileName);
	void removeFile(char* fileName);
};

#endif /*DATAMANAGER_H_*/
