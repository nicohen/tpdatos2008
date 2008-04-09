// AlmacenX.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "TestCase.h"
#include "TrueAssertion.h"

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

void test_01(TestCase* test){
	test->Assert_True(false);
	test->Assert_True(true);
}

int main(int argc, char* argv[]){
	int failedTests=0;
	
	
	TestCase* test01=new TestCase("test_01",&failedTests);	
	test_01(test01);
	delete test01;
	
	
	printf(":::Tests:::.......................\n");
	if(failedTests>0){
		printf("!!!!!!FAILED %i TEST/S !!!!!!!!!!\n",failedTests);
	}else{
		printf("Ok\n");		
	}

	printf("..................................\n");

	system("pause");
	return 0;
}