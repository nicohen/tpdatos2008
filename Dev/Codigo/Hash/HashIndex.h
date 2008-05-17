#ifndef HASHINDEX_H_
#define HASHINDEX_H_
#include "../DataValue.h"
#include "../DataFile.h"
#include "HashTable.h"

class HashIndex
{
private:
	DataFile* _keysfile;
	HashTable* _hashtable;
public:
	HashIndex();
	virtual ~HashIndex();
	virtual void create(char* filePath, int size);
	virtual void load(char* filePath);
	virtual void insert(DataValue* keyValue,int blockNumber);
	
};

#endif /*HASHINDEX_H_*/
