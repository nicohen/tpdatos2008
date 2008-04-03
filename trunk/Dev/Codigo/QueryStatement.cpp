#include "QueryStatement.h"
#include "Utils.h"

QueryStatement::QueryStatement(char* filename):Statement(filename){
}


StatementResult* QueryStatement::execute(DataManager* anIDataManager){
	return new StatementResult();
}

void QueryStatement::writeStatementQuery(OutPutter* anOutPutter) {
		anOutputter->printLine("Sé ejecutó la instrucción QueryStatemet");	
}

QueryStatement::~QueryStatement(){
}
