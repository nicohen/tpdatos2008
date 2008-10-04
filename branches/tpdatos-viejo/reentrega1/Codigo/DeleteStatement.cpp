#include "DeleteStatement.h"
#include "Utils.h"

DeleteStatement::DeleteStatement(char* filename):Statement(filename){
}


StatementResult* DeleteStatement::execute(DataManager* dataManager) {
	StatementResult* statementResult = new StatementResult();
	statementResult->setResult("Intentando Eliminar Archivo.");
	return statementResult;
}

void DeleteStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción DeleteStatement");		
}

DeleteStatement::~DeleteStatement(){
}
