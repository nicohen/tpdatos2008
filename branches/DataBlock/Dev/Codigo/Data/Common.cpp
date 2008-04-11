#include "stdafx.h"

#include "Common.h"
#include "string.h"
#include "stdio.h"
#include <fstream>

using namespace std;

char* cloneStr(char* source){
	int len=0;
	char* clon;
	len= strlen(source);
	
	clon= (char*)malloc(sizeof(char)*(len+1));
	memcpy(clon,source,len+1);
	return clon; 
}

bool existsFile(char* filename){
	fstream* existingFile=NULL;
	existingFile = new fstream(filename,ios::in|ios::binary);
	if(existingFile->is_open()){
		//Error, llamando al crear cuando ya existe el archivo
		existingFile->close();
		delete existingFile;
		return true;
	}
	delete existingFile;
	return false;
}



bool hadSuccessRemoving(int removeResponse){
	return removeResponse==0;
}