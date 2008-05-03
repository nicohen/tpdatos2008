#ifndef DATAMANAGER_H_
#define DATAMANAGER_H_

#include "DataFile.h"
#include <vector>
#include "Buffer/BlocksBuffer.h"

using namespace std;

class DataManager{
	
private:
	char* _basePath;
	int _bufferSize;
	BlocksBuffer* _blocksBuffer;
public:
	DataManager(char* basePath, int bufferSize);
	virtual ~DataManager();
	void addFile(DataFile* file);
	DataFile* getFile(char* fileName);
	char* getBasePath();
	bool removeFile(char* fileName);
	
	unsigned int getBufferHitsCount();
	unsigned int getBufferMissCount();
	unsigned int getBufferTotalSize();
 
};

#endif /*DATAMANAGER_H_*/
