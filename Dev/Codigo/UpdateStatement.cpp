#include "UpdateStatement.h"
#include "Utils.h"

UpdateStatement::UpdateStatement(char* filename):Statement(filename){
}


StatementResult* UpdateStatement::execute(DataManager* anIDataManager){
	return new StatementResult();
}

void UpdateStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutputter->printLine("Sé ejecutó la instrucción UpdateStatement");	
}

UpdateStatement::~UpdateStatement(){
}
