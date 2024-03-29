#include "HashTable.h"
#include "stdio.h"
#include "../Utils.h"
#include "../Data/FileNotFoundException.h"

HashTable::HashTable(char* debugHeader){
	_hashFile=NULL;
	_debugHeader = cloneStr(debugHeader);
}

HashTable::~HashTable(){
	if (_hashFile!=NULL){
		fclose(_hashFile);
	}
	free(_fileName);
}

void HashTable::create(char* filePath, int size){
	_size=size;
	int zero=0;
	_hashFile=fopen(filePath,"w+");
	_fileName= cloneStr(filePath);
	fseek(_hashFile,0,SEEK_SET);
	fwrite(&size,INT_SIZE,1,_hashFile);
	for (int i=0;i<size;i++){
		fwrite(&zero,INT_SIZE,1,_hashFile);	
	}		
}

void HashTable::load(char* filePath){
	_fileName= cloneStr(filePath);
	_hashFile=fopen(filePath,"r+");
	fseek(_hashFile,0,SEEK_SET);
	fread(&_size,INT_SIZE,1,_hashFile);
}

void HashTable::deleTe() {
	if (!hadSuccessRemoving(remove(_fileName))) {
		throw new FileNotFoundException((char*)"Se intento eliminar un archivo que no existe");
	}
}

int HashTable::getSize(){
	return _size;
}

int HashTable::getAt(int i){
	int content;
	fseek(_hashFile,(i+1)*INT_SIZE,SEEK_SET);
	fread(&content,INT_SIZE,1,_hashFile);
	return content;
}

void HashTable::update(int index, int value){
	string msg;
	msg.append(_debugHeader);
	msg.append("Actualizando la tabla. Posicion '");
	appendIntTo(&msg,index);
	msg.append("', Valor '");
	appendIntTo(&msg,value);
	msg.append("'");
	DEBUGS(&msg);
	fseek(_hashFile,(index+1)*INT_SIZE,SEEK_SET);
	fwrite(&value,INT_SIZE,1,_hashFile);
	fflush(_hashFile);
}

void HashTable::grow(){
	string msg;
	msg.append(_debugHeader);
	msg.append("Agrandando la tabla. Valor anterior '");
	appendIntTo(&msg,_size);
	int* buffer= (int*) malloc(INT_SIZE*_size);
	fseek(_hashFile,INT_SIZE,SEEK_SET);
	fread(buffer,INT_SIZE,_size,_hashFile);
	fseek(_hashFile,INT_SIZE*(_size+1),SEEK_SET);
	fwrite(buffer,INT_SIZE,_size,_hashFile);
	_size=_size+_size;
	fseek(_hashFile,0,SEEK_SET);
	fwrite(&_size,INT_SIZE,1,_hashFile);
	free(buffer);

	msg.append("', Valor nuevo '");
	appendIntTo(&msg,_size);
	msg.append("'");
	DEBUGS(&msg);
}

void HashTable::append(int value){
//	string msg;
//	msg.append("HASH agregando elemento a la tabla");
//	appendIntTo(&msg,_size);
	int* buffer= (int*) malloc(INT_SIZE*1);
	
	fseek(_hashFile,INT_SIZE*(_size+1),SEEK_SET);
	fwrite(&value,INT_SIZE,_size,_hashFile);
	_size=_size+1;
	fseek(_hashFile,0,SEEK_SET);
	fwrite(&_size,INT_SIZE,1,_hashFile);
	free(buffer);

//	msg.append("', Valor nuevo '");
//	appendIntTo(&msg,_size);
//	msg.append("'");
//	DEBUGS(&msg);
}

void HashTable::simplify(){
	_size=_size/2;
	fseek(_hashFile,0,SEEK_SET);
	fwrite(&_size,INT_SIZE,1,_hashFile);
	truncate(_fileName,this->getPhysicalSize());
}

void HashTable::toString(string* buffer) {
	int at;
	if (_size>0) {
		for(int i=0;i<_size;i++) {
			at = getAt(i);
			buffer->append("\n");
			appendIntTo(buffer,i);
			buffer->append("|");
			appendIntTo(buffer,at);
		}
	} else {
		buffer->append("0");
	}
}

int HashTable::getPhysicalSize() {
	return (this->_size+1)*INT_SIZE;
}

bool HashTable::removeLast(){
	if(_size> 0){//Para no borrar el primer elemento
		_size=_size - 1;
		fseek(_hashFile,0,SEEK_SET);
		fwrite(&_size,INT_SIZE,1,_hashFile);
		truncate(_fileName,this->getPhysicalSize());
		return true;
	}else{
		return false;
	}
}
