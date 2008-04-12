#include "Utils.h"
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

void DEBUG(const char* words){
	extern bool verbose;
	if (verbose){
		printf("%s\n",words);
	}
}

bool isNumeric(char* word){
	int i=0;
	int size =strlen(word);
	while ((i<size)&& ('0'<=word[i])&&(word[i]<='9')){
		i++;
	}
	return i==size;
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
