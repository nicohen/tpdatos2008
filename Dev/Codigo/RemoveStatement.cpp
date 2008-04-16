#include "RemoveStatement.h"
#include "Utils.h"
#include "IntValue.h"
#include "StringValue.h"
#include "StructureValue.h"
#include <sstream>

RemoveStatement::RemoveStatement(char* filename):Statement(filename){
}


StatementResult* RemoveStatement::execute(DataManager* anIDataManager){
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
	struc->addValue(new StringValue("inside struct1"));
	struc->addValue(new StringValue("inside struct2"));
	struc->addValue(new StringValue("inside struct3"));
	rec->addValue(new IntValue(10));
	rec->addValue(new StringValue("sdasdasd"));	
	rec->addValue(new IntValue(11));
	rec->addValue(struc);
	
	out<<this->getFieldNumber();
	intToString = out.str();

	buffer.append("'Se eliminaron los registros con valor ['");
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

void RemoveStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción RemoveStatement");	
}

RemoveStatement::~RemoveStatement(){
}

void RemoveStatement::setFieldNumber(int fieldNumber){
	_fieldNumber= fieldNumber;
}
int RemoveStatement::getFieldNumber(){
	return _fieldNumber;
}
void RemoveStatement::setValue(DataValue* value){
	_value= value;
}
DataValue* RemoveStatement::getValue(){
	return _value;
}
