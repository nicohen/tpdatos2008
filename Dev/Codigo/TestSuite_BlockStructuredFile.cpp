#include "TestingFramework/TestCase.h"
#include "TestingFramework/TestSuiteResult.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include "Data/BlockStructuredFile.h"
#include "Data/Block.h"
#include "Data/RecordsBlock.h"
#include "Data/RawRecord.h"
#include "Data/Record.h"
#include "IntValue.h"
#include "StringValue.h"
#include "StructureValue.h"
#include "IntType.h"


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
			printf("\ncompare arrays false:pos %i, expected '%i'(%i), but was '%i'(%i)",i,*(array1+i),*(array1+i),*(array2+i),*(array2+i));
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
Block* createEmptyBlock(T_BLOCKSIZE size){
	return new Block(createEmptyByteArray(size),size);
}

Block* createSomeBlock(T_BLOCKSIZE size,int hardcodedtype){
	char* content=NULL;
	content=createEmptyByteArray(size);
	switch(hardcodedtype){
		case 1:
			*content='a';
			*(content+size-1)='b';
			break;
		case 2:
			*content='c';
			*(content+size-1)='e';			
			break;
		case 3:
			*content='f';
			*(content+size-1)='h';		
			break;	
	}
	return new Block(content,size);
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
	file->bAppendContentBlock(createEmptyBlock(512));
	test->Assert_inteq(2,file->getBlockCount());
	
	delete file;
}

void Test_WhenItUpdatesBlockRealyWritesOnDisk(TestCase* test){
	BlockStructuredFile* file=NULL;
	char* filename="Test_WhenItUpdatesBlockRealyWritesOnDisk.bin";
	fstream* filestream=NULL;
	
	
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->bUpdateContentBlock(0,createEmptyBlock(512));
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
	file->bUpdateContentBlock(0,createEmptyBlock(512));
	test->Assert_inteq(1,file->getContentBlockCount());
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(1,loadedfile->getContentBlockCount());
	delete file;
	
	
	//Actualizo el segundo bloque
	file=BlockStructuredFile::Load(filename);
	file->bUpdateContentBlock(1,createEmptyBlock(512));
	test->Assert_inteq(2,file->getContentBlockCount());
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(2,loadedfile->getContentBlockCount());
	delete file;
	
	
	//Actualizo el primer bloque nuevamente
	file=BlockStructuredFile::Load(filename);
	file->bUpdateContentBlock(0,createEmptyBlock(512));
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
	file->bUpdateContentBlock(0,new Block(buffer1,512));
	delete file;
		
	loadedfile=BlockStructuredFile::Load(filename);
	
	test->Assert_True_m(compareByteArray(buffer1,loadedfile->bGetContentBlock(0,NULL)->getContent(),512),"Deberian ser iguales");
	delete loadedfile;
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
	file->bUpdateContentBlock(0,new Block(buffer1,512));
	delete file;
		
	loadedfile=BlockStructuredFile::Load(filename);
	obtainedbuffer=loadedfile->getBlock(1);
	
	test->Assert_True_m(compareByteArray(buffer1,obtainedbuffer,512),"Deberian ser iguales");
	delete loadedfile;
	
	free(buffer1);
	free(obtainedbuffer);
}

void Test_Append(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	char* filename="Test_Append.bin";
	
	//Actualizo el primer bloque
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->bAppendContentBlock(createEmptyBlock(512));
	test->Assert_inteq(1,file->getContentBlockCount());
	file->bAppendContentBlock(createEmptyBlock(512));
	test->Assert_inteq(2,file->getContentBlockCount());
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(2,loadedfile->getContentBlockCount());
	test->Assert_True_m(compareByteArray(createEmptyBlock(512)->getContent(),loadedfile->bGetContentBlock(1,NULL)->getContent(),512),"Deberian ser iguales");
	
	delete loadedfile;
}

void Test_Block_setContent(TestCase* test){
	Block* block=NULL;
	char* buffer;
	block=new Block(512);
	buffer=createEmptyByteArray(512);
	*(buffer)='q';
	block->setContent(buffer);
	test->Assert_True_m(compareByteArray(buffer,block->getContent(),512),"Deberian ser iguales");
	*(buffer)='o';
	test->Assert_True_m(!compareByteArray(buffer,block->getContent(),512),"Deberian ser distintos");
	delete block;
	free(buffer);
}

void Test_Block_Constructor(TestCase* test){
	Block* block=NULL;
	char* buffer;
	
	buffer=createEmptyByteArray(512);
	*(buffer)='q';
	block=new Block(buffer,512);
	test->Assert_True_m(compareByteArray(buffer,block->getContent(),512),"Deberian ser iguales");
	*(buffer)='o';
	test->Assert_True_m(!compareByteArray(buffer,block->getContent(),512),"Deberian ser distintos");
	delete block;
	free(buffer);
}

void Test_Block_setFragment(TestCase* test){
	Block* block=NULL;
	char* buffer;
	char* expected;
	char* fragment;
	T_BLOCKSIZE offset;
	buffer=createEmptyByteArray(512);
	*(buffer)='q';
	block=new Block(buffer,512);
	
	offset=5;
	fragment=createEmptyByteArray(3);
	*(fragment+offset)='n';
	*(fragment+offset+1)='a';
	*(fragment+offset+2)='h';
	block->setFragment(fragment,offset,3);
	
	expected=createEmptyByteArray(512);
	*(expected)='q';
	*(expected+offset)='n';
	*(expected+offset+1)='a';
	*(expected+offset+2)='h';
	test->Assert_True_m(compareByteArray(expected,block->getContent(),512),"Deberian ser iguales");
		
	delete block;
	free(buffer);
	free(expected);
	free(fragment);
}

void Test_Block_SizeAndFreeSpace(TestCase* test){
	Block* block=NULL;
	char* buffer;
	buffer=createEmptyByteArray(512);
	*(buffer)='q';
	block=new Block(buffer,512);
	block->getFreeSpace();
	test->Assert_inteq(0,block->getFreeSpace());
	test->Assert_inteq(512,block->getSize());
	block->setFreeSpace(20);
	test->Assert_inteq(20,block->getFreeSpace());
	delete block;
	free(buffer);
}

void Test_BlockStructured_BUpdateBlock(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	Block* block=NULL;
	Block* obtainedBlock=NULL;
	char* filename="Test_BlockStructured_BUpdateBlock.bin";
	char* buffer;
	//char* obtainedbuffer;
	buffer=createEmptyByteArray(512);*(buffer)='q';
	block=new Block(buffer,512);
	
	
	//Actualizo el primer bloque
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->bUpdateContentBlock(0,block);
	delete file;
		
	loadedfile=BlockStructuredFile::Load(filename);
	obtainedBlock=loadedfile->bGetContentBlock(0,NULL);
	
	test->Assert_True_m(compareByteArray(buffer,obtainedBlock->getContent(),512),"Deberian ser iguales");
	delete loadedfile;

	free(buffer);
	//free(obtainedbuffer);
	delete block;
	delete obtainedBlock;
}


void Test_BlockStructured_bAppendContentBlock(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	Block* block1=NULL;
	Block* block2=NULL;
	Block* obtainedBlock=NULL;
	char* filename="Test_BlockStructured_BAppendBlock.bin";
	char* buffer1;
	char* buffer2;
	//char* obtainedbuffer;
	buffer1=createEmptyByteArray(512);*(buffer1+1)='q';
	buffer2=createEmptyByteArray(512);*(buffer2+5)='4';

	
	block1=new Block(buffer1,512);
	block2=new Block(buffer2,512);
	
	//Agrego bloques
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->bAppendContentBlock(block1);
	file->bAppendContentBlock(block2);
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	obtainedBlock=loadedfile->bGetContentBlock(0,NULL);	
	test->Assert_True_m(compareByteArray(buffer1,obtainedBlock->getContent(),512),"Deberian ser iguales");
	delete obtainedBlock;
	
	
	obtainedBlock=loadedfile->bGetContentBlock(1,NULL);
	test->Assert_True_m(compareByteArray(buffer2,obtainedBlock->getContent(),512),"Deberian ser iguales");
	delete loadedfile;

	free(buffer1);
	free(buffer2);
	delete block1;
	delete block2;
	delete obtainedBlock;
}

Block* getSomeBlock(T_BLOCKSIZE size){
	Block* res=NULL;
	char* buffer1;
	//char* obtainedbuffer;
	buffer1=createEmptyByteArray(size);*(buffer1+1)='q';
	res=new Block(buffer1,size);
	free(buffer1);
	return res;
}

void Test_BlockStructured_removeLastContentBlock(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	Block* block1=NULL;
	Block* block2=NULL;
	char* filename="Test_BlockStructured_removeLastContentBlock.bin";
	
	block1=getSomeBlock(512);
	block2=getSomeBlock(512);
	
	//Agrego bloques
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	file->bAppendContentBlock(block1);
	file->bAppendContentBlock(block2);
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(2,loadedfile->getContentBlockCount());
	loadedfile->removeLastContentBlock();
	test->Assert_inteq(1,loadedfile->getContentBlockCount());
	delete loadedfile;
	
	loadedfile=BlockStructuredFile::Load(filename);
	test->Assert_inteq(1,loadedfile->getContentBlockCount());test->Assert_inteq(1,loadedfile->getContentBlockCount());
	delete loadedfile;
	

	delete block1;
	delete block2;
}

void Test_RecordsBlock(TestCase* test){
	RecordsBlock* recordsBlock=NULL;
	char* updatedBuffer=NULL;
	T_BLOCKSIZE actualRecord1Size=0;
	T_BLOCKSIZE actualRecord2Size=0;
	T_BLOCKSIZE actualRecordsCount=0;	
	
	//Creo un bloque de registros
	recordsBlock=new RecordsBlock(100);
	recordsBlock->appendRecord(new RawRecord("e",1));
	recordsBlock->appendRecord(new RawRecord("a",1));
	
	updatedBuffer=recordsBlock->getContent();
	
	memcpy(&actualRecordsCount,updatedBuffer,sizeof(T_BLOCKSIZE));
	//Corro el puntero la cantidad de bytes que ocupa el campo que dice la cantidad de elementos
	updatedBuffer+=sizeof(T_BLOCKSIZE);
	memcpy(&actualRecord1Size,updatedBuffer,sizeof(T_BLOCKSIZE));
	memcpy(&actualRecord2Size,updatedBuffer+sizeof(T_BLOCKSIZE)+actualRecord1Size,sizeof(T_BLOCKSIZE));
	//Verifico el campo que indica la catidad de bloques
	test->Assert_inteq(2,actualRecordsCount);
	//Verifico el campo que indica el tamaño del primer registro
	test->Assert_inteq(1,actualRecord1Size);
	//Verifico el campo que indica el tamaño del segundo registro
	test->Assert_inteq(1,actualRecord2Size);
	//Verifico el campo que guarda el contenido del primer registro
	test->Assert_True_m(compareByteArray("e",updatedBuffer+sizeof(T_BLOCKSIZE),1),"Deberian ser arrays iguales");
	//Verifico el campo que guarda el contenido del segundo registro
	test->Assert_True_m(compareByteArray("a",updatedBuffer+sizeof(T_BLOCKSIZE)+1+sizeof(T_BLOCKSIZE),1),"Deberian ser arrays iguales");
	//Verifico el espacio libre
	test->Assert_inteq(100-2*(1+sizeof(T_BLOCKSIZE))-sizeof(T_BLOCKSIZE),recordsBlock->getFreeSpace());
	delete recordsBlock;
}

void Test_RecordsBlock_Deserialization(TestCase* test){
	RecordsBlock* recordsBlock=NULL;
	RecordsBlock* deserializedRecordsBlock=NULL;
	char* serializedData=NULL;
	
	//Creo un bloque de registros
	recordsBlock=new RecordsBlock(100);
	//Le agrego registros
	recordsBlock->appendRecord(new RawRecord("hola",4));
	recordsBlock->appendRecord(new RawRecord("chau",4));
	
	//Lo serializo
	serializedData=(char*)malloc(100);
	memcpy(serializedData,recordsBlock->getContent(),100);
	delete recordsBlock;
	
	//Creo un nuevo bloque de registros a partir de la informacion serializada
	deserializedRecordsBlock=new RecordsBlock(serializedData,100);
	test->Assert_inteq(2,deserializedRecordsBlock->getRecords()->size());
	test->Assert_True_m(compareByteArray("hola",((RawRecord*)deserializedRecordsBlock->getRecords()->at(0))->getContent(),4),"hola_Deberian ser arrays iguales");
	test->Assert_True_m(compareByteArray("chau",((RawRecord*)deserializedRecordsBlock->getRecords()->at(1))->getContent(),4),"chau_Deberian ser arrays iguales");
	free(serializedData);
	delete deserializedRecordsBlock;	
}

void Test_RecordsBlock_RecordsManipulation(TestCase* test){
	RecordsBlock* recordsBlock=NULL;
	RecordsBlock* deserializedRecordsBlock=NULL;
	char* serializedData=NULL;
	
	//Creo un bloque de registros
	recordsBlock=new RecordsBlock(100);
	//Le agrego registros
	recordsBlock->getRecords()->push_back(new RawRecord("Holaas",6));
	recordsBlock->getRecords()->push_back(new RawRecord("Haaaeee",7));
	recordsBlock->getRecords()->push_back(new RawRecord("aax",3));
	recordsBlock->getRecords()->pop_back();
	
	//Lo serializo
	serializedData=(char*)malloc(100);
	memcpy(serializedData,recordsBlock->getContent(),100);
	delete recordsBlock;
	
	//Creo un nuevo bloque de registros a partir de la informacion serializada
	deserializedRecordsBlock=new RecordsBlock(serializedData,100);
	test->Assert_inteq(2,deserializedRecordsBlock->getRecords()->size());
	test->Assert_True_m(compareByteArray("Holaas",((RawRecord*)deserializedRecordsBlock->getRecords()->at(0))->getContent(),6),"hola_Deberian ser arrays iguales");
	test->Assert_True_m(compareByteArray("Haaaeee",((RawRecord*)deserializedRecordsBlock->getRecords()->at(1))->getContent(),7),"chau_Deberian ser arrays iguales");
	free(serializedData);
	delete deserializedRecordsBlock;
}



Block* createRecordsBlock(char* content, T_BLOCKSIZE size){
	printf("\n createRecordsBlock called");
	return new RecordsBlock(content,size);
}

void Test_BlockStructured_DataBlockCreation(TestCase* test){
	BlockStructuredFile* file=NULL;
	BlockStructuredFile* loadedfile=NULL;
	RecordsBlock* block;
	RecordsBlock* loadedblock;
	//Agrego bloques
	char* filename="Test_BlockStructured_DataBlockCreation.bin";
	createBlockStructuredFileOnDisk(filename,512);
	file=BlockStructuredFile::Load(filename);
	block=new RecordsBlock(512);
	block->appendRecord(new RawRecord("aaaa",4));
	file->bAppendContentBlock(block);
	file->bAppendContentBlock(createEmptyBlock(512));
	delete file;
	
	loadedfile=BlockStructuredFile::Load(filename);
	loadedblock = (RecordsBlock*)loadedfile->bGetContentBlock(0,&createRecordsBlock);
	test->Assert_True_m(compareByteArray("aaaa",((RawRecord*)loadedblock->getRecords()->at(0))->getContent(),4),"Los bloques deberian ser iguales");
	delete loadedfile;
}

char* serializeInt(int value){
	char* serializedData=(char*)malloc(sizeof(int));
	memcpy(serializedData,(char*)&value,sizeof(int));
	return serializedData;
}

void Test_IntValue_SerializeDeserialize(TestCase* test){	
	IntValue* inttoserialize;
	IntValue* deserializedint;
	IntType* type=new IntType;
	
	inttoserialize=new IntValue(10);
	deserializedint=(IntValue*)type->deserializeValue(inttoserialize->serialize());
	
	
	test->Assert_inteq(10,deserializedint->getInt());
	test->Assert_inteq(inttoserialize->getInt(),deserializedint->getInt());
	
	delete inttoserialize;
	delete deserializedint;
	delete type;	
}

void Test_StringValue_Deserialize(TestCase* test){
	StringValue* strtoserialize=NULL;
	StringValue* deserializedstr=NULL;
	StringType* stringType=NULL;
	
	stringType=new StringType();
	//Creo un string cualquiera
	strtoserialize=new StringValue("abcdefgh123456789");
	//Serializo
	deserializedstr=(StringValue*)stringType->deserializeValue(strtoserialize->serialize());
	//Verifico que sean iguales
	test->Assert_streq("abcdefgh123456789",deserializedstr->getString());
}

//typedef T_REG
//const INTTYPE 'i';
typedef unsigned short T_RECORD_F_Q;
typedef unsigned short T_VALUE_Q;
typedef unsigned short T_FIELD_TYPE;
/*
char intToChar(int i){
	char result;
}*/

void Test_Record_Serialize(TestCase* test){
	//Cantidad,{cantidad de valores para este campo,Tipo,Valor}
	//Valor para int: "int"
	//Valor para string: largo,string
	//Valor para structured: cantidad,{Tipo,Valor}
	/*
	T_FIELD_TYPE INTTYPE=1;
	Record* record=NULL;
	char* data;
	T_RECORD_F_Q fieldqty=1;
	T_VALUE_Q valueqty=1;
	T_FIELD_TYPE fieldtype=INTTYPE;
	int intvalue=13;
	int size=sizeof(T_RECORD_F_Q)+sizeof(T_VALUE_Q)+sizeof(T_FIELD_TYPE)+sizeof(int);
	data=(char*)malloc(size);
	int offset=0;
	memcpy(data+offset,&fieldqty,sizeof(T_RECORD_F_Q));
	offset+=sizeof(T_RECORD_F_Q);
	memcpy(data+offset,&valueqty,sizeof(T_VALUE_Q));
	offset+=sizeof(T_VALUE_Q);
	memcpy(data+offset,&fieldtype,sizeof(T_FIELD_TYPE));
	offset+=sizeof(T_FIELD_TYPE);
	memcpy(data+offset,&intvalue,sizeof(int));
	record=new Record();
	printf("\n__%i__",size);
	record->deserialize(new RawRecord(data,size));
	//record->addValue(new IntValue(10));
	delete record;
	*/
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
	
	TestCase* test10=new TestCase("Test_Append",&failedTests);	
	Test_Append(test10);
	delete test10;
	
	TestCase* test11=new TestCase("Test_Block_Constructor",&failedTests);	
	Test_Block_Constructor(test11);
	delete test11;

	TestCase* test12=new TestCase("Test_Block_setContent",&failedTests);	
	Test_Block_setContent(test12);
	delete test12;	
	
	TestCase* test13=new TestCase("Test_Block_SizeAndFreeSpace",&failedTests);	
	Test_Block_SizeAndFreeSpace(test13);
	delete test13;
	
	TestCase* test14=new TestCase("Test_BlockStructured_BUpdateBlock",&failedTests);	
	Test_BlockStructured_BUpdateBlock(test14);
	delete test14;
	
	TestCase* test15=new TestCase("Test_BlockStructured_BAppendBlock",&failedTests);	
	Test_BlockStructured_bAppendContentBlock(test15);
	delete test15;
	
	/*TestCase* test16=new TestCase("Test_BlockStructured_removeLastContentBlock",&failedTests);	
	Test_BlockStructured_removeLastContentBlock(test16);
	delete test16;*/
	
	TestCase* test17=new TestCase("Test_RecordsBlock",&failedTests);	
	Test_RecordsBlock(test17);
	delete test17;
	
	TestCase* test18=new TestCase("Test_RecordsBlock_Deserialization",&failedTests);	
	Test_RecordsBlock_Deserialization(test18);
	delete test18;
	
	TestCase* test19=new TestCase("Test_RecordsBlock_RecordsManipulation",&failedTests);	
	Test_RecordsBlock_RecordsManipulation(test19);
	delete test19;
		
	TestCase* test20=new TestCase("Test_BlockStructured_DataBlockCreation",&failedTests);	
	Test_BlockStructured_DataBlockCreation(test20);
	delete test20;

	TestCase* test21_1=new TestCase("Test_IntValue_SerializeDeserialize",&failedTests);	
	Test_IntValue_SerializeDeserialize(test21_1);
	delete test21_1;
	
/*	
	TestCase* test22=new TestCase("Test_Record_Serialize",&failedTests);	
	Test_Record_Serialize(test22);
	delete test22;
	*/
	TestCase* test23=new TestCase("Test_StringValue_Deserialize",&failedTests);	
	Test_StringValue_Deserialize(test23);
	delete test23;	
	
		
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
>>--Done --> void appendBlock(char* content); (tener en cuenta que el indice tiene que estar defasado)
>>--Done --> char* getBlock(int blockNumber);
void removeBlock(int blockNumber);
Actualizar la lista de espacios libres en bloques en cada operacion
int getFirstFreeBlockNumber();
void moveBlock(int currentBlockNumber,int destBlockNumber);
virtual ~BlockStructuredFile(void);
>>--Done --> void upElq ue serdateBlock(int blockNumber,char* content);
clase block??
>>--Done --> clase header block??
>>--Done --> Cambiar loadPropertiesFromBuffer por "load header from buffer"
>>--Done --> Aclarar Indices
>>--Done --> Mover una parte de updateBlock a append block. cosa que el updateBlock solo actue cuando se actualice un bloque. Cuando se está agregando uno hay que llamar al append 
Que el block count calcule dependiendo del tamaño del archivo
>>--Done --> Espacios libres?
>>--Done --> Hacer que el record copie el array de chars que recibe
Hacer un GetSomeBlock(1 o 2 o 3) que de diferentes Blocks hardcoded
BlockStructuredFile Darle una funcion fabrica de blocks
DataType: El que serializa es el 
DataType y DataValue: Pasar cosas a superclases 
DataType: probar equals de
getSerializationSize y getContent
 */