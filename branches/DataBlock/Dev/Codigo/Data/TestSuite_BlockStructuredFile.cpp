// AlmacenX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "TestCase.h"
#include "TestSuiteResult.h"
#include <stdio.h>

#include "BlockStructuredFile.h"



using namespace std;



void Test_BlockStructuredFile(TestCase* test){
	fstream* file=NULL;
	char* filename="C:\\temp\\Test_BlockStructuredFile.bin";
	BlockStructuredFile* bsfile=NULL;
	bsfile=BlockStructuredFile::Create(filename,512);

	file = new fstream(filename,ios::in|ios::binary);
	if(file->is_open()){
		file->close();
	}else{
		test->Assert_True_m(file->is_open(),"El archivo no se creó");
	}
	delete file;

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