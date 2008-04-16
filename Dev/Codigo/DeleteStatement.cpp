#include "DeleteStatement.h"
#include "Utils.h"

DeleteStatement::DeleteStatement(char* filename):Statement(filename){
}


StatementResult* DeleteStatement::execute(DataManager* dataManager) {
	StatementResult* statementResult = NULL;
	string* buffer = NULL;
	char* cadena;
	bool wasSuccessful = false;
	
	//Elimino el archivo
	wasSuccessful = dataManager->removeFile(this->getFileName());
	
	statementResult = new StatementResult();
	buffer = new string();
	
	if (wasSuccessful) {
		buffer->append("Se eliminó correctamente el archivo: ");
	} else {
		buffer->append("Se eliminó incorrectamente el archivo: ");
	}
	buffer->append(this->getFileName());
	if (wasSuccessful) {
		buffer->append(" RES=1");
	} else {
		buffer->append(" RES=0");
	}
	
	cadena = (char*) malloc(strlen(buffer->c_str()));
	strcpy(cadena,buffer->c_str());
	
	statementResult->setResult(cadena);
	
	delete buffer;
	return statementResult;
}

void DeleteStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción DeleteStatement");		
}

DeleteStatement::~DeleteStatement(){
}
