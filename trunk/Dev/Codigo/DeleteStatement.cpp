#include "DeleteStatement.h"
#include "Utils.h"

DeleteStatement::DeleteStatement(char* filename):Statement(filename){
}


StatementResult* DeleteStatement::execute(DataManager* anIDataManager) {
	return new StatementResult();
}

void DeleteStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción DeleteStatement");		
}

DeleteStatement::~DeleteStatement(){
}
