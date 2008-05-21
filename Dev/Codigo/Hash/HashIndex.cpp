#include "HashIndex.h"
#include <string.h>
#include "../Utils.h"
#include "../Data/ContentOverflowBlockException.h"
#include "../Data/RecordSizeOverflowException.h"
#include "../StringValue.h"
#include "../Data/KeysBlockFactory.h"
#include "../IntValue.h"
#include "../Data/RecordNotFoundException.h"
#include "../Field.h"
#include <vector>

HashIndex::HashIndex(T_BLOCKSIZE indexBlockSize)
{
	_indexBlockSize=indexBlockSize;
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
	
	vector<Field*>* fields=new vector<Field*>();
	
	Field* keyField = new Field();
	Field* secondaryField1 = new Field();
	
	keyField->setDataType(new StringType());
	secondaryField1->setDataType(new IntType());
	
	//fields->push_back(keyField);
	fields->push_back(secondaryField1);
	

	_keysfile=new DataFile((char*)keysFileName.c_str(),_indexBlockSize,keyField,fields,NULL);
	//_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->save(folderPath);
	delete _keysfile;
	_keysfile = new DataFile((char*)keysFileName.c_str());
	_keysfile->load(folderPath);
	
	_hashtable=new HashTable();
	_hashtable->create((char*)hashFileFullPath.c_str(),1);
	_hashtable->update(0,1);
}

void HashIndex::unIndex(DataValue* keyValue) {
	int hashTablePos = getHash(((StringValue*)keyValue)->getString()) % _hashtable->getSize();
	int keysBlockNumber= _hashtable->getAt(hashTablePos);

	string buffer;	
	buffer.append("HASH: Desindexando registro");
	keyValue->toString(&buffer);
	DEBUGS(&buffer);
	
	_keysfile->removeRecordAt(keysBlockNumber,0,keyValue);
}

void HashIndex::update(DataValue* keyValue, int blockNumber) {
	int hashTablePos = getHash(((StringValue*)keyValue)->getString()) % _hashtable->getSize();
	int keysBlockNumber= _hashtable->getAt(hashTablePos);
	Record* keyRecord=new Record();
	keyRecord->addValue(new StringValue(cloneStr((((StringValue*)keyValue)->getString()))));
	keyRecord->addValue(new IntValue(blockNumber));
	_keysfile->updateRecordAt(keysBlockNumber,keyRecord);
}

void HashIndex::deleTe(){
	_keysfile->deleTe();
	_hashtable->deleTe();
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
//	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->load(folderPath);
	_indexBlockSize= _keysfile->getBlockStructuredFile()->getBlockSize();
	
	_hashtable=new HashTable();
	_hashtable->load((char*)hashFileFullPath.c_str());
}

int HashIndex::getHash(char* arg){
	return ElHashDeCubillas(arg);
}

void HashIndex::reIndex(int keysBlockNumber) {
	vector<Record*>* erasedRecords = _keysfile->removeRecordsAt(keysBlockNumber);

	string buffer;
	buffer.append("HASH: Inicio de reindexacion de registros");
	DEBUGS(&buffer);

	Record* each=NULL;
	vector<Record*>::iterator iter;
	for (iter = erasedRecords->begin(); iter != erasedRecords->end(); iter++ ){
		each=((Record*)*iter);
		index(each->getValues()->at(0),((IntValue*)each->getValues()->at(1))->getInt());
	}
//	DEBUG("HASH: Fin de reindexacion de registros");
}

void HashIndex::index(DataValue* keyValue,int blockNumber){
	if (keyValue->getCharType()!=DataType::STRING_TYPE){
		throw "se esperaba stringValue";
	}
	int hashTablePos = getHash(((StringValue*)keyValue)->getString()) % _hashtable->getSize();
	int keysBlockNumber= _hashtable->getAt(hashTablePos);
	
	string buffer;
	buffer.append("HASH Indexando el registro: ");
	keyValue->toString(&buffer);
	DEBUGS(&buffer);
	
	Record* keyRecord=new Record();
	keyRecord->addValue(new StringValue(cloneStr((((StringValue*)keyValue)->getString()))));
	keyRecord->addValue(new IntValue(blockNumber));
	
	try{
		_keysfile->insertRecordAt(keysBlockNumber,keyRecord);
	}catch(ContentOverflowBlockException* ex){
		_keysfile->appendEmptyBlock();
		_hashtable->grow();
		_hashtable->update(hashTablePos,_keysfile->getLastRecordsBlockIndex());
		this->reIndex(keysBlockNumber);
		this->index(keyValue,blockNumber);
	}catch(RecordSizeOverflowException* ex2){
		delete ex2;
		string exmessage;
		buffer.append("HASH [ERROR]: No se puede indexar el registro ");
		keyRecord->toString(&exmessage);
		exmessage.append(" porque su tamaño es mayor al de un bloque.");
		DEBUGS(&exmessage);		
	}
}

int HashIndex::getBlockNumber(DataValue* keyValue) {
	int hashTablePos = getHash(((StringValue*)keyValue)->getString()) % _hashtable->getSize();
	int keysBlockNumber= _hashtable->getAt(hashTablePos);

	string buffer;
	buffer.append("HASH: Buscando numero de bloque del registro");
	keyValue->toString(&buffer);
	DEBUGS(&buffer);

	vector<Record*>* recordsFound = _keysfile->findRecordsAt(keysBlockNumber,0,keyValue);
	if (recordsFound->size()==0) {
		throw new RecordNotFoundException();
	}
	
	return ((IntValue*)recordsFound->at(0)->getValues()->at(1))->getInt();
}

void HashIndex::setBlocksBuffer(BlocksBuffer* blocksBuffer) {
	_keysfile->setBlocksBuffer(blocksBuffer);
	_keysfile->appendEmptyBlock();
}
