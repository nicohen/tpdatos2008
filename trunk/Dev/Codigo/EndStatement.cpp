#include "EndStatement.h"
#include "Utils.h"

EndStatement::EndStatement(char* filename):Statement(filename){
}


void EndStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción EndStatement");
}

EndStatement::~EndStatement(){
}
