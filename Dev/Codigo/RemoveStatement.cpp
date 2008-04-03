#include "RemoveStatement.h"
#include "Utils.h"

RemoveStatement::RemoveStatement(char* filename):Statement(filename){
}


StatementResult* RemoveStatement::execute(DataManager* anIDataManager){
	return new StatementResult();
}

void RemoveStatement::writeStatementQuery(OutPutter* anOutPutter) {
		anOutputter->printLine("Sé ejecutó la instrucción RemoveStatement");	
}

RemoveStatement::~RemoveStatement(){
}
