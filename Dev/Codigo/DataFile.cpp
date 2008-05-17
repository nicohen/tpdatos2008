#include "DataFile.h"
#include "Data/RecordsBlock.h"
#include "string.h"
#include <vector>
#include "IntType.h"
#include "Data/IdentityException.h"
#include "Data/TypeMismatchException.h"
#include "Utils.h"
#include "Data/FileNotFoundException.h"
#include "Data/FileDoesAlreadyExistsException.h"
#include "Data/ContentOverflowBlockException.h"
#include "Data/RecordSizeOverflowException.h"
#include "Data/BlockNotFoundException.h"
#include "Data/CannotUpdateRecordException.h"
#include "Data/RecordNotFoundException.h"

DataFile::DataFile(char* fileName){
	_fileName = cloneStr(fileName);
	_fullPath=NULL;
}


DataFile::DataFile(char* fileName, int blockSize, int fileType, int indexSize, int secondaryFieldsCount, vector<Field*>* secondaryFields, SecondaryIndex* secondaryIndex) {
	//ToDo: Desde afuera matar esto-->secondaryIndex	
	vector<Field*>* fields=new vector<Field*>();
	Field* primaryField=new Field();
	primaryField->setIsMandatory(true);
	primaryField->setIsPolyvalent(false);
	primaryField->setDataType(new IntType());
	fields->push_back(primaryField);
	
	Field* each=NULL;
	vector<Field*>::iterator iter;
	for (iter = secondaryFields->begin(); iter != secondaryFields->end(); iter++ ){
		each=((Field*)*iter);		
		fields->push_back(each);
	}
	
	_fileName = cloneStr(fileName);
	_blockSize = blockSize;
	_metadataBlock = new MetadataBlock(blockSize);
	_metadataBlock->setFileType(fileType);
	_metadataBlock->setSecondaryFields(fields);
	_blockFactory=new RecordsBlockFactory();
}

void DataFile::setBlocksBuffer(BlocksBuffer* blocksBuffer){
	_blocksBuffer=blocksBuffer;
}

Field* DataFile::getPrimaryField(){
	return (Field*)this->_metadataBlock->GetSecondaryFields()->at(0);	
}

vector<Field*>* DataFile::getFields(){
	return this->_metadataBlock->GetSecondaryFields();
}

DataFile::~DataFile() {
	//MATAAAAR
	//_metadataBlock
	if(this->_fullPath!=NULL){
		free(this->_fullPath);
	}
	delete _blockFactory;
}

void DataFile::setBlockStructuredFile(BlockStructuredFile* blockStructuredFile) {
	this->_blockStructuredFile = blockStructuredFile;
}

BlockStructuredFile* DataFile::getBlockStructuredFile() {
	return this->_blockStructuredFile;
}

char* DataFile::appendFolder(char* fileName, char* folderPath){
	string buffer;
	char* result;
	
	buffer.append(folderPath);
	buffer.append(fileName);
	
	result = (char*) malloc(strlen(buffer.c_str()));
	strcpy(result,buffer.c_str());
	return result;	
}

void DataFile::setFolder(char* folderPath){
	this->_fullPath=appendFolder(this->_fileName,folderPath);
}

void DataFile::load(char* folderPath){
	this->setFolder(folderPath);
	if(!existsFile(this->_fullPath)){
		throw new FileNotFoundException("Se intento cargar un archivo que no existe");
	}
	//Cargo el blockStructureFile
	this->_blockStructuredFile = BlockStructuredFile::Load(this->_fullPath);
	//Cargo el MetadataBlock
	this->_metadataBlock = (MetadataBlock*)_blockStructuredFile->bGetContentBlock(DataFile::FIRST_BLOCK,&_metadataBlockFactory);
}

void DataFile::save(char* folderPath) {
	this->setFolder(folderPath);	
	
	if(existsFile(this->_fullPath)){
		throw new FileDoesAlreadyExistsException("No se puede crear el archivo porque ya existe uno con el mismo nombre");
	}
	//Creo el blockStructureFile
	this->_blockStructuredFile = BlockStructuredFile::Create(this->_fullPath,_blockSize);
	//Guardo el MetadataBlock
	this->_blockStructuredFile->bAppendContentBlock(this->_metadataBlock);
}

char* DataFile::getFileName() {
	return this->_fullPath;
}

T_FILESIZE DataFile::getDataUsedSpace() {
	//recorrer todos los recordsblock y acumular el getUsedSpace-->implementa
	int usedSpace = 0;
	RecordsBlock* recordsBlock;
	
	for (int i=1; i <= this->_blockStructuredFile->getContentBlockCount()-1; i++) {
		recordsBlock = this->getRecordBlock(i);
		//recordsBlock = (RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(i,&(RecordsBlock::createRecordsBlock));
		usedSpace += recordsBlock->getUsedSpace();
	}
	
	return usedSpace;
}

T_FILESIZE DataFile::getDataFreeSpace() {
	//recorrer todos los recordsblock y acumular el getFreeSpace-->implementa
	int freeSpace = 0;
	RecordsBlock* recordsBlock;
	
	for (int i=1; i <= this->_blockStructuredFile->getContentBlockCount()-1; i++) {
		recordsBlock = this->getRecordBlock(i);
		//	(RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(i,&(RecordsBlock::createRecordsBlock));
		freeSpace += (recordsBlock->getSize() - recordsBlock->getUsedSpace());
	}
	
	return freeSpace;
}

T_BLOCKSIZE DataFile::getRecordsBlockCount(){
	return this->_blockStructuredFile->getContentBlockCount()-1;
}

vector<Record*>* DataFile::findRecords(int fNumber,DataValue* fValue){
	// obtener bloque por bloque
	// llenar cada RecordBlock con un bloque
	// devuelve un array de bytes
	// tengo que crear un record a partir de un array de bytes que devuelve el recordblock
	vector<Record*>* recordsObteined= new vector<Record*>();
	vector<Record*>* recordsFoundAt = NULL;
	RecordsBlock *rBlock;
	int length= this->getRecordsBlockCount();
	for(int j=1;j<=length;j++){
		rBlock=	this->getRecordBlock(j);
		recordsFoundAt = this->findRecordsAt(j,fNumber,fValue);
		vector<Record*>::iterator iter;
		for (iter = recordsFoundAt->begin(); iter != recordsFoundAt->end(); iter++ ) {
			recordsObteined->push_back(((Record*)*iter));
		}
	}
	
	if (recordsFoundAt!=NULL)
		delete recordsFoundAt;
	
	return recordsObteined;
}

vector<Record*>* DataFile::findRecordsAt(T_BLOCKCOUNT blockNumber, int fNumber,DataValue* fValue){
	// obtener directamente el bloque
	// llenar cada RecordBlock con un bloque
	// devuelve un array de bytes
	// tengo que crear un record a partir de un array de bytes que devuelve el recordblock
	vector<Record*>* recordsFound= new vector<Record*>();
	RecordsBlock *rBlock;

	try {
		rBlock=	this->getRecordBlock(blockNumber);
	} catch (BlockStructuredFileException* ex) {
		//Sale en el caso que no haya encontrado bloques
		delete ex;
		throw new BlockNotFoundException("No se ha encontrado Bloque dentro del archivo");
	}
	
	RawRecord* each=NULL;
	vector<RawRecord*>::iterator iter;
	for (iter = rBlock->begin(); iter != rBlock->end(); iter++ ){
		each=((RawRecord*)*iter);
		Record* record= new Record();
		record->deserialize(each,this->getFields());
		if(record->matchField(fNumber,fValue)){
			recordsFound->push_back(record);
		}else{
			delete record;
		}
	}
	
	return recordsFound;
}

vector<Record*>* DataFile::removeRecord(int fNumber,DataValue* fValue) {
	vector<Record*>* removedRecords = new vector<Record*>();
	vector<Record*>* removedRecordsAt;
	int length= this->getRecordsBlockCount();
	Record* each=NULL;
	
	for(int j=1;j<=length;j++) {
		removedRecordsAt = this->removeRecordAt(j,fNumber,fValue);
		vector<Record*>::iterator iter;
		for (iter = removedRecordsAt->begin(); iter != removedRecordsAt->end(); iter++ ){
			each = ((Record*)*iter);
			removedRecords->push_back(each);
		}
	}
	
	if (removedRecordsAt!=NULL) {
		delete removedRecordsAt;
	}
	return removedRecords;
}

vector<Record*>* DataFile::removeRecordAt(T_BLOCKCOUNT blockNumber, int fNumber, DataValue* fValue) throw (BlockNotFoundException*) {
	bool updateRecord=false;
	RecordsBlock *rBlock;
	vector<Record*>* removedRecords = new vector<Record*>();

	try {
		rBlock=	this->getRecordBlock(blockNumber);
	} catch (BlockStructuredFileException* ex) {
		//Sale en el caso que no haya encontrado bloques
		delete ex;
		throw new BlockNotFoundException("No se ha encontrado Bloque dentro del archivo");
	}
	
	RawRecord* each=NULL;
	vector<RawRecord*>::iterator iter;
	for (iter = rBlock->begin(); iter != rBlock->end(); iter++ ){
		each=((RawRecord*)*iter);
		Record* record= new Record();
		record->deserialize(each,this->getFields());
		if(record->matchField(fNumber,fValue)){
			removedRecords->push_back(record);
			rBlock->erase(iter);
			iter--;
			updateRecord=true;
		}
	}
	if (updateRecord){
		this->_blockStructuredFile->bUpdateContentBlock(blockNumber,rBlock);
		updateRecord=false;
	}
	return removedRecords;
}

/*
vector<Field*>* DataFile::getDataStructure(){
	return this->_metadataBlock->GetSecondaryFields();
}*/
	
T_BLOCKSIZE DataFile::getDataRecordsCount() {
	//recorrer todos los recordsblock y acumular el getFreeSpace-->implementa
	int recordsCount = 0;
	RecordsBlock* recordsBlock;
	
	for (int i=1; i <= this->_blockStructuredFile->getContentBlockCount()-1; i++) {
		recordsBlock =  this->getRecordBlock(i);
			//(RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(i,&(RecordsBlock::createRecordsBlock));
		recordsCount += recordsBlock->RecordCount();
	}
	
	return recordsCount;
}

T_FILESIZE DataFile::getFileSize() {
	return this->_blockStructuredFile->getFileSize();
}


bool DataFile::isArrayOf(vector<Field*>* fields, vector<DataValue*>* values){
	Field* aField;
	DataValue* aValue;
	vector<Field*>::iterator fieldIter;
	vector<DataValue*>::iterator valueIter;
	
	if(fields->size()!=values->size()){
		return false;
	}
		
	for(valueIter= values->begin(), fieldIter= fields->begin();
		valueIter< values->end() && fieldIter< fields->end();
		valueIter++, fieldIter++){
			aValue= (DataValue*)*valueIter;
			aField= (Field*)*fieldIter;
			if (aValue->isInstanceOf(aField->getDataType())==false){
				return false;
			}else{
				if(aField->isMandatory() && aValue->isNull()){
					return false;
				}
			}
	}
	if (fieldIter== fields->end()){
		if (valueIter != values->end()){
			return false;
		}
	}else{
		while (fieldIter!=fields->end()){
			aField= (Field*)*fieldIter;
			if (aField->isMandatory()==true){
				return false;
			}
			fieldIter++;
		}
	}
	return true;	
}

T_BLOCKCOUNT DataFile::getFirstRecordsBlockIndex(){
	return 1;
}
T_BLOCKCOUNT DataFile::getLastRecordsBlockIndex(){
	return this->_blockStructuredFile->getContentBlockCount()-1;
}

bool DataFile::existsAnotherWithSameKey(Record* record){
	bool res=false;
	vector<Record*>* sameKeyRecordsfound = this->findRecords(0,(DataValue*)record->getValues()->at(0));
	if(sameKeyRecordsfound->size()>0){
		res=true;
	}
	delete sameKeyRecordsfound;
	return res;
}
void DataFile::appendEmptyBlock(){
	RecordsBlock* recordsBlock = new RecordsBlock(this->_blockStructuredFile->getBlockSize());
	this->_blockStructuredFile->bAppendContentBlock(recordsBlock);
	this->_blocksBuffer->addBlock(this->getFileName(),this->getLastRecordsBlockIndex(),recordsBlock);
}


int DataFile::insertRecord(Record* record) {
	string str;
	if(this->existsAnotherWithSameKey(record)){
		throw new IdentityException("Ya existe un registro con la misma clave que el que se quiere insertar");
	}	
	if (this->isArrayOf(this->_metadataBlock->GetSecondaryFields(),record->getValues())==false){
		throw new TypeMismatchException("Los datos ingresados no coinciden con la estructura del Archivo");
	}	
	for (T_BLOCKCOUNT i=this->getFirstRecordsBlockIndex();i <=this->getLastRecordsBlockIndex(); i++) {
		try{
			this->insertRecordAt(i,record);
			return i;//Si no hay excepcion es porque lo insertó bien, por lo tanto termina el metodo.
		}catch(ContentOverflowBlockException* ex1){
			delete ex1;
		}
	}
	try{
		this->appendEmptyBlock();		
		this->insertRecordAt(this->getLastRecordsBlockIndex(),record);
		return this->getLastRecordsBlockIndex();
	}catch(ContentOverflowBlockException* ex2){
		delete ex2;
		throw new RecordSizeOverflowException();
	}
}

void DataFile::insertRecordAt(T_BLOCKCOUNT blockNumber,Record* record){
	RecordsBlock* recordsBlock = NULL;
	RawRecord* rawRecord =NULL;
	try{
		rawRecord = record->serialize();
		recordsBlock = this->getRecordBlock(blockNumber);
		recordsBlock->push_back(rawRecord);
		this->_blockStructuredFile->bUpdateContentBlock(blockNumber,recordsBlock);
	}catch(ContentOverflowBlockException* ex){
		delete rawRecord;
		throw ex;
	}
}

RecordsBlock* DataFile::getRecordBlock(int blockNumber){
	Block* result= this->_blocksBuffer->getBlock(this->getFileName(),blockNumber);	
	if (result==NULL){
		result= this->getBlockStructuredFile()->bGetContentBlock(blockNumber,this->getBlockFactory());
		this->_blocksBuffer->addBlock(this->getFileName(),blockNumber,result);
	}
	return (RecordsBlock*)result;
}

bool DataFile::updateRecord(Record* myRecord) {
	if (this->canInsert(myRecord)) {
		int length= this->getRecordsBlockCount();
		
		for(int j=1;j<=length;j++) {
			try {
				this->updateRecordAt(j,myRecord);
				return true;
			} catch (CannotUpdateRecordException* ex1) {
				delete ex1;
				this->removeRecordAt(j,0,myRecord->getValues()->at(0));
				this->insertRecord(myRecord);
				return true;
			} catch (RecordNotFoundException* ex2) {
				delete ex2;
			}
		}
	}
	return false;
}

bool DataFile::updateRecordAt(T_BLOCKCOUNT blockNumber,Record* myRecord) {
	vector<Record*>* recordsFound = this->findRecordsAt(blockNumber,0,myRecord->getValues()->at(0));
	
	Record* recordToUpdate = NULL;
	if (recordsFound->size()==1) {
		recordToUpdate = recordsFound->at(0);
		if (this->getRecordBlock(blockNumber)->canUpdate(recordToUpdate->serialize(),myRecord->serialize())) {
			if(this->removeRecordAt(blockNumber,0,myRecord->getValues()->at(0))->size()<0){
				return false;
			} else {
				this->insertRecordAt(blockNumber,myRecord);
				return true;
			}
		} else {
			throw new CannotUpdateRecordException();
		}
	} else {
		throw new RecordNotFoundException();
	}
}

T_BLOCKSIZE DataFile::getSize(){
	return 1;
}

BlockFactory* DataFile::getBlockFactory(){
	return this->_blockFactory;
}

void DataFile::setBlockFactory(BlockFactory* blockFactory){
	delete this->_blockFactory;
	this->_blockFactory=blockFactory;
}
bool DataFile::canInsert(Record* record) {
	return this->getRecordBlock(0)->canInsert(record->serialize());
}
