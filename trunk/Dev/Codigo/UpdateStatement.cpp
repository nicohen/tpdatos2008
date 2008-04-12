#include "UpdateStatement.h"
#include "Utils.h"

UpdateStatement::UpdateStatement(char* filename):Statement(filename){
	_values= new std::vector<DataValue*>();
}


StatementResult* UpdateStatement::execute(DataManager* anIDataManager){
	return new StatementResult();
}

void UpdateStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción UpdateStatement");	
}

UpdateStatement::~UpdateStatement(){
}
void UpdateStatement::addValues(std::vector<DataValue*>* valueList){
	vector<DataValue*>::iterator iter;
	for (iter = valueList->begin(); iter != valueList->end(); iter++ ){
		_values->push_back(*iter);
	}
	delete valueList;
}
