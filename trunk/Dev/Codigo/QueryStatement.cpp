#include "QueryStatement.h"
#include "Utils.h"
#include "string.h"
#include "Data/RecordsBlock.h"
#include <sstream>
#include "IntValue.h"
#include "StringValue.h"
#include "StructureValue.h"

QueryStatement::QueryStatement(char* filename):Statement(filename){
}

StatementResult* QueryStatement::execute(DataManager* dataManager) {
	DataFile* dFile= dataManager->getFile(this->getFileName());
	vector<Record*>* list= dFile->findRecords(this->getFieldNumber(),this->getValue());
	Record* each=NULL;
	vector<Record*>::iterator iter;
	printf("Elementos encontrados %d\n",list->size());
	for (iter = list->begin(); iter != list->end(); iter++ ){
		each=((Record*)*iter);
		string* str= new string();
		each->toString(str);
		DEBUG(str->c_str());
		delete str;
	}
	StatementResult* sr= new StatementResult();
	sr->setResult("SALIO TODO OK!!!!");
	return sr;
}

void QueryStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción QueryStatemet");	
}

QueryStatement::~QueryStatement(){
}

void QueryStatement::setFieldNumber(int fieldNumber){
	_fieldNumber= fieldNumber;
}
int QueryStatement::getFieldNumber(){
	return _fieldNumber;
}
void QueryStatement::setValue(DataValue* value){
	_value= value;
}
DataValue* QueryStatement::getValue(){
	return _value;
}
