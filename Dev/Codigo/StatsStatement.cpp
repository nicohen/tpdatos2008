#include "StatsStatement.h"
#include "Utils.h"

StatsStatement::StatsStatement(char* filename):Statement(filename){
}


StatementResult* StatsStatement::execute(DataManager* anIDataManager){
	return new StatementResult();
}

void StatsStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutputter->printLine("Sé ejecutó la instrucción StatsStatemet");	
}

StatsStatement::~StatsStatement(){
}
