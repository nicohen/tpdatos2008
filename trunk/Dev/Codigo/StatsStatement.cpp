#include "StatsStatement.h"
#include "Utils.h"

StatsStatement::StatsStatement(char* filename):Statement(filename){
}


StatementResult* StatsStatement::execute(DataManager* anIDataManager) {
	/*
	 * OCUPADO
	 * 	DATOS  [bytes]
	 *  INDICE [bytes]
	 *  NETO   [bytes]
	 * 
	 * LIBRE
	 * 	DATOS  [bytes]
	 * 	INDICE [bytes]
	 * 
	 * CANTIDAD REGISTROS/ENTRADAS
	 * 	DATOS  [cantidad]
	 *  INDICE [cantidad]
	 * 
	 */
	StatementResult* statementResult = new StatementResult();
	string* buffer;
	char* cadena;
		
	buffer->append("OCUPADO:\n");
	
	
	cadena = (char*) malloc(strlen(buffer->c_str()));
	strcpy(cadena,buffer->c_str());
	statementResult->setResult(cadena);
	
	free(cadena);
	delete buffer;
	return new StatementResult();
}

void StatsStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción StatsStatemet");	
}

StatsStatement::~StatsStatement(){
}
