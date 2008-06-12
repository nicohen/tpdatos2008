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

	_hashtable=new HashTable();
	_hashtable->create((char*)hashFileFullPath.c_str(), 1);
	_hashtable->update(0, 1);
	
	_dispersionfile=new HashTable();
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

	_hashtable=new HashTable();
	_hashtable->load((char*)hashFileFullPath.c_str());
	
	_dispersionfile=new HashTable();
	_dispersionfile->load((char*)dispersionFileFullPath.c_str());
}

void HashIndex::unIndex(DataValue* keyValue) {
	string buffer;
	buffer.append("HASH Desindexando clave ");
	keyValue->toString(&buffer);
	DEBUGS(&buffer);
	string debugMartes;
	//this->_keysfile->toString(&debugMartes);
	this->toString(&debugMartes);
	DEBUGS(&debugMartes);
	int keysBlockNumber= getKeysFileBlockNumberFor(keyValue);
	_keysfile->removeRecordAt(keysBlockNumber, 0, keyValue);
	if (_keysfile->getRecordBlock(keysBlockNumber)->getRecords()->size() == 0) {
		this->simplify(keysBlockNumber, keyValue);
	}
}

void HashIndex::simplify(int keysBlockNumber, DataValue* keyValue) {
	int deltaDispersion = _dispersionfile->getAt(keysBlockNumber-1) / 2;
	int hashTablePosition = getHashTablePosition(keyValue);
	
	int upperHashTablePosition = (_hashtable->getSize()+deltaDispersion)%_hashtable->getSize(); 
	int lowerHashTablePosition = (_hashtable->getSize()-deltaDispersion)%_hashtable->getSize();
	
	//Verificar si esta igualdad es correcta
	if (_hashtable->getAt(upperHashTablePosition)==_hashtable->getAt(lowerHashTablePosition)) {
		
		int newDispersion = _hashtable->getAt(lowerHashTablePosition);
		_hashtable->update(hashTablePosition,newDispersion);

		int steps = _dispersionfile->getAt(keysBlockNumber-1);
		int current = hashTablePosition;
		for (int i = 0;i<(_hashtable->getSize()/steps);i++){
			current = current % _hashtable->getSize();
			_hashtable->update(current,newDispersion);
			current = current + steps;					
		}
		
		_dispersionfile->update(keysBlockNumber,_dispersionfile->getAt(keysBlockNumber-1) / 2);
		
		int distance= _hashtable->getSize()/2;
		int i=0;
		int other= (keysBlockNumber+distance)%_hashtable->getSize();
		while (i<distance) {
			if ((i!=keysBlockNumber)&&(i!=other)&&(_hashtable->getAt(i)!=_hashtable->getAt(distance+i))) {
				return;
			}
			i++;
		}
		
		_hashtable->simplify();				
	}

	


//	if (_hashtable->getSize()==1){
//		return;
//	}
//	int distance= _hashtable->getSize()/2;
//	int i=0;
//	int other= (arg0+distance)%_hashtable->getSize();
//	while (i<distance) {
//		if ((i!=arg0)&&(i!=other)&&(_hashtable->getAt(i)!=_hashtable->getAt(distance+i))) {
//			return;
//		}
//		i++;
//	}
//	if (i==distance) {
//		string buffer;
//		buffer.append("HASH Simplificando la tabla de hash.\n");
//		buffer.append("HASH Tamaño anterior: ");
//		appendIntTo(&buffer,_hashtable->getSize());
//		int lower=_hashtable->getAt(arg0);
//		int hier=_hashtable->getAt(arg0+distance);
//		int block1= _hashtable->getAt(arg0);
//		int block2= _hashtable->getAt(other);
//		_dispersionfile->update(block1-1,(_dispersionfile->getAt(block1-1)/2));
//		_dispersionfile->update(block2-1,(_dispersionfile->getAt(block2-1)/2));
//		_hashtable->simplify();
//		buffer.append(". Tamaño nuevo: ");
//		appendIntTo(&buffer,_hashtable->getSize());
//		buffer.append("\n");
//		DEBUGS(&buffer);
//		_hashtable->update(arg0,(lower<hier)?lower:hier);
//		
//		this->reIndex(arg0);
//		this->reIndex(arg0+distance);
//	}
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
		
		//Crea nuevo bucket vacio
		//TODO - En vez de appendear, fijarse si existe algun bloque libre y no referenciado
		_keysfile->appendEmptyBlock();
		
		int dispersionOriginal = _dispersionfile->getAt(keysBlockNumber-1);
		
		if (dispersionOriginal<=_hashtable->getSize()) {
			_hashtable->grow();
			_hashtable->update(hashTablePosition,_keysfile->getLastRecordsBlockIndex());
		}
		
		//duplica la dispersion del bucket confilctivo y el nuevo
		int newDispersion = 2*dispersionOriginal;
		_dispersionfile->update(keysBlockNumber-1,newDispersion);
		_dispersionfile->append(newDispersion);
		
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
				_hashtable->update(current,newDispersion);
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

void HashIndex::appendBlock(int dispersion){
	
}