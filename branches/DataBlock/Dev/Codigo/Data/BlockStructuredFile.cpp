#include "stdafx.h"
#include "BlockStructuredFile.h"

#include <fstream>

using namespace std;
BlockStructuredFile::BlockStructuredFile(char* filename) {
	this->_filename=filename;
}
BlockStructuredFile::~BlockStructuredFile(){
	
}

void BlockStructuredFile::save(){
	/*fstream file (this->_filename,ios::trunc|ios::in|ios::binary|ios::out);
	file.seekg (0, ios::beg);
	file.write(this->_buffer,this->_size);
	file.close();*/
}

BlockStructuredFile* BlockStructuredFile::Create(char* filename,T_BLOCKSIZE blockSize){
	BlockStructuredFile* res=NULL;
	fstream* file=NULL;
	res=new BlockStructuredFile(filename);
	res->_blockSize=blockSize;

	file = new fstream(res->_filename,ios::trunc|ios::in|ios::binary|ios::out);
	file->seekg (0, ios::beg);
	file->write((char*)&blockSize,sizeof(T_BLOCKSIZE));
	file->close();
	delete file;


	return res;
}
