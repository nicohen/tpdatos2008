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
	
	protected:
		virtual int getHash(char* arg);
public:
	HashIndex();
	virtual ~HashIndex();
	virtual void create(char* folderPath,char* filePath);
	virtual void load(char* folderPath,char* filePath);
	virtual void index(DataValue* keyValue,int blockNumber);
	
};

#endif /*HASHINDEX_H_*/
