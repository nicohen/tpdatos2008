#include "EndStatement.h"
#include "Utils.h"
#include "OutPutter.h"

EndStatement::EndStatement(char* filename):Statement(filename){
}


StatementResult* EndStatement::execute(DataManager* anIDataManager){
	StatementResult* sr = new StatementResult();
	
	sr->setResult((char*)"El programa finaliza su ejecución");
	return sr;
}

void EndStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción EndStatement");
}

EndStatement::~EndStatement(){
}
