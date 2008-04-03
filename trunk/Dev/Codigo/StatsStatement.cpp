#include "StatsStatement.h"
#include "Utils.h"

StatsStatement::StatsStatement(char* filename):Statement(filename){
}


void StatsStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción StataStatement");
}

StatsStatement::~StatsStatement(){
}
