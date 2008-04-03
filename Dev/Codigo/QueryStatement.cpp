#include "QueryStatement.h"
#include "Utils.h"

QueryStatement::QueryStatement(char* filename):Statement(filename){
}


void QueryStatement::execute(void* anIDataManager, OutPutter* anOutputter){
	anOutputter->printLine("Sé ejecutó la instrucción ConsultStatemet");
}

QueryStatement::~QueryStatement(){
}
