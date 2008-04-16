#include "DataFile.h"
#include "string.h"

DataFile::DataFile(char* fileName){
	_fileName = cloneStr(fileName);
	_fullPath=NULL;
}

DataFile::DataFile(char* fileName, int blockSize, int fileType, int indexSize, int secondaryFieldsCount, vector<Field*>* secondaryFields, SecondaryIndex* secondaryIndex) {
	
	_fileName = cloneStr(fileName);
	_blockSize = blockSize;
	//Le seteo el MetadataBlock
	_metadataBlock = new MetadataBlock(blockSize);
	//_metadataBlock->setIndexSize(indexSize);
	_metadataBlock->setFileType(fileType);
	_metadataBlock->setSecondaryFields(secondaryFields);
}

DataFile::~DataFile() {
	//MATAAAAR
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
	
	//Cargo el blockStructureFile
	this->_blockStructuredFile = BlockStructuredFile::Load(this->_fullPath);
	//Cargo el MetadataBlock
	this->_metadataBlock = (MetadataBlock*)_blockStructuredFile->bGetContentBlock(DataFile::FIRSTBLOCK,&MetadataBlock::createMetadataBlock);
}

void DataFile::save(char* folderPath) {
	this->setFolder(folderPath);	
	
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
	RecordsBlock* recordsBlock = NULL;
	RawRecord* rawRecord = record->serialize();

	try {
		T_BLOCKCOUNT freeRecordBlockNumber = this->_blockStructuredFile->getFirstFreeContentBlockNumber(1,record->getSerializationFullSize(),&RecordsBlock::createRecordsBlock);
		recordsBlock = (RecordsBlock*)this->_blockStructuredFile->bGetContentBlock(freeRecordBlockNumber,&RecordsBlock::createRecordsBlock);
		recordsBlock->getRecords()->push_back(rawRecord);
		this->_blockStructuredFile->bUpdateContentBlock(freeRecordBlockNumber,recordsBlock);
	} catch(BlockNotFoundException*) {
		recordsBlock = new RecordsBlock(this->_blockSize);
		this->_blockStructuredFile->bAppendContentBlock(recordsBlock);
	}

}
