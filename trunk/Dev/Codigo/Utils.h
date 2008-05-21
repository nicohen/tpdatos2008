#ifndef UTILS_H_
#define UTILS_H_

#include <string>
#include "string.h"

using namespace std;

char* cloneStr(const char* source);
bool isNumeric(char* word);
void DEBUG(const char* word);
void DEBUG_CONDITIONAL(const char* word);
int pepe();
void appendIntTo(string* str, int number);
void DEBUGS(string* pepe);
bool existsFile(char* filename);
bool hadSuccessRemoving(int removeResponse);
unsigned int ElHashDeCubillas(char* str);
#endif /*UTILS_H_*/
