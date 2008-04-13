#include "DataFile.h"

DataFile::DataFile(char* fileName, int blockSize, int fileType, int indexSize, int secondaryFieldsCount, vector<Field*>* secondaryFields, SecondaryIndex* secondaryIndex) {
	_fileName = cloneStr(fileName);
	_blockSize = blockSize;

	//Le seteo el BlockStructuredFile
	_blockStructuredFile = new BlockStructuredFile(fileName);
	
	//Le seteo el MetadataBlock
	_metadataBlock = new MetadataBlock();
	_metadataBlock->setIndexSize(indexSize);
	_metadataBlock->setFileType(fileType);
	_metadataBlock->setSecondaryFields(secondaryFields);
	_metadataBlock->setQtyFields(secondaryFieldsCount);
}

DataFile::~DataFile() {}

void DataFile::setBlockStructuredFile(BlockStructuredFile* blockStructuredFile) {
	this->_blockStructuredFile = blockStructuredFile;
}

BlockStructuredFile* DataFile::getBlockStructuredFile() {
	return this->_blockStructuredFile;
}

void DataFile::create() {
	static int FIRSTBLOCK = 0;
	this->_blockStructuredFile->Create(this->getFileName(),this->getBlockSize());
	this->_blockStructuredFile->updateContentBlock(FIRSTBLOCK,this->_metadataBlock->serialize());
}

char* DataFile::getFileName() {
	return this->_fileName;
}

int DataFile::getBlockSize() {
	return this->_blockSize;
}

//FileDefinition* getFile(char* fileName) {
//	
//}
//
//void removeFile(char* fileName) {
//	
//}
