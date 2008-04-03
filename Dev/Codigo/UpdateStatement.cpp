#include "UpdateStatement.h"
#include "Utils.h"

UpdateStatement::UpdateStatement(char* filename):Statement(filename){
}


void UpdateStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción UpdateStatement");
}

UpdateStatement::~UpdateStatement(){
}
