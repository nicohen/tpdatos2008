#include "stdio.h"
#include "stdlib.h"
#include "Data/MetadataBlock.h"
#include "FileManager.h"
#include "Field.h"
#include "StringType.h"
#include "IntType.h"
#include "StructureType.h"
#include "Utils.h"

//bool verbose = false;

int _main(int argc, char **argv) {
	FILE* salida;
	FILE* entrada;
	Field* field;
	StringType* sType= new StringType();
	IntType* iType= new IntType();
	StructureType* ssType= new StructureType();
	MetadataBlock* metadata= new MetadataBlock(512);
	MetadataBlock* metadata2= new MetadataBlock(512);
	metadata->setFileType(2);
	/**/
	ssType->addType(new StringType());
	ssType->addType(new IntType());
	/**/
	field= new Field();
	field->setIsMandatory(true);
	field->setIsPolyvalent(true);
	field->setDataType(sType);
	metadata->setSecondaryField(field);
	/**/
	field= new Field();
	field->setIsMandatory(true);
	field->setIsPolyvalent(true);
	field->setDataType(iType);
	metadata->setSecondaryField(field);
	/**/
	field= new Field();
	field->setIsMandatory(true);
	field->setIsPolyvalent(true);
	field->setDataType(ssType);
	metadata->setSecondaryField(field);
	/**/
	salida= fopen("Data/Meta.txt","w+");
	fwrite (metadata->getContent() , 1 , metadata->getSize() , salida );
	fclose(salida);
	
	entrada= fopen("Data/Meta.txt","r+");
	char* buffer= (char*)malloc(512*sizeof(char));
	fread(buffer,1,512,entrada);
	metadata2=new MetadataBlock(buffer,512);	
	fclose(entrada);
	free(buffer);
	delete metadata;
	delete metadata2;
	printf("sdasdasd");
	return 0;
}
