// AlmacenX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Common.h"
#include "TestCase.h"
#include "TestSuiteResult.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "BlockStructuredFile.h"

using namespace std;

bool REMOVE_TEST_FILES2=false;

void REMOVE_OPTINALY(char* filename){
	if(REMOVE_TEST_FILES2){
		remove(filename);
	}
}

void Test_WritesTheHeader(TestCase* test){
	fstream* file=NULL;
	char* filename="C:\\temp\\Test_BlockStructuredFile.bin";
	T_BLOCKSIZE blockSize=0;
	T_BLOCKCOUNT blockCount=0;
	T_BLOCKSIZE firstBlockFreeSpace=0;
	char* buffers;
	BlockStructuredFile* bsfile=NULL;

	remove(filename);
	bsfile=BlockStructuredFile::Create(filename,512);
	test->Assert_inteq(1,bsfile->getBlockCount());
	test->Assert_inteq(512,bsfile->getBlockSize());
	delete bsfile;

	file = new fstream(filename,ios::in|ios::binary);
	if(file->is_open()){
		buffers=(char*)malloc(512);
		file->seekg(0,ios::beg);
		file->read(buffers,512);
		memcpy(&blockSize,buffers, sizeof(T_BLOCKSIZE));
		memcpy(&blockCount,buffers+sizeof(T_BLOCKSIZE),sizeof(T_BLOCKCOUNT));
		memcpy(&firstBlockFreeSpace,buffers+sizeof(T_BLOCKSIZE)+sizeof(T_BLOCKCOUNT), sizeof(T_BLOCKSIZE));
		
		//Verifico que haya escrito el BlockSize
		test->Assert_inteq(512,blockSize);
		//Verifico que haya escrito el BlockCount
		test->Assert_inteq(1,blockCount);
		//Verifico que haya escrito el primer elemento de la FreeSpaceList
		test->Assert_inteq(512-sizeof(T_BLOCKSIZE)-sizeof(T_BLOCKCOUNT)-sizeof(T_BLOCKSIZE),firstBlockFreeSpace);
		file->close();
		delete buffers;
	}else{
		test->Assert_True_m(file->is_open(),"El archivo no se creó");
	}
	delete file;
	REMOVE_OPTINALY(filename);

}

void Test_LoadsProperly(TestCase* test){
	BlockStructuredFile* createdbsfile=NULL;
	BlockStructuredFile* loadedbsfile=NULL;
	char* filename="C:\\temp\\Test_LoadsProperly.bin";
	remove(filename);

	createdbsfile=BlockStructuredFile::Create(filename,512);
	delete createdbsfile;

	loadedbsfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(512,loadedbsfile->getBlockSize());
	test->Assert_inteq(1,loadedbsfile->getBlockCount());
	delete loadedbsfile;
	
}


int _tmain(int argc, char* argv[]){
	int failedTests=0;
		
	TestCase* test01=new TestCase("Test_WritesTheHeader",&failedTests);	
	Test_WritesTheHeader(test01);
	delete test01;	

	TestCase* test02=new TestCase("Test_LoadsProperly",&failedTests);	
	Test_LoadsProperly(test02);
	delete test02;	

	delete new TestSuiteResult(failedTests);
	system("pause");
	return 0;
}