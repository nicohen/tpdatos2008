#include "HashIndex.h"
#include <string.h>
#include "../Utils.h"
#include "../Data/ContentOverflowBlockException.h"
#include "../Data/RecordSizeOverflowException.h"
#include "../IntValue.h"
#include "../Data/RecordNotFoundException.h"
#include "../Field.h"
#include <vector>

HashIndex::HashIndex(T_BLOCKSIZE indexBlockSize, DataType* keyType) {
	_keyType=keyType;
	_indexBlockSize=indexBlockSize;
}

HashIndex::~HashIndex() {
	delete _keysfile;
	delete _dispersionfile;
	delete _hashtable;
}

void HashIndex::create(char* folderPath, char* filePath) {
	string keysFileName;
	string hashFileFullPath;
	string dispersionFileFullPath;
	string fullpath;

	fullpath.append(folderPath);
	fullpath.append(filePath);

	keysFileName.append(filePath);
	keysFileName.append(".keys");

	hashFileFullPath.append(fullpath);
	hashFileFullPath.append(".hash");
	
	dispersionFileFullPath.append(fullpath);
	dispersionFileFullPath.append(".disp");

	vector<Field*>* fields=new vector<Field*>();

	Field* keyField = new Field();
	Field* secondaryField1 = new Field();

	keyField->setDataType(_keyType);
	secondaryField1->setDataType(new IntType());

	//fields->push_back(keyField);
	fields->push_back(secondaryField1);

	_keysfile=new DataFile((char*)keysFileName.c_str(),_indexBlockSize,keyField,fields,NULL);
//	_keysfile->setBlockFactory(new KeysBlockFactory());
	_keysfile->save(folderPath);
 
	_hashtable=new HashTable((char*)"HASH TABLE ");
	_hashtable->create((char*)hashFileFullPath.c_str(), 1);
	_hashtable->update(0, 1);
	
	_dispersionfile=new HashTable((char*)"DISPERSION TABLE ");
	_dispersionfile->create((char*)dispersionFileFullPath.c_str(), 1);
	_dispersionfile->update(0, 1);
}

void HashIndex::deleTe() {
	_keysfile->deleTe();
	_hashtable->deleTe();
	_dispersionfile->deleTe();
}

void HashIndex::load(char* folderPath, char* filePath) {
	string keysFileName;
	string hashFileFullPath;
	string dispersionFileFullPath;
	string fullpath;

	fullpath.append(folderPath);
	fullpath.append(filePath);

	keysFileName.append(filePath);
	keysFileName.append(".keys");

	hashFileFullPath.append(fullpath);
	hashFileFullPath.append(".hash");
	
	dispersionFileFullPath.append(fullpath);
	dispersionFileFullPath.append(".disp");

	_keysfile=new DataFile((char*)keysFileName.c_str());
	_keysfile->setBlockFactory(new RecordsBlockFactory());
	_keysfile->load(folderPath);
	this->_keyType= _keysfile->getFields()->at(0)->getDataType();

	_indexBlockSize= _keysfile->getBlockStructuredFile()->getBlockSize();

	_hashtable=new HashTable((char*)"HASH TABLE ");
	_hashtable->load((char*)hashFileFullPath.c_str());
	
	_dispersionfile=new HashTable((char*)"DISPERSION TABLE ");
	_dispersionfile->load((char*)dispersionFileFullPath.c_str());
}

void HashIndex::unIndex(DataValue* keyValue) {
	string buffer;
	buffer.append("HASH Desindexando clave ");
	keyValue->toString(&buffer);
	DEBUGS(&buffer);
	
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);
	string debugMartes1;
	this->toString(&debugMartes1);
	DEBUGS(&debugMartes1);

	_keysfile->removeRecordAt(keysBlockNumber, 0, keyValue);

	string debugMartes2;
	this->toString(&debugMartes2);
	DEBUGS(&debugMartes2);

	if (_keysfile->getRecordBlock(keysBlockNumber)->getRecords()->size() == 0) {
		this->simplify(keysBlockNumber, keyValue);
		
		string debugMartes3;
		this->toString(&debugMartes3);
		DEBUGS(&debugMartes3);

	}
}

void HashIndex::simplify(int emptyKeysBlockNumber, DataValue* keyValue) {
	if (_hashtable->getSize()==1) {
		return;
	}

	int deltaDispersion = _dispersionfile->getAt(emptyKeysBlockNumber-1) / 2;
	int hashTablePosition = getHashTablePosition(keyValue);
	
	int upperHashTablePosition = (hashTablePosition+deltaDispersion)%_hashtable->getSize(); 
	int lowerHashTablePosition = (hashTablePosition-deltaDispersion)%_hashtable->getSize();
	int upperKeysBlockNumber = _hashtable->getAt(upperHashTablePosition); 
	int lowerKeysBlockNumber = _hashtable->getAt(lowerHashTablePosition);

	//Verificar si esta igualdad es correcta
	if (_dispersionfile->getAt(upperKeysBlockNumber-1)==_dispersionfile->getAt(lowerKeysBlockNumber-1)) {

		int newKeyBlockNumber= (emptyKeysBlockNumber==lowerKeysBlockNumber)?upperKeysBlockNumber:lowerKeysBlockNumber;
		_hashtable->update(hashTablePosition,newKeyBlockNumber);

		//Recorro la hashtable desde la posicion X=emptyKeysBlockNumber-1 de a saltos 
		//dispersion(X) y le asigno lowerKeysBlockNumber
		int steps = _dispersionfile->getAt(emptyKeysBlockNumber-1);
		int current = hashTablePosition;
		for (int i = 0;i<(_hashtable->getSize()/steps);i++){
			current = current % _hashtable->getSize();
			_hashtable->update(current,newKeyBlockNumber);
			current = current + steps;					
		}
		_dispersionfile->update(emptyKeysBlockNumber-1,_dispersionfile->getAt(emptyKeysBlockNumber-1) / 2);
		_dispersionfile->update(newKeyBlockNumber-1,_dispersionfile->getAt(newKeyBlockNumber-1) / 2);

		//Si las dos mitades de la hashtable son iguales, trunco la hashtable a la mitad
		recursivelyShrink();
	}
	truncateKeysFileIfPossible();
}

void HashIndex::recursivelyShrink(void){
	int distance= _hashtable->getSize()/2;
	int i=0;
	bool equals= true;
	while (i<distance && equals) {
		if (_hashtable->getAt(i)!=_hashtable->getAt(distance+i)) {
			equals= false;
		}
		i++;
	}
	if (_hashtable->getSize()==1) {
		equals= false;
	}
	if(equals){
		_hashtable->simplify();
		this->recursivelyShrink();
	}
}

void HashIndex::update(DataValue* keyValue, int blockNumber) {
	string buffer;
	buffer.append("HASH Actualizando clave '");
	keyValue->toString(&buffer);
	buffer.append("'... Nuevo numero de bloque de datos ");
	appendIntTo(&buffer, blockNumber);
	DEBUGS(&buffer);

	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);

	Record* keyRecord=new Record();
	keyRecord->addValue(keyValue->clone());
	keyRecord->addValue(new IntValue(blockNumber));

	_keysfile->updateRecordAt(keysBlockNumber, keyRecord);
}

unsigned int HashIndex::getHash(DataValue* input) {
	string inputString;
	input->toString(&inputString);
	string cubihashdebug;
	cubihashdebug.append("-->TEST_CUBI_HASH: ");
	cubihashdebug.append((char*)inputString.c_str());
	input->toString(&cubihashdebug);
	unsigned int hashResult= RSHash((char*)inputString.c_str());
	cubihashdebug.append(", ");
	appendIntTo(&cubihashdebug,hashResult);
	DEBUGS(&cubihashdebug);
	return hashResult;
}

unsigned int HashIndex::RSHash(char* input) {
	unsigned int b = 378551;
	unsigned int a = 63689;
	unsigned int hash = 0;

	for (size_t i = 0; i < strlen(input); i++) {
		hash = hash * a + input[i];
		a = a * b;
	}

	return hash;
}

void HashIndex::reIndex(int keysBlockNumber) {
	vector<Record*>* erasedRecords = _keysfile->removeRecordsAt(keysBlockNumber);

	string buffer;
	buffer.append("HASH Reindexando el bucket número ");
	appendIntTo(&buffer, keysBlockNumber);
	DEBUGS(&buffer);

	Record* each=NULL;
	vector<Record*>::iterator iter;
	for (iter = erasedRecords->begin(); iter != erasedRecords->end(); iter++) {
		each=((Record*)*iter);
		index(each->getValues()->at(0), ((IntValue*)each->getValues()->at(1))->getInt());
	}
	//	DEBUG("HASH: Fin de reindexacion de registros");
}

unsigned int HashIndex::getHashTablePosition(DataValue* keyValue) {
	string buffer;
	buffer.append("HASH buscando posicion en la tabla para la clave ");
	keyValue->toString(&buffer);
	int hashsize= _hashtable->getSize();
	unsigned int hash=getHash(keyValue);
	unsigned int hashTablePos = hash % hashsize;
	buffer.append(" ... Posición obtenida ");
	appendIntTo(&buffer, hashTablePos);
	DEBUGS(&buffer);
	return hashTablePos;
}

int HashIndex::getKeysFileBlockNumberFor(DataValue* keyValue) {
	string buffer;
	buffer.append("HASH buscando numero de bucket para la clave ");
	keyValue->toString(&buffer);
	int blockNumber = _hashtable->getAt(getHashTablePosition(keyValue));
	buffer.append("' ... Numero de bucket obtenido: ");
	appendIntTo(&buffer, blockNumber);
	DEBUGS(&buffer);
	return blockNumber;
}

void HashIndex::index(DataValue* keyValue, int blockNumber) {
	string startMsg;
	startMsg.append("HASH Indexando la clave ");
	keyValue->toString(&startMsg);
	startMsg.append(" asociada al bloque de datos número ");
	appendIntTo(&startMsg, blockNumber);
	DEBUGS(&startMsg);
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);

	Record* keyRecord=new Record();
	keyRecord->addValue(keyValue->clone());
	keyRecord->addValue(new IntValue(blockNumber));

	try {
		string insertMsg;
		insertMsg.append("HASH Intentando insertar el registro ");
		keyRecord->toString(&insertMsg);
		insertMsg.append(" en el bucket número ");
		appendIntTo(&insertMsg,keysBlockNumber);
		insertMsg.append(".");
		
		string debugMartes1;
		//this->_keysfile->toString(&debugMartes);
		this->toString(&debugMartes1);
		DEBUGS(&debugMartes1);

		_keysfile->insertRecordAt(keysBlockNumber,keyRecord);
		
		string debugMartes2;
		//this->_keysfile->toString(&debugMartes);
		this->toString(&debugMartes2);
		DEBUGS(&debugMartes2);

	} catch(ContentOverflowBlockException* ex) {		
		delete ex;
		
		string overflowMsg;
		overflowMsg.append("HASH Overflow en el bucket número ");
		appendIntTo(&overflowMsg,keysBlockNumber);
		overflowMsg.append(". Agregando bucket vacio.");
		DEBUGS(&overflowMsg);
		int hashTablePosition = getHashTablePosition(keyValue);
		
		//duplica la dispersion del bucket confilctivo y el nuevo
		int dispersionOriginal = _dispersionfile->getAt(keysBlockNumber-1);
		int newDispersion = 2*dispersionOriginal;

		//Crea nuevo bucket vacio
		//TODO - En vez de appendear, fijarse si existe algun bloque libre y no referenciado
		this->appendBucket(newDispersion);
		
		if (dispersionOriginal>=_hashtable->getSize()) {
			_hashtable->grow();
			
		}
	//		_hashtable->update((hashTablePosition+_hashtable->getSize()/2)%_hashtable->getSize(),_keysfile->getLastRecordsBlockIndex());
		_hashtable->update(hashTablePosition,_keysfile->getLastRecordsBlockIndex());
		//duplica la dispersion del bucket confilctivo y el nuevo
		updateDispersion(keysBlockNumber,newDispersion);
		
		// REVISAR ESTA COMPARACION!!!
		//VERIFICAS SI HAY QUE DUPLICAR LA TABLA
		string verifica;
		verifica.append("---->HASH verifica si hay que duplicar la tabla, dispersion: ");
		appendIntTo(&verifica,_dispersionfile->getAt(keysBlockNumber-1));
		verifica.append("tamaño de hashtable: ");
		appendIntTo(&verifica,_hashtable->getSize());
		DEBUGS(&verifica);

		if (dispersionOriginal>_hashtable->getSize()) {
			int steps= _hashtable->getSize()/newDispersion;
			int current= hashTablePosition;
			for (int i= 0;i<steps;i++){
				current=current%_hashtable->getSize();
				_hashtable->update(current,_keysfile->getLastRecordsBlockIndex());
				current=current+newDispersion;					
			}
		}
		
		//_dispersionfile->update(this->_keysfile->getLastRecordsBlockIndex()-1,newDispersion);
		
		//_hashtable->update(getHashTablePosition(keyValue),_keysfile->getLastRecordsBlockIndex());
		this->reIndex(keysBlockNumber);
		this->index(keyValue,blockNumber);
		
		string debugMartes;
		//this->_keysfile->toString(&debugMartes);
		this->toString(&debugMartes);
		DEBUGS(&debugMartes);

		
	} catch(RecordSizeOverflowException* ex2) {
//		delete ex2;
		string exmessage;

		exmessage.append("HASH [ERROR] No se puede indexar el registro ");
		keyRecord->toString(&exmessage);
		exmessage.append(" porque su tamaño es mayor al de un bloque.");
		DEBUGS(&exmessage);
		throw ex2;
	}
}

int HashIndex::getBlockNumber(DataValue* keyValue) {
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);

	string buffer;
	buffer.append("HASH Buscando numero de bloque de datos para la clave");
	keyValue->toString(&buffer);
	DEBUGS(&buffer);

	vector<Record*>* recordsFound = _keysfile->findRecordsAt(keysBlockNumber, 0,
			keyValue);
	if (recordsFound->size()==0) {
		throw new RecordNotFoundException();
	}

	return ((IntValue*)recordsFound->at(0)->getValues()->at(1))->getInt();
}

void HashIndex::setBlocksBuffer(BlocksBuffer* blocksBuffer) {
	_keysfile->setBlocksBuffer(blocksBuffer);
	if (_keysfile->getRecordsBlockCount()==0) {
		_keysfile->appendEmptyBlock();
	}
}


void HashIndex::toString(string* buffer) {
	this->_keysfile->toString(buffer);
	buffer->append("\n TABLA DE DISPERSIONES \n");
	this->_dispersionfile->toString(buffer);
	buffer->append("\n HASHTABLE \n");
	this->_hashtable->toString(buffer);
}

int HashIndex::getSize() {
	return (this->_keysfile->getDataUsedSpace()+this->_hashtable->getPhysicalSize());
}

void HashIndex::appendBucket(int dispersion){
	_keysfile->appendEmptyBlock();
	_dispersionfile->append(dispersion);
}

void HashIndex::removeLastBucket(){
	_keysfile->truncateLast();
	_dispersionfile->removeLast();
}

int HashIndex::getDispersion(int blockNumber){
	return _dispersionfile->getAt(blockNumber-1);
}

void HashIndex::updateDispersion(int blockNumber, int withValue){
	_dispersionfile->update(blockNumber-1,withValue);
}

void HashIndex::updateHashTableCyclicaly(int startingPosition,int step,int updateWith){
	int stepCount= _hashtable->getSize()/step;
	int current= startingPosition;
	for (int i= 0;i<stepCount;i++){
		current=current%_hashtable->getSize();
		_hashtable->update(current,updateWith);
		current=current+step;				
	}
}

void HashIndex::truncateKeysFileIfPossible(){
	int maxBlockNumber = this->getGreatestReferencedKeyBlockNumber();
	this->_keysfile->truncateBlocks(maxBlockNumber);
}

int HashIndex::getGreatestReferencedKeyBlockNumber(){
	int max=0;
	for(int i=0;i<=this->_hashtable->getSize();i++){
		int current=this->_hashtable->getAt(i);
		if(current>max){
			max=current;
		}
	}
	return max;
}

