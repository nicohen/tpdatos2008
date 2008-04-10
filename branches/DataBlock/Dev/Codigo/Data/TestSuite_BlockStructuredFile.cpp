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

void Test_BlockStructuredFile(TestCase* test){
	fstream* file=NULL;
	char* filename="C:\\temp\\Test_BlockStructuredFile.bin";
	T_BLOCKSIZE blockSize=0;


	remove(filename);

	BlockStructuredFile* bsfile=NULL;
	bsfile=BlockStructuredFile::Create(filename,512);

	file = new fstream(filename,ios::in|ios::binary);
	if(file->is_open()){
		file->seekg(0,ios::beg);
		file->read((char*)&blockSize, sizeof(T_BLOCKSIZE));
		test->Assert_inteq(512,blockSize);
		file->close();
	}else{
		test->Assert_True_m(file->is_open(),"El archivo no se creó");
	}
	delete file;
	REMOVE_OPTINALY(filename);
	delete bsfile;

}


int _tmain(int argc, char* argv[]){
	int failedTests=0;
		
	TestCase* test01=new TestCase("Test_BlockStructuredFile",&failedTests);	
	Test_BlockStructuredFile(test01);
	delete test01;	

	delete new TestSuiteResult(failedTests);
	system("pause");
	return 0;
}