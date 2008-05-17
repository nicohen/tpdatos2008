#include "HashIndex.h"
#include <string.h>
#include "..\Utils.h"
//ContentOverflowBlockException
//StringValue
HashIndex::HashIndex()
{
}

HashIndex::~HashIndex()
{
	delete _keysfile;
	delete _hashtable;
}


void HashIndex::create(char* folderPath,char* filePath, int size){
	string keysFileName;
	string hashFileFullPath;
	string fullpath;
	
	fullpath.append(folderPath);
	fullpath.append(filePath);
	
	keysFileName.append(filePath);
	keysFileName.append(".keys");
	
	
	hashFileFullPath.append(fullpath);
	hashFileFullPath.append(".hash");
	
	
	_keysfile=new DataFile(keysFileName.c_str());
	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->save(folderPath);
	
	_hashtable=new HashTable();
	_hashtable->create(hashFileFullPath.c_str(),1);
	
}
void HashIndex::load(char* filePath){
	string keysFileName;
	string hashFileFullPath;
	string fullpath;
	
	fullpath.append(folderPath);
	fullpath.append(filePath);
	
	keysFileName.append(filePath);
	keysFileName.append(".keys");
	
	
	hashFileFullPath.append(fullpath);
	hashFileFullPath.append(".hash");
	
	
	_keysfile=new DataFile(keysFileName.c_str());
	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->load(folderPath);
	
	_hashtable=new HashTable();
	_hashtable->load(hashFileFullPath.c_str());
}

int HashIndex::getHash(char* arg){
	return 1;
}

void HashIndex::index(DataValue* keyValue,int blockNumber){
	if (keyValue->getCharType()!=DataType::STRING_TYPE){
		throw new "se esperaba stringValue";
	}
	int hashTablePos = getHash(((StringValue*)keyValue)->getString()) % _hashtable->getSize();
	int keysBlockNumber= _hashtable->getAt(hashTablePos);
	
	Record* keyRecord=new Record();
	keyRecord->addValue(new StringValue(cloneStr(((StringValue*)keyValue->getString()))));
	keyRecord->addValue(new IntValue(blockNumber));
	
	try{
		_keysfile->insertRecordAt(keysBlockNumber,keyRecord);
	}catch(ContentOverflowBlockException* ex){
		
	}
}
