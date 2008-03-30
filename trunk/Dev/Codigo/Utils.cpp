#include "Utils.h"
#include "string.h"

char* cloneStr(char* source){
	int len=0;
	char* clon;
	len= strlen(source);
	
	clon= (char*)malloc(sizeof(char)*(len+1));
	memcpy(clon,source,len+1);
	return clon; 
}
 
bool isNumeric(char* word){
	int i=0;
	int size =strlen(word);
	while ((i<size)&& ('0'<word[i])&&(word[i]<'9')){
		i++;
	}
	return i==size;
}
