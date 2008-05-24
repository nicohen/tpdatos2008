#ifndef HASHINDEX_H_
#define HASHINDEX_H_
#include "../DataValue.h"
#include "../DataFile.h"
#include "HashTable.h"
#include "../Data/Block.h"
#include "../Buffer/BlocksBuffer.h"

class DataFile;
class HashIndex
{
private:
	DataFile* _keysfile;
	HashTable* _hashtable;
	T_BLOCKSIZE _indexBlockSize;
	int _conflictiveKeysfileBlockNumber;
	DataType* _keyType;
	
protected:
		virtual unsigned int getHash(DataValue* input);
public:
	HashIndex(T_BLOCKSIZE indexBlockSize,DataType* keyType);
	virtual ~HashIndex();
	virtual void create(char* folderPath,char* filePath);
	virtual void load(char* folderPath,char* filePath);
	virtual void index(DataValue* keyValue,int blockNumber);
	virtual int getBlockNumber(DataValue* keyValue);
	virtual void reIndex(int keysBlockNumber);
	virtual void unIndex (DataValue* keyValue);
	virtual void update (DataValue* keyValue, int blockNumber);
	virtual void deleTe();
	virtual void setBlocksBuffer(BlocksBuffer* blocksBuffer);
	virtual	void simplify(int arg0);
	virtual unsigned int getHashTablePosition(DataValue* keyValue);
	virtual int getKeysFileBlockNumberFor(DataValue* keyValue);
	unsigned int RSHash(char* input);

};

#endif /*HASHINDEX_H_*/
