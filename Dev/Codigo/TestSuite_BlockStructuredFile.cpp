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


bool compareByteArray(char* array1,char* array2,T_BLOCKSIZE size){
	T_BLOCKSIZE i=0;
	for (i = 0; i < size; ++i) {
		if(*(array1+i)!=*(array2+i)){
			return false;
		}
	}
	return true;
}

void cleararray(char* array,T_BLOCKSIZE size){
	T_BLOCKSIZE i=0;
	for (i = 0; i < size; ++i) {
		*(array+i)='\0';
	}
}

char* createEmptyByteArray(T_BLOCKSIZE size){
	char* array;
	array=(char*)malloc(size);
	cleararray(array,size);
	*(array+size-1)='a';
	return array;	
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

void createBlockStructuredFileOnDisk(char* filename,T_BLOCKSIZE blockSize){
	BlockStructuredFile* file=NULL;
	remove(filename);
	file=BlockStructuredFile::Create(filename,blockSize);
	delete file;
}



void Test_UpdatesBlockCountAfterABlockAppend(TestCase* test){
	BlockStructuredFile* file=NULL;
	char* filename="Test_UpdatesBlockCountAfterABlockAppend.bin";
		
	createBlockStructuredFileOnDisk(filename,512);

	file=BlockStructuredFile::Load(filename);
	test->Assert_inteq(512,file->getBlockSize());
	test->Assert_inteq(1,file->getBlockCount());
	file->appendBlock(createEmptyByteArray(512));
	test->Assert_inteq(2,file->getBlockCount());
	
	delete file;
}

void Test_WhenItUpdatesBlockRealyWritesOnDisk(TestCase* test){
	BlockStructuredFile* file=NULL;
	char* filename="Test_WhenItUpdatesBlockRealyWritesOnDisk.bin";
	fstream* filestream=NULL;
	
	
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->updateContentBlock(0,createEmptyByteArray(512));
	delete file;
	
	filestream = new fstream(filename,ios::in|ios::binary);
	if(filestream->is_open()){
		filestream->seekg(0,ios::end);
		test->Assert_inteq(1024,filestream->tellg());
		filestream->close();
	}else{
		test->Assert_True_m(filestream->is_open(),"El archivo no se cre�");
	}	
	delete filestream;	
}

void Test_WhenItUpdatesBlockSavesHeaderInformation(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	char* filename="Test_WhenItUpdatesBlockSavesHeaderInformation.bin";
	
	//Actualizo el primer bloque
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	test->Assert_inteq(0,file->getContentBlockCount());
	file->updateContentBlock(0,createEmptyByteArray(512));
	test->Assert_inteq(1,file->getContentBlockCount());
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(1,loadedfile->getContentBlockCount());
	delete file;
	
	
	//Actualizo el segundo bloque
	file=BlockStructuredFile::Load(filename);
	file->updateContentBlock(1,createEmptyByteArray(512));
	test->Assert_inteq(2,file->getContentBlockCount());
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(2,loadedfile->getContentBlockCount());
	delete file;
	
	
	//Actualizo el primer bloque nuevamente
	file=BlockStructuredFile::Load(filename);
	file->updateContentBlock(0,createEmptyByteArray(512));
	test->Assert_inteq(2,file->getContentBlockCount());
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(2,loadedfile->getContentBlockCount());
	delete file;
}
void Test_getContentBlockCount(TestCase* test){
	BlockStructuredFile* file=NULL;
	char* filename="Test_getContentBlockCount.bin";
	
	//Actualizo el primer bloque
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	test->Assert_inteq(0,file->getContentBlockCount());
	delete file;
}


void Test_compareByteArray(TestCase* test){
	char* buffer1=NULL;
	char* buffer2=NULL;
	
	//Creo dos arrays iguales
	buffer1=(char*)malloc(60);
	buffer2=(char*)malloc(60);
	cleararray(buffer1,60);
	cleararray(buffer2,60);
	
	//Verifico que sean iguales
	test->Assert_True_m(compareByteArray(buffer1,buffer2,60),"Deberian ser iguales");
	
	//Modifico el ultimo elemento
	*(buffer2+59)='a';

	//Verifico que sean distintos
	test->Assert_True_m(!compareByteArray(buffer1,buffer2,60),"Deberian ser distintos");
	
	free (buffer1);
	free (buffer2);
}

void Test_getContentBlock(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	char* filename="Test_getContentBlock.bin";
	char* buffer1;
	char* obtainedbuffer;
	
	buffer1=createEmptyByteArray(512);
	*(buffer1+5)='y';	
	
	//Actualizo el primer bloque
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->updateContentBlock(0,buffer1);
	delete file;
		
	loadedfile=BlockStructuredFile::Load(filename);
	obtainedbuffer=loadedfile->getContentBlock(0);
	
	test->Assert_True_m(compareByteArray(buffer1,obtainedbuffer,512),"Deberian ser iguales");
	delete loadedfile;
	
	free(buffer1);
	free(obtainedbuffer);
}

void Test_GetBlock(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	char* filename="Test_getContentBlock.bin";
	char* buffer1;
	char* obtainedbuffer;
	
	buffer1=createEmptyByteArray(512);
	*(buffer1+5)='9';	
	
	//Actualizo el primer bloque
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->updateContentBlock(0,buffer1);
	delete file;
		
	loadedfile=BlockStructuredFile::Load(filename);
	obtainedbuffer=loadedfile->getBlock(1);
	
	test->Assert_True_m(compareByteArray(buffer1,obtainedbuffer,512),"Deberian ser iguales");
	delete loadedfile;
	
	free(buffer1);
	free(obtainedbuffer);
}


int main(int argc, char* argv[]){
	int failedTests=0;
	
	
	
	TestCase* test01=new TestCase("Test_WritesTheHeader",&failedTests);	
	Test_WritesTheHeader(test01);
	delete test01;	

	TestCase* test02=new TestCase("Test_LoadsProperly",&failedTests);	
	Test_LoadsProperly(test02);
	delete test02;	
	
	TestCase* test03=new TestCase("Test_UpdatesBlockCountAfterABlockAppend",&failedTests);	
	Test_UpdatesBlockCountAfterABlockAppend(test03);
	delete test03;	
	
	TestCase* test04=new TestCase("Test_WhenItUpdatesBlockRealyWritesOnDisk",&failedTests);	
	Test_WhenItUpdatesBlockRealyWritesOnDisk(test04);
	delete test04;
	
	TestCase* test05=new TestCase("Test_WhenItUpdatesBlockSavesHeaderInformation",&failedTests);	
	Test_WhenItUpdatesBlockSavesHeaderInformation(test05);
	delete test05;
	
	TestCase* test06=new TestCase("Test_getContentBlockCount",&failedTests);	
	Test_getContentBlockCount(test06);
	delete test06;
	
	TestCase* test07=new TestCase("Test_getContentBlock",&failedTests);	
	Test_getContentBlock(test07);
	delete test07;
	
	TestCase* test08=new TestCase("Test_compareByteArray",&failedTests);	
	Test_compareByteArray(test08);
	delete test08;
	
	TestCase* test09=new TestCase("Test_GetBlock",&failedTests);	
	Test_GetBlock(test09);
	delete test09;
	
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
>>--Done --> void updateBlock(int blockNumber,char* content);
clase block??
>>--Done --> clase header block??
>>--Done --> Cambiar loadPropertiesFromBuffer por "load header from buffer"
>>--Done --> Aclarar Indices
Mover una parte de updateBlock a append block. cosa que el updateBlock solo actue cuando se actualice un bloque. Cuando se está agregando uno hay que llamar al append 



VIEJO!!!!VIEJO!!!!VIEJO!!!!VIEJO!!!!VIEJO!!!!
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