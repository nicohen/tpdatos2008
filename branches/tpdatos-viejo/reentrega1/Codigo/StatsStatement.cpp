#include "StatsStatement.h"
#include "Utils.h"
#include <sstream>

StatsStatement::StatsStatement(char* filename):Statement(filename){
}

StatementResult* StatsStatement::execute(DataManager* dataManager) {
	StatementResult* statementResult = new StatementResult();
	statementResult->setResult("Intentando Generar Estadisticas.");
	return statementResult;
}

void StatsStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción StatsStatemet");	
}

StatsStatement::~StatsStatement(){
}
