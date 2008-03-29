#include "Statement.h"
#include <stdio.h>
#include "Utils.h"
/*
 * El parametro aName será clonado
 * */
Statement::Statement(char* fileName)
{
	_fileName=cloneStr(fileName);
}

char* Statement::getFileNamess(){
	return _fileName;	
}

Statement::~Statement()
{
	free(this->_fileName);
}
