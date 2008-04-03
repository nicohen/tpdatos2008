#include "RemoveStatement.h"
#include "Utils.h"

RemoveStatement::RemoveStatement(char* filename):Statement(filename){
}


void RemoveStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción RemoveStatement");
}

RemoveStatement::~RemoveStatement(){
}
