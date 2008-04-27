#ifndef UTILS_H_
#define UTILS_H_

#include "string.h"
#include "stdlib.h"

char* cloneStr(const char* source);
bool isNumeric(char* word);
void DEBUG(const char* word);
bool existsFile(char* filename);
bool hadSuccessRemoving(int removeResponse);
#endif /*UTILS_H_*/
