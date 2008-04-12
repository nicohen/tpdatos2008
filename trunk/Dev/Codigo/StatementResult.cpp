#include "StatementResult.h"

StatementResult::StatementResult()
{
}

StatementResult::~StatementResult()
{
}

bool StatementResult::wasOk(){
	return true;
}

/*
vector<Registry*>* StatementResult::getFoundRegistries(){
	return 0;
}
*/
void StatementResult::write(OutPutter* outputter){
	//Escribe el resultado en el outputter	
}
