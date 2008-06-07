#ifndef IINDEX_H_
#define IINDEX_H_

#include "../DataValue.h"
#include "../Buffer/BlocksBuffer.h"
#include <string>

class IIndex
{
public:
	IIndex();
	virtual ~IIndex();
	
	virtual void create(char* folderPath,char* filePath)=0;
	virtual void load(char* folderPath,char* filePath)=0;
	virtual void index(DataValue* keyValue,int blockNumber)=0;
	virtual int getBlockNumber(DataValue* keyValue)=0;
	virtual void unIndex (DataValue* keyValue)=0;
	virtual void update (DataValue* keyValue, int blockNumber)=0;
	virtual void deleTe()=0;
	virtual void setBlocksBuffer(BlocksBuffer* blocksBuffer)=0;
	virtual void toString(string* buffer)=0;
	
};

#endif /*IINDEX_H_*/
