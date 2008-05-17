#include "Utils.h"
#include "string.h"
#include "stdio.h"
#include <fstream>

using namespace std;
char* cloneStr(const char* source){
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

void DEBUG_CONDITIONAL(const char* words){
	extern bool verbose;
	if (verbose && false){
		printf("%s\n",words);
	}
}

bool isNumeric(char* word){
	int i=0;
	int size =strlen(word);
	if (size==0){
		return false;
	}
	if ((word[i]=='+')||(word[i]=='-')){
		i++;
	}
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

unsigned int ElHashDeCubillas(char* str) {
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;

   for(size_t i = 0; i < strlen(str); i++) {
      hash = hash * a + str[i];
      a    = a * b;
   }

   return hash;
}

bool hadSuccessRemoving(int removeResponse){
	return removeResponse==0;
}
