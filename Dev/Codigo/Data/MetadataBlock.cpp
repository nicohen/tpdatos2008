#include "MetadataBlock.h"
#include "../Statement.h"

MetadataBlock::MetadataBlock(T_BLOCKSIZE size): Block(size) {
	_fileType=Statement::OTHER;
	_fields= new vector<Field*>();
}
MetadataBlock::MetadataBlock(char* content,T_BLOCKSIZE size): Block(content,size){
	setContent(content);
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
/*
int MetadataBlock::getIndexSize() {
	return this->_indexSize;
}

void MetadataBlock::setIndexSize(int indexSize) {
	this->_indexSize = indexSize;
}
*/
int MetadataBlock::getFileType() {
	return this->_fileType;
}

void MetadataBlock::setFileType(int fileType) {
	this->_fileType = fileType;
}

int MetadataBlock::getQtyFields() {
	return this->_fields->size();
}

void MetadataBlock::setSecondaryField(Field* field) {
	this->_fields->push_back(field);
}

void MetadataBlock::setSecondaryFields(vector<Field*>* fields) {
	this->_fields = fields;
}
Field* MetadataBlock::parseField(char* content, int* offset){
	Field* field;
	unsigned short length;
	memcpy(&length,content+*offset,sizeof(short));
	*offset+=sizeof(short);
	char* byteCode= (char*)malloc(sizeof(char)*length);
	memcpy(byteCode,content+*offset,sizeof(char)*length);
	*offset+=sizeof(char)*length;
	field= new Field(byteCode);
	free(byteCode);	
	return field;
}
// IMPLEMENTAR ESTOS METODOS
void MetadataBlock::setContent(char* content){
	Block::setContent(content);
	int counter=0;
	unsigned short qtyField=0;
	memcpy(&(this->_fileType),content,sizeof(short));
	counter+=sizeof(short);
	memcpy(&qtyField,content+counter,sizeof(short));
	counter+=sizeof(short);
	for (int j=0;j<qtyField;j++){
		this->setSecondaryField(this->parseField(content,&counter));
	}
}

void MetadataBlock::setFragment(char* content,T_BLOCKSIZE offset,T_BLOCKSIZE size){
	Block::setFragment(content,offset,size);
}

void MetadataBlock::writeOnBlock(Field* field,Block* block,int* offset){
	T_BLOCKSIZE fieldSize;
	char* serializedField;
	fieldSize= field->serialize(&serializedField);
	block->setFragment((char*)&fieldSize,*offset,sizeof(T_BLOCKSIZE));
	*offset+=sizeof(T_BLOCKSIZE);
	block->setFragment(serializedField,*offset,fieldSize);
	*offset+=fieldSize;
	free(serializedField);
}

char* MetadataBlock::getContent(){
	vector<Field*>::iterator iter;
	Field* each;
	int counter= sizeof(T_FILETYPE);
	this->setFragment((char*)&_fileType,0,counter);
	unsigned short size= _fields->size();
	this->setFragment((char*)&size,counter,sizeof(short));
	counter+= sizeof(short);
	for (iter = this->_fields->begin(); iter != this->_fields->end(); iter++ ){	
		each=(Field*)*iter;
		this->writeOnBlock(each,this,&counter);
	}
	this->setFreeSpace(this->getSize()-counter);
	return Block::getContent();
}

void MetadataBlock::setFreeSpace(T_BLOCKSIZE space){
}

T_BLOCKSIZE MetadataBlock::getSize(){
	return Block::getFreeSpace();
}

T_BLOCKSIZE MetadataBlock::getFreeSpace(){
	return Block::getSize();
}
