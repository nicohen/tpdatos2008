#include "HashIndex.h"
#include <string.h>
#include "../Utils.h"
#include "../Data/ContentOverflowBlockException.h"
#include "../StringValue.h"
#include "../Data/KeysBlockFactory.h"
#include "../IntValue.h"

HashIndex::HashIndex()
{
}

HashIndex::~HashIndex()
{
	delete _keysfile;
	delete _hashtable;
}


void HashIndex::create(char* folderPath,char* filePath){
	string keysFileName;
	string hashFileFullPath;
	string fullpath;
	
	fullpath.append(folderPath);
	fullpath.append(filePath);
	
	keysFileName.append(filePath);
	keysFileName.append(".keys");
	
	
	hashFileFullPath.append(fullpath);
	hashFileFullPath.append(".hash");
	
	
	_keysfile=new DataFile((char*)keysFileName.c_str());
	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->save(folderPath);
	
	_hashtable=new HashTable();
	_hashtable->create((char*)hashFileFullPath.c_str(),1);
	
}
void HashIndex::load(char* folderPath,char* filePath){
	string keysFileName;
	string hashFileFullPath;
	string fullpath;
	
	fullpath.append(folderPath);
	fullpath.append(filePath);
	
	keysFileName.append(filePath);
	keysFileName.append(".keys");
	
	
	hashFileFullPath.append(fullpath);
	hashFileFullPath.append(".hash");
	
	
	_keysfile=new DataFile((char*)keysFileName.c_str());
	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->load(folderPath);
	
	_hashtable=new HashTable();
	_hashtable->load((char*)hashFileFullPath.c_str());
}

int HashIndex::getHash(char* arg){
	return 1;
}

void HashIndex::index(DataValue* keyValue,int blockNumber){
	int recordPosition;
	
	if (keyValue->getCharType()!=DataType::STRING_TYPE){
		throw "se esperaba stringValue";
	}
	int hashTablePos = getHash(((StringValue*)keyValue)->getString()) % _hashtable->getSize();
	int keysBlockNumber= _hashtable->getAt(hashTablePos);
	
	Record* keyRecord=new Record();
	keyRecord->addValue(new StringValue(cloneStr((((StringValue*)keyValue)->getString()))));
	keyRecord->addValue(new IntValue(keysBlockNumber));
	
	try{
		_keysfile->insertRecordAt(keysBlockNumber,keyRecord);
	}catch(ContentOverflowBlockException* ex){
		recordPosition = _keysfile->insertRecord(keyRecord);
		_hashtable->grow();
		_hashtable->update(hashTablePos,recordPosition);
	}
}
