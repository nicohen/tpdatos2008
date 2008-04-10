#include "stdafx.h"

#include "Common.h"
#include "string.h"
#include "stdio.h"

char* cloneStr(char* source){
	int len=0;
	char* clon;
	len= strlen(source);
	
	clon= (char*)malloc(sizeof(char)*(len+1));
	memcpy(clon,source,len+1);
	return clon; 
}


bool hadSuccessRemoving(int removeResponse){
	return removeResponse==0;
}