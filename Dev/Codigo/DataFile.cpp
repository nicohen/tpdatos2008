#include "DataFile.h"

DataFile::DataFile(char* fileName) {
	_metadataBlock = new MetadataBlock();
	_fileName = cloneStr(fileName);
}

DataFile::~DataFile() {
	
}

void DataFile::setBlockStructuredFile(BlockStructuredFile* blockStructuredFile) {
	this->_blockStructuredFile = blockStructuredFile;
}

BlockStructuredFile* DataFile::getBlockStructuredFile() {
	return this->_blockStructuredFile;
}

//void addFile(FileDefinition* file) {
//	
//}
//
//FileDefinition* getFile(char* fileName) {
//	
//}
//
//void removeFile(char* fileName) {
//	
//}
