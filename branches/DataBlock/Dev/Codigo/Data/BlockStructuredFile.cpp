#include "stdafx.h"
#include "BlockStructuredFile.h"

BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_filename=filename;
}
BlockStructuredFile::~BlockStructuredFile(){
	
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename,int blockSize){
	BlockStructuredFile* res=NULL;
	res=new BlockStructuredFile(filename);
	res->_blockSize=blockSize;
	return res;
}
