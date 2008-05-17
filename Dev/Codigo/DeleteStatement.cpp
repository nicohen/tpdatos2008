#include "DeleteStatement.h"
#include "Utils.h"

DeleteStatement::DeleteStatement(char* filename):Statement(filename){
}


StatementResult* DeleteStatement::execute(DataManager* dataManager) {
	StatementResult* statementResult = NULL;
	string* buffer = NULL;
//	char* cadena;
	bool wasSuccessful = false;
	
	//Elimino el archivo
	wasSuccessful = dataManager->removeFile(cloneStr(this->getFileName()));
	
	statementResult = new StatementResult();
	buffer = new string();
	
	if (wasSuccessful) {
		buffer->append("'Se eliminó correctamente el archivo ");
	} else {
		buffer->append("'Se eliminó incorrectamente el archivo ");
	}
	buffer->append(this->getFileName());
	if (wasSuccessful) {
		buffer->append("' Res = 1");
	} else {
		buffer->append("' Res = 0");
	}
	
	statementResult->setResult((char*)buffer->c_str());
	
	delete buffer;
	return statementResult;
}

void DeleteStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción DeleteStatement");		
}

DeleteStatement::~DeleteStatement(){
}
