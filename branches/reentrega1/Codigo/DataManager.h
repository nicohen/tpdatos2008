#ifndef DATAMANAGER_H_
#define DATAMANAGER_H_

#include "DataFile.h"
#include <vector>

using namespace std;

class DataManager{
	
private:
	char* _basePath;	
public:
	DataManager(char* basePath);
	virtual ~DataManager();
	void addFile(DataFile* file);
	DataFile* getFile(char* fileName);
	char* getBasePath();
	bool removeFile(char* fileName);
};

#endif /*DATAMANAGER_H_*/
