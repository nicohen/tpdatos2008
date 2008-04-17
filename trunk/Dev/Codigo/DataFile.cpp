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
	this->_metadataBlock = (MetadataBlock*)_blockStructuredFile->bGetContentBlock(DataFile::FIRST_BLOCK,&MetadataBlock::createMetadataBlock);
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
	return this->_fileName;
}

T_FILESIZE DataFile::getDataUsedSpace() {
	//recorrer todos los recordsblock y acumular el getUsedSpace-->implementa
	int usedSpace = 0;
	RecordsBlock* recordsBlock;
	
	for (int i=1; i <= this->_blockStructuredFile->getContentBlockCount()-1; i++) {
		recordsBlock = (RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(i,&(RecordsBlock::createRecordsBlock));
		usedSpace += recordsBlock->getUsedSpace();
	}
	
	return usedSpace;
}

T_FILESIZE DataFile::getDataFreeSpace() {
	//recorrer todos los recordsblock y acumular el getFreeSpace-->implementa
	int freeSpace = 0;
	RecordsBlock* recordsBlock;
	
	for (int i=1; i <= this->_blockStructuredFile->getContentBlockCount()-1; i++) {
		recordsBlock = (RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(i,&(RecordsBlock::createRecordsBlock));
		freeSpace += recordsBlock->getFreeSpace();
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
	RecordsBlock *rBlock;
	int length= this->getRecordsBlockCount();
	for(int j=1;j<=length;j++){
		rBlock=	this->getRecordBlock(j);
		vector<RawRecord*>* recordsList= rBlock->getRecords();
		RawRecord* each=NULL;
		vector<RawRecord*>::iterator iter;
		for (iter = recordsList->begin(); iter != recordsList->end(); iter++ ){
			each=((RawRecord*)*iter);
			Record* record= new Record();
			record->deserialize(each,this->getFields());
			if(record->matchField(fNumber,fValue)){
				recordsObteined->push_back(record);
			}else{
				delete record;
			}
		}		
	}
	return recordsObteined;
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
		recordsBlock = (RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(i,&(RecordsBlock::createRecordsBlock));
		recordsCount += recordsBlock->getRecords()->size();
	}
	
	return recordsCount;
}

T_FILESIZE DataFile::getFileSize() {
	return this->_blockStructuredFile->getFileSize();
}

void DataFile::insertRecord(Record* record) {
	
	vector<Record*>* sameKeyRecordsfound = this->findRecords(0,(DataValue*)record->getValues()->at(0));
	if(sameKeyRecordsfound->size()>0){
		delete sameKeyRecordsfound;
		throw new IdentityException("Ya existe un registro con la misma clave que el que se quiere insertar");
	}
	delete sameKeyRecordsfound;
	
	vector<DataValue*>*	recordValues= record->getValues();
	vector<DataValue*>::iterator recordIter;
	DataValue* aValue;
	vector<Field*>* fileFields= this->_metadataBlock->GetSecondaryFields();
	vector<Field*>::iterator fieldIter;
	Field* aField;
	for(recordIter= recordValues->begin(), fieldIter= fileFields->begin();
		recordIter< recordValues->end() && fieldIter< fileFields->end();
		recordIter++, fieldIter++){
			aValue= (DataValue*)*recordIter;
			aField= (Field*)*fieldIter;
			string* buffer= new string();
			aValue->toString(buffer);
			delete buffer;
			if (aField->getDataType()->equals(aValue->getType())==false){
				throw new TypeMismatchException("Los datos ingresados no coinciden con la estructura del Archivo");
			}
	}
	RecordsBlock* recordsBlock = NULL;
	RawRecord* rawRecord = record->serialize();
	try {
		T_BLOCKCOUNT freeRecordBlockNumber = this->_blockStructuredFile->getFirstFreeContentBlockNumber(1,record->getSerializationFullSize(),&RecordsBlock::createRecordsBlock);
		recordsBlock = (RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(freeRecordBlockNumber,&RecordsBlock::createRecordsBlock);
		recordsBlock->getRecords()->push_back(rawRecord);
		this->_blockStructuredFile->bUpdateContentBlock(freeRecordBlockNumber,recordsBlock);		
	} catch(BlockNotFoundException* ex) {
		recordsBlock = new RecordsBlock(this->_blockStructuredFile->getBlockSize());
		recordsBlock->getRecords()->push_back(rawRecord);
		this->_blockStructuredFile->bAppendContentBlock(recordsBlock);
		delete ex;
	}
}

RecordsBlock* DataFile::getRecordBlock(int blockNumber){
	//VALIDAR SI EXISTE ESE NUMERO DE BLOCKE
	//POR NAHUE
	return (RecordsBlock*)this->getBlockStructuredFile()->bGetContentBlock(blockNumber,&RecordsBlock::createRecordsBlock);
}

bool DataFile::updateRecord(Record* myRecord) {
	bool found = false;

//	vector<Record*>* recordsObteined= new vector<Record*>();
	RecordsBlock *rBlock;
	int length= this->getRecordsBlockCount();
	for(int j=1;j<=length;j++){
		rBlock=	this->getRecordBlock(j);
		vector<RawRecord*>* recordsList = rBlock->getRecords();
		RawRecord* each=NULL;
		vector<RawRecord*>::iterator iter;
		for (iter = recordsList->begin(); iter != recordsList->end(); iter++ ){
			each=((RawRecord*)*iter);
			Record* recordToMatch = new Record();
			recordToMatch->deserialize(each,this->getFields());
			if(recordToMatch->matchField(0,myRecord->getValues()->at(0))){
				RawRecord* myRawRecord = myRecord->serialize();
				recordsList->erase(iter);
				recordsList->push_back(myRawRecord);
				this->_blockStructuredFile->bUpdateContentBlock(j,rBlock);
				found = true;
				break;
			}
		}		
		if (found)
			break;
	}
	return found;
}
