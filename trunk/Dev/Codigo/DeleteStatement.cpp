#include "DeleteStatement.h"
#include "Utils.h"

DeleteStatement::DeleteStatement(char* filename):Statement(filename){
}


void DeleteStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción RemoveStatement");
}

DeleteStatement::~DeleteStatement(){
}
