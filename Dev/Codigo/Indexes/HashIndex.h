#ifndef HASHINDEX_H_
#define HASHINDEX_H_
#include "../DataValue.h"
#include "../DataFile.h"
#include "HashTable.h"
#include "../Data/Block.h"
#include "../Buffer/BlocksBuffer.h"
#include "IIndex.h"
#include "string.h"

class DataFile;
class HashIndex: public IIndex
{
private:
	DataFile* _keysfile;
	HashTable* _hashtable;
	HashTable* _dispersionfile;
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
	virtual void simplify(int keysBlockNumber, DataValue* keyValue);
	virtual unsigned int getHashTablePosition(DataValue* keyValue);
	virtual int getKeysFileBlockNumberFor(DataValue* keyValue);
	unsigned int RSHash(char* input);
	virtual void toString(string* buffer);
	virtual int getSize();
	void appendBucket(int dispersion);
	void removeLastBucket();
	int getDispersion(int blockNumber);
	void updateDispersion(int blockNumber, int withValue);
	void updateHashTableCyclicaly(int startingPosition,int step,int updateWith);
};

#endif /*HASHINDEX_H_*/
