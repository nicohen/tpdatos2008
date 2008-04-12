#include "TestingFramework/TestCase.h"
#include "TestingFramework/TestSuiteResult.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Data/BlockStructuredFile.h"

using namespace std;

bool REMOVE_TEST_FILES2=false;
bool verbose=true;

void REMOVE_OPTINALY(char* filename){
	if(REMOVE_TEST_FILES2){
		remove(filename);
	}
}

void Test_WritesTheHeader(TestCase* test){
	fstream* file=NULL;
	char* filename="Test_BlockStructuredFile.bin";
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
		test->Assert_True_m(file->is_open(),"El archivo no se cre�");
	}
	delete file;
	REMOVE_OPTINALY(filename);

}

void Test_LoadsProperly(TestCase* test){
	BlockStructuredFile* createdbsfile=NULL;
	BlockStructuredFile* loadedbsfile=NULL;
	char* filename="Test_LoadsProperly.bin";
	remove(filename);

	createdbsfile=BlockStructuredFile::Create(filename,512);
	delete createdbsfile;

	loadedbsfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(512,loadedbsfile->getBlockSize());
	test->Assert_inteq(1,loadedbsfile->getBlockCount());
	delete loadedbsfile;
	
}


int main(int argc, char* argv[]){
	int failedTests=0;
		
	TestCase* test01=new TestCase("Test_WritesTheHeader",&failedTests);	
	Test_WritesTheHeader(test01);
	delete test01;	

	TestCase* test02=new TestCase("Test_LoadsProperly",&failedTests);	
	Test_LoadsProperly(test02);
	delete test02;	

	delete new TestSuiteResult(failedTests);
	return 0;
};




/*
2008_04_10
-------------

>>--Done --> Donde static BlockStructuredFile* Load(char* filename);
>>--Done --> static BlockStructuredFile* Create(char* filename,int blockSize);
>>--Done --> int getBlockSize();
>>--Done --> int getBlockCount();
void appendBlock(char* content); (tener en cuenta que el indice tiene que estar defasado)
char* getBlock(int blockNumber);
void removeBlock(int blockNumber);
Actualizar la lista de espacios libres en bloques en cada operacion
int getFirstFreeBlockNumber();
void moveBlock(int currentBlockNumber,int destBlockNumber);
virtual ~BlockStructuredFile(void);
void updateBlock(int blockNumber,char* content);








 OOOLDD
>>--Done --> Crear un bloque de tama�o N en un archivo dado
>>--Done --> Al escribir se actualiza la cantidad de registros escritos al principipo
Escribir bytes(registros) en bloque
Leer bytes(registros) en bloque
Parametrizar tama�os
Informacion de llenado
colchon de 80%
EliminarRegistros
Cuando se elimina un registro, el espacio queda libre. Hay que leer hasta el final en busca de registros, es decir, en busca de algun campo que indique el largo de un registro
generalizar el tama�o del RecordCount dentro de un bloque
validar que no se quiera meter un registro mas grande que Size-Tama�o de RecordCount
validar que no se quiera meter un registro mas grande que el espacio libre - Tama�o de RecordLenght
>>--Done --> IMP: hacer todo en memoria y poner un flush()
>>--Done --> cambiar allocateSpace por clear

 
 */