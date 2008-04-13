#include "MetadataBlock.h"

MetadataBlock::MetadataBlock(void) {

}

void clearMetadataBlock(vector<Field*>* fields) {
	vector<Field*>::iterator iter;
	for (iter = fields->begin(); iter != fields->end(); iter++ ) {
		delete ((Field*)*iter);
	}
	fields->clear();
}

MetadataBlock::~MetadataBlock() {
	clearMetadataBlock(this->_fields);
	delete(this->_fields);
}

char* MetadataBlock::serialize() {
	char* cadena;
	int valor = 1;
	cadena = (char*) malloc(sizeof(char));
	cadena = (char*)valor;
//	printf("%c",cadena);	
	return cadena;
}

int MetadataBlock::getIndexSize() {
	return this->_indexSize;
}

void MetadataBlock::setIndexSize(int indexSize) {
	this->_indexSize = indexSize;
}

int MetadataBlock::getFileType() {
	return this->_fileType;
}

void MetadataBlock::setFileType(int fileType) {
	this->_fileType = fileType;
}

int MetadataBlock::getQtyFields() {
	return this->_fields->size();
}

void MetadataBlock::setQtyFields(int qtyFields) {
	this->_qtyFields = qtyFields;
}

void MetadataBlock::setSecondaryField(Field* field) {
	this->_fields->push_back(field);
}

void MetadataBlock::setSecondaryFields(vector<Field*>* fields) {
	this->_fields = fields;
}
