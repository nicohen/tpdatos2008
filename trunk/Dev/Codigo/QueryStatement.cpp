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
//		recordsBlock = (RecordsBlock*)bsf->bGetContentBlock(i,&(RecordsBlock::createRecordsBlock));
//		rawRecords = recordsBlock->getRecords();
//		vector<RawRecord*>::iterator iter;
//		for(iter = rawRecords->begin(); iter != rawRecords->end(); iter++) {
//			//Chequear si el contenido concuerda
//			if (((RawRecord*)*iter)->getContent())
//			rawRecord = ((RawRecord*)*iter);
//		}
//	}

	Record* rec=NULL;
	StructureValue* struc=NULL;
	StatementResult* sr = new StatementResult();
	
	char* cadena; 
	string buffer;
	string intToString;
	stringstream out;
	
	rec=new Record();
	struc=new StructureValue();
	struc->addValue(new StringValue("inside query struct1"));
	struc->addValue(new StringValue("inside query struct2"));
	struc->addValue(new StringValue("inside query struct3"));
	rec->addValue(new IntValue(10));
	rec->addValue(new StringValue("query sdasdasd"));	
	rec->addValue(new IntValue(11));
	rec->addValue(struc);
	
	out<<this->getFieldNumber();
	intToString = out.str();
	
	buffer.append("'Se consulto por registros con valor ['");
//	buffer.append(dataValue->toString());
	buffer.append("pepito"); //hardcodeado
	buffer.append("'] en campo [");
//	buffer.append(intToString);
	buffer.append("0"); //hardcodeado
	buffer.append("]' ");
	buffer.append("Res = ");
	rec->toString(&buffer);
//	buffer.append(dataValue->toString());
//	buffer.append("pepito"); //hardcodeado
//	buffer.append("',");
//	buffer.append(intToString);
//	buffer.append("5"); //hardcodeado
//	buffer.append(",|...|]"); //hardcodeado

	cadena = (char*) malloc(strlen(buffer.c_str()));
	strcpy(cadena,buffer.c_str());
	sr->setResult(cadena);

	delete rec;
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
