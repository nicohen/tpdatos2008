// AlmacenX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "TestCase.h"
#include "TrueAssertion.h"
#include "DataBlock.h"

#include <stdio.h>

using namespace std;

ifstream::pos_type size;
char * memblock;


/*
Escribe el contenido en el archivo con el formato adecuado
*/
void writeRecord(fstream* file, char* content){
	char length=0;
	length=(char)strlen(content);	
	file->write(&length,1);
	file->write(content,strlen(content));
}


void writeTestFile(char* filename){
	fstream file (filename,ios::trunc|ios::in|ios::binary|ios::out);
	if (file.is_open())
	{
		cout << "File was opened\n";
		file.seekg(0);
		writeRecord(&file,"Registro1");
		writeRecord(&file,"Este es el segundo registro");
		writeRecord(&file,"Este es el tercer registro");
		writeRecord(&file,"Este es el cuarto registro");
		file.close();
		delete[] memblock;
		cout << "File Writen\n";
		return;
	}
	cout << "File NOT Writen\n";
	return;
}

int SIZEOF_RECORD_SIZE_SECTION = 1;

void readFile(char* filename){
	fstream file (filename,ios::in|ios::binary);	
	char lenght=0;
	char* content;
	if (file.is_open())
	{
		cout << "File was opened\n";
		file.seekg(0);

		//Leo la primer seccion que es la seccion de "TAMAÑO". Indica el largo del string
		file.read(&lenght,SIZEOF_RECORD_SIZE_SECTION);
		//Me muevo hacia adelante para pararme luego de la seccion de "TAMAÑO". Indica el largo del string
		file.seekg(SIZEOF_RECORD_SIZE_SECTION,ios::beg);
		
		//Aloco memoria segun el largo del contenido
		content=(char*)malloc(lenght+1);
		//leo el contenido
		file.read(content,lenght);
		*(content+lenght)='\0';
		
		printf("___%i___",lenght);
		printf("___%s___",content);

		free(content);
		file.close();
		delete[] memblock;
		cout << "File Writen\n";
		return;
	}
	cout << "File NOT Writen\n";
	return;
}

/*int main(int argc, char* argv[]){

	writeTestFile("c:/temp/example2.bin");
	readFile("c:/temp/example2.bin");

	system("pause");
	return 0;
}
*/
/*
void test_01(TestCase* test){
	test->Assert_True_m(false,"Errprrrr");
	test->Assert_True(true);
	test->Assert_streq("a","a");
	test->Assert_streq("b","a");
}*/

bool hadSuccessRemoving(int removeResponse){
	return removeResponse==0;
}

char* filename="C:\\temp\\block.bin";
int blockSize=256;

void Test_DateBlock(TestCase* test){
	DataBlock* block=NULL;
	char current='\0';
	int nonSpacesFound=0;
	remove(filename);	
	
	block=new DataBlock(filename,blockSize);
	block->allocateSpace();
	delete block;
		
	//test->Assert_True_m(hadSuccessRemoving(remove(filename)),"El DataBlock no creó ningun archivo");
	fstream file (filename,ios::in|ios::binary);
	if(file.is_open()){
		file.seekg (0, ios::end);
		test->Assert_True_m(blockSize==file.tellg(),"El DataBlock creo un archivo de tamaño distinto a 512");
		
		file.seekg (0, ios::beg);
		for(int i=0;i<blockSize;i++){
			file.seekg(i);
			file.read(&current,1);
			if(current!='\0'){
				nonSpacesFound++;
			}
		}
		test->Assert_True_m(nonSpacesFound==0,"El DataBlock dejó algunos espacios no vacios");
		file.close();
	}
	test->Assert_True_m(hadSuccessRemoving(remove(filename)),"El DataBlock no creó ningun archivo");
	remove(filename);
}




/*
Escribe el contenido en el archivo con el formato adecuado
*/
/*void writeRecord(fstream* file, char* content){
	char length=0;
	length=(char)strlen(content);	
	file->write(&length,1);
	file->write(content,strlen(content));
}
*/
void Test_Block_WritesRecordCountAtTheBeginingOfTheFile(TestCase* test){
	DataBlock* block=NULL;
	char* recordContent=0;
	char recordCount='\0';
	
	remove(filename);

	block=new DataBlock(filename,blockSize);
	block->allocateSpace();
	delete block;
	
	block=new DataBlock(filename,blockSize);
	block->writeRecord("Este es el primer registro");
	block->writeRecord("Este es el segundo registro");
	block->writeRecord("Este es el tercer registro");
	block->writeRecord("Este es el cuarto registro");
	block->writeRecord("Este es el quinto registro");
	delete block;

	fstream file (filename,ios::in|ios::binary);
	if(file.is_open()){		
		file.seekg (0, ios::beg);
		file.read(&recordCount,1);
		test->Assert_True_m((int)recordCount==5,"Se esperaban 5 registros");
		file.close();
	}else{
		test->Assert_True_m(false,"No se pudo abrir el archivo para testear");
	}

	//remove(filename);
}

int main(int argc, char* argv[]){
	int failedTests=0;
	
	
	TestCase* test01=new TestCase("Allocate Block Space",&failedTests);	
	Test_DateBlock(test01);
	delete test01;

	TestCase* test02=new TestCase("Test_Block_WritesRecordCountAtTheBeginingOfTheFile",&failedTests);	
	Test_Block_WritesRecordCountAtTheBeginingOfTheFile(test02);
	delete test02;
	
	
	printf("::::::::::::::::::::::::::::::::::\n");
	printf(":::Tests::::::::::::::::::::::::::\n");
	printf("::::::::::::::::::::::::::::::::::\n");
	if(failedTests>0){
		printf("!!!!!!FAILED %i TEST/S !!!!!!!!!!\n",failedTests);
	}else{
		printf("Ok\n");		
	}
	printf("::::::::::::::::::::::::::::::::::\n");

	system("pause");
	return 0;
}