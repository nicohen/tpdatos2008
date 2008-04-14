#include "QueryStatement.h"
#include "Utils.h"
#include "string.h"
#include "Data/RecordsBlock.h"
#include <sstream>

QueryStatement::QueryStatement(char* filename):Statement(filename){
}

StatementResult* QueryStatement::execute(DataManager* dataManager) {
	// obtener bloque por bloque
	// llenar cada RecordBlock con un bloque
	// devuelve un array de bytes
	// tengo que crear un record a partir de un array de bytes que devuelve el recordblock

//	vector<RawRecord*>* rawRecords;
//	RecordsBlock* recordsBlock;
//	RawRecord* rawRecord;
//	Record* record;
//	DataValue* dataValue;
//	
//	DataFile* df = dataManager->getFile(this->getFileName());
//	//TODO - Meter el BlockStructuredFile dentro del DataFile
//	BlockStructuredFile* bsf = df->getBlockStructuredFile();
//	for (int i=0; i<bsf->getContentBlockCount(); i++) {
//		recordsBlock = (RecordsBlock*)bsf->bGetContentBlock(i,&(df->createRecordsBlock));
//		rawRecords = recordsBlock->getRecords();
//		vector<RawRecord*>::iterator iter;
//		for(iter = rawRecords->begin(); iter != rawRecords->end(); iter++) {
//			//Chequear si el contenido concuerda
//			if (((RawRecord*)*iter)->getContent())
//			rawRecord = ((RawRecord*)*iter);
//		}
//	}

	StatementResult* sr = new StatementResult();
	
	char* cadena; 
	string buffer;
	string intToString;
	stringstream out;
	
	out<<this->getFieldNumber();
	intToString = out.str();
	
	buffer.append("'Se consulto por registros con valor ['");
//	buffer.append(dataValue->toString());
	buffer.append("pepito"); //hardcodeado
	buffer.append("'] en campo [");
//	buffer.append(intToString);
	buffer.append("0"); //hardcodeado
	buffer.append("]' ");
	buffer.append("Res = ['");
//	buffer.append(dataValue->toString());
	buffer.append("pepito"); //hardcodeado
	buffer.append("',");
//	buffer.append(intToString);
	buffer.append("5"); //hardcodeado
	buffer.append(",|...|]"); //hardcodeado

	cadena = (char*) malloc(strlen(buffer.c_str()));
	strcpy(cadena,buffer.c_str());
	sr->setResult(cadena);

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
