#include "HashIndex.h"
#include <string.h>
#include "../Utils.h"
#include "../Data/ContentOverflowBlockException.h"
#include "../Data/RecordSizeOverflowException.h"
#include "../StringValue.h"
#include "../Data/KeysBlockFactory.h"
#include "../Data/KeysBlock.h"
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
	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->save(folderPath);
	delete _keysfile;
	_keysfile = new DataFile((char*)keysFileName.c_str());
	_keysfile->load(folderPath);
	
	_hashtable=new HashTable();
	_hashtable->create((char*)hashFileFullPath.c_str(),1);
	_hashtable->update(0,1);
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
	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->load(folderPath);
	_indexBlockSize= _keysfile->getBlockStructuredFile()->getBlockSize();
	
	_hashtable=new HashTable();
	_hashtable->load((char*)hashFileFullPath.c_str());
}

void HashIndex::unIndex(DataValue* keyValue) {
	string buffer;	
	buffer.append("HASH Desindexando clave '");
	keyValue->toString(&buffer);
	buffer.append("'");
	DEBUGS(&buffer);
	
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);	
	
	_keysfile->removeRecordAt(keysBlockNumber,0,keyValue);
}

void HashIndex::update(DataValue* keyValue, int blockNumber) {
	string buffer;	
	buffer.append("HASH Actualizando clave '");
	keyValue->toString(&buffer);
	buffer.append("'... Nuevo numero de bloque de datos '");
	appendIntTo(&buffer,blockNumber);
	buffer.append("'");
	DEBUGS(&buffer);
	
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);
	
	Record* keyRecord=new Record();
	keyRecord->addValue(new StringValue(cloneStr((((StringValue*)keyValue)->getString()))));
	keyRecord->addValue(new IntValue(blockNumber));
	
	_keysfile->updateRecordAt(keysBlockNumber,keyRecord);
}

unsigned int HashIndex::getHash(char* arg){
	return ElHashDeCubillas(arg);
}

void HashIndex::reIndex(int keysBlockNumber) {
	vector<Record*>* erasedRecords = _keysfile->removeRecordsAt(keysBlockNumber);

	string buffer;
	buffer.append("HASH Reindexando el bucket número '");
	appendIntTo(&buffer,keysBlockNumber);
	buffer.append("'");
	DEBUGS(&buffer);

	Record* each=NULL;
	vector<Record*>::iterator iter;
	for (iter = erasedRecords->begin(); iter != erasedRecords->end(); iter++ ){
		each=((Record*)*iter);
		index(each->getValues()->at(0),((IntValue*)each->getValues()->at(1))->getInt());
	}
//	DEBUG("HASH: Fin de reindexacion de registros");
}

unsigned int HashIndex::getHashTablePosition(DataValue* keyValue){
	string buffer;
	buffer.append("HASH buscando posicion en la tabla para la clave '");
	keyValue->toString(&buffer);	
	unsigned int hashTablePos = getHash(((StringValue*)keyValue)->getString()) % _hashtable->getSize();
	buffer.append("'... Posición obtenida '");
	appendIntTo(&buffer,hashTablePos);
	buffer.append("'");
	DEBUGS(&buffer);
	return hashTablePos;
}

int HashIndex::getKeysFileBlockNumberFor(DataValue* keyValue){
	string buffer;
	buffer.append("HASH buscando numero de bucket para la clave '");
	keyValue->toString(&buffer);
	int blockNumber = _hashtable->getAt(getHashTablePosition(keyValue));
	buffer.append("' ... Numero de bucket obtenido: ");
	appendIntTo(&buffer,blockNumber);
	return blockNumber;
}

void HashIndex::index(DataValue* keyValue,int blockNumber){
	if (keyValue->getCharType()!=DataType::STRING_TYPE){
		throw "se esperaba stringValue";
	}
	
	string startMsg;
	startMsg.append("HASH Indexando la clave '");
	keyValue->toString(&startMsg);
	startMsg.append("' asociada al bloque de datos número '");
	appendIntTo(&startMsg,blockNumber);
	startMsg.append("'");
	DEBUGS(&startMsg);
	
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);
	
	Record* keyRecord=new Record();
	keyRecord->addValue(new StringValue(cloneStr((((StringValue*)keyValue)->getString()))));
	keyRecord->addValue(new IntValue(blockNumber));
	
	try{
		string insertMsg;
		insertMsg.append("HASH Intentando insertar el registro '");
		keyRecord->toString(&insertMsg);
		insertMsg.append("' en el bucket número '");
		appendIntTo(&insertMsg,keysBlockNumber);
		insertMsg.append("'.");
		_keysfile->insertRecordAt(keysBlockNumber,keyRecord);
	}catch(ContentOverflowBlockException* ex){
		delete ex;
		DEBUG("HASH Overflow en el archivo de claves");
		
		string overflowMsg;
		DEBUG("HASH Agregando bucket vacio");
		KeysBlock* conflictiveBlock=(KeysBlock*)_keysfile->getRecordBlock(keysBlockNumber);
		KeysBlock* newBlock=(KeysBlock*)_keysfile->appendEmptyBlock();
		if (conflictiveBlock->getDispersion()==_hashtable->getSize()){
			_hashtable->grow();
		}
		conflictiveBlock->setDispersion(_hashtable->getSize());
		newBlock->setDispersion(_hashtable->getSize());
		_hashtable->update(getHashTablePosition(keyValue),_keysfile->getLastRecordsBlockIndex());
		this->reIndex(keysBlockNumber);
		this->index(keyValue,blockNumber);
	}catch(RecordSizeOverflowException* ex2){
		delete ex2;
		string exmessage;
		
		exmessage.append("HASH [ERROR] No se puede indexar el registro ");
		keyRecord->toString(&exmessage);
		exmessage.append(" porque su tamaño es mayor al de un bloque.");
		DEBUGS(&exmessage);		
	}
}

int HashIndex::getBlockNumber(DataValue* keyValue) {
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);

	string buffer;
	buffer.append("HASH Buscando numero de bloque de datos para la clave");
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
