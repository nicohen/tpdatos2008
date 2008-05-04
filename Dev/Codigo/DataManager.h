#ifndef DATAMANAGER_H_
#define DATAMANAGER_H_

#include "DataFile.h"
#include <vector>
#include "Buffer/BlocksBuffer.h"
#include "Buffer/DataFilesBuffer.h"

using namespace std;

class DataManager{
	
private:
	char* _basePath;
	BlocksBuffer _blocksBuffer;
	DataFilesBuffer* _dataFilesBuffer;
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
	unsigned int getBufferCurrentSize();
	unsigned int getBufferBlocksCount();
	
	unsigned int getFilesBufferHitsCount();
	unsigned int getFilesBufferMissCount();
	unsigned int getFilesBufferTotalSize();
	unsigned int getFilesBufferCurrentSize();
	unsigned int getFilesBufferBlocksCount();
 
};

#endif /*DATAMANAGER_H_*/
