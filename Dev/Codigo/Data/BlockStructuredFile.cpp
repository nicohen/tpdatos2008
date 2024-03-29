#include "BlockStructuredFile.h"
#include "../Utils.h"
#include <string>
#include <sstream>
#include "BlockStructuredFileException.h"
#include "FileDoesAlreadyExistsException.h"
#include "FileNotFoundException.h"

void BlockStructuredFile::setBlockSize(T_BLOCKSIZE size) {
	this->_header->setBlockSize(size);
}
void BlockStructuredFile::setBlockCount(T_BLOCKCOUNT count) {
	this->_header->setBlockCount(count);
}

T_BLOCKCOUNT BlockStructuredFile::getBlockCount() {
	return this->_header->getBlockCount();
}

T_FILESIZE BlockStructuredFile::getFileSize() {
	this->_file->seekg(0, ios::end);
	return this->_file->tellg();
}

T_BLOCKSIZE BlockStructuredFile::getBlockSize() {
	return this->_header->getBlockSize();
}

BlockStructuredFile* BlockStructuredFile::Load(char* filename) {
	if(!existsFile(filename)){
		throw new FileNotFoundException((char*)"Se intento cargar un archivo que no existe");
	}
	BlockStructuredFile* res=NULL;
	T_BLOCKSIZE blockSize;
	fstream* file=NULL;

	file = new fstream(filename,ios::in|ios::binary);
	//Me muevo a la posicion 0 del archivo
	file->seekg(0, ios::beg);
	//Leo el primer campo (blockSize) para poder leer
	file->read((char*)&blockSize, sizeof(T_BLOCKSIZE));

	delete file;

	res=new BlockStructuredFile(filename);
	res->load(blockSize);
	return res;
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename, T_BLOCKSIZE blockSize) {
	if(existsFile(filename)){
		throw new FileDoesAlreadyExistsException((char*)"No se puede crear el archivo porque ya existe uno con el mismo nombre");
	}
	BlockStructuredFile* res=NULL;
	fstream* file=NULL;
	file = new fstream(filename,ios::trunc|ios::in|ios::out|ios::binary);
	file->close();
	delete file;

	res=new BlockStructuredFile(filename);
	res->setBlockSize(blockSize);
	res->setBlockCount(1);
	res->saveHeader();
	return res;
}

BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_file=NULL;
	this->_filename=filename;
	if (!existsFile(this->_filename)) {
		string msg;
		msg.append("No se encontró el archivo");
		throw new BlockStructuredFileException((char*)msg.c_str());
	}
	this->_file = new fstream(this->_filename,ios::in|ios::out|ios::binary);
	this->_header=new BlockStructuredFileHeader();
	this->setBlockCount(0);
	this->setBlockSize(0);
}

BlockStructuredFile::~BlockStructuredFile() {
	if (this->_file!=NULL) {
		this->_file->close();
		delete this->_file;
	}
	delete this->_header;
}

void BlockStructuredFile::load(T_BLOCKSIZE blockSize) {
	char* buffer;
	//Cargo todo el bloque en un buffer y cargo las propiedades de ahí
	buffer=(char*)malloc(blockSize);
	this->_file->seekg(0, ios::beg);
	this->_file->read(buffer, blockSize);
	this->_header->loadPropertiesFromBuffer(buffer);
	free(buffer);
}

void BlockStructuredFile::saveHeader() {
	char* buffer;
	buffer=(char*)malloc(this->getBlockSize());
	this->_header->saveHeaderToBuffer(buffer);
	this->updateBlock(0, buffer);
	free(buffer);
}

T_BLOCKCOUNT BlockStructuredFile::getLastBlockIndex() {
	return this->getBlockCount()-1;
}

void BlockStructuredFile::appendBlock(char* content) {
	this->updateBlock(this->getLastBlockIndex()+1, content);
	this->notifyBlockUpdated(this->getLastBlockIndex()+1);
}

void BlockStructuredFile::notifyBlockUpdated(T_BLOCKCOUNT blockNumber) {
	if (blockNumber>=this->getBlockCount()) {
		this->setBlockCount(this->getBlockCount()+1);
		this->saveHeader();
	}
}

void BlockStructuredFile::updateBlock(T_BLOCKCOUNT blockNumber, char* content) {
	this->_file->seekg(this->getBlockFilePositionFromAbsoluteBlockCount(blockNumber),ios::beg);
	this->_file->write(content, this->getBlockSize());
	this->_file->flush();
}

void BlockStructuredFile::updateContentBlock(T_BLOCKCOUNT contentBlockNumber,
		char* content) {
	this->updateBlock(
			this->getAbsoluteBlockNumberFromContentBlockNumber(contentBlockNumber),
			content);
	notifyBlockUpdated(this->getAbsoluteBlockNumberFromContentBlockNumber(contentBlockNumber));
}

T_FILESIZE BlockStructuredFile::getBlockFilePositionFromAbsoluteBlockCount(
		T_BLOCKCOUNT blockNumber) {
	return this->getBlockSize()*blockNumber;
}

T_BLOCKCOUNT BlockStructuredFile::getAbsoluteBlockNumberFromContentBlockNumber(
		T_BLOCKCOUNT contentBlockNumber) {
	return contentBlockNumber+this->getHeaderBlockCount();
}

char* BlockStructuredFile::getContentBlock(T_BLOCKCOUNT contentBlockNumber) {
	return getBlock(this->getAbsoluteBlockNumberFromContentBlockNumber(contentBlockNumber));
}

char* BlockStructuredFile::getBlock(T_BLOCKCOUNT blockNumber)
		throw (BlockStructuredFileException*) {
	if (blockNumber>=this->getBlockCount()) {
		string msg;
		ostringstream os;
		os<<blockNumber;
		msg.append("Se pidió un bloque que no existe: num = ");
		msg.append(os.str());
		throw new BlockStructuredFileException((char*)msg.c_str());
	} else {
		char* buffer;
		//Cargo todo el bloque en un buffer y cargo las propiedades de ah�
		buffer=(char*)malloc(this->getBlockSize());
		this->_file->seekg(
				this->getBlockFilePositionFromAbsoluteBlockCount(blockNumber),
				ios::beg);
		this->_file->read(buffer, this->getBlockSize());
		return buffer;
	}
}

T_BLOCKCOUNT BlockStructuredFile::getHeaderBlockCount() {
	return 1;
}

T_BLOCKCOUNT BlockStructuredFile::getContentBlockCount() {
	return this->getBlockCount()-this->getHeaderBlockCount();
}

void BlockStructuredFile::bUpdateContentBlock(T_BLOCKCOUNT contentBlockNumber,
		Block* block) {
	if (block->getUsedSpace()>this->getBlockSize()) {
		throw new BlockStructuredFileException((char*)"El bloque tiene un tamaño mas grande que el esperado");
	}
	this->updateContentBlock(contentBlockNumber, block->getContent());
}

Block* BlockStructuredFile::bGetContentBlock(T_BLOCKCOUNT contentBlockNumber,BlockFactory* blockFactory) {
	Block* result=NULL;
	char* buffer;
	buffer=this->getContentBlock(contentBlockNumber);
	if (blockFactory==NULL) {
		result=new Block(buffer,this->getBlockSize());
	} else {
		result=blockFactory->createBlock(buffer, this->getBlockSize());
	}

	free(buffer);
	return result;
}

void BlockStructuredFile::bAppendContentBlock(Block* block) {
	this->appendBlock(block->getContent());
	//Aca hay que actualizar luego el header para decirle el espacio libre de este bloque. block->getFreeSpace()
}

void BlockStructuredFile::deleTe(){
	if(this->_file->is_open()){
		this->_file->close();
	}
	remove(this->_filename);
}

bool BlockStructuredFile::truncateLast(){
	if(this->getBlockCount()>this->getHeaderBlockCount()){
		this->setBlockCount(this->getBlockCount()-1);
		this->saveHeader();
		if(this->_file->is_open()){
			this->_file->close();
		}
		delete this->_file;
		truncate(this->_filename,this->getBlockCount()*this->getBlockSize());
		this->_file = new fstream(this->_filename,ios::in|ios::out|ios::binary);
		return true;	
	}else{
		return false;
	}
	
}

