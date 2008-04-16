#include "StatsStatement.h"
#include "Utils.h"
//#include <stddef.h>
//#include <stdio.h>
//#include <sys/types.h>
//#include <dirent.h>


StatsStatement::StatsStatement(char* filename):Statement(filename){
}


StatementResult* StatsStatement::execute(DataManager* anIDataManager) {
	/*
	 * OCUPADO
	 * 	DATOS  [bytes]
	 *  INDICE [bytes]
	 *  NETO   [bytes]
	 * 
	 * LIBRE
	 * 	DATOS  [bytes]
	 * 	INDICE [bytes]
	 * 
	 * CANTIDAD REGISTROS/ENTRADAS
	 * 	DATOS  [cantidad]
	 *  INDICE [cantidad]
	 * 
	 * en el datafile
	 * getDataSize (devuelve un T_FILE_SIZE) -->implementar
	 * 		recorrer todos los recordsblock y acumular el getUsedSpace-->implementar
	 * 
	 */
	StatementResult* statementResult = new StatementResult();
	string* buffer = new string();
	char* cadena;
		
//	DIR* dp;
//	struct dirent* ep;
//	
//	dp = opendir("./");
//	if (dp!=NULL) {
//		while(ep=readdir(dp)) {
//			puts(ep->d_name);
//		}
//		(void)closedir(dp);
//	} else {
//		perror("Couldn't open the directory");
//	}
//
//	printf("[chars:");
//	for(int i=0;i<256;i++) {
//		printf("%c",ep->d_name[i]);
//	}
//	printf("]");
	
	buffer->append("OCUPADO:\n");
	
	//recorrer archivos del directorio y traer el datausedspace
	DataFile* dataFile = anIDataManager->getFile(this->getFileName());
	printf("[OCUPADO DATOS             = %i bytes]\n",dataFile->getDataUsedSpace());
	printf("[OCUPADO INDICE            = 0 bytes]\n");
	printf("[OCUPADO NETO              = %i bytes]\n",dataFile->getFileSize());
	printf("[LIBRE DATOS               = %i bytes]\n",dataFile->getDataFreeSpace());
	printf("[LIBRE INDICE              = 0 bytes]\n");
	printf("[CANTIDAD REGISTROS DATOS  = %i bytes]\n",dataFile->getDataRecordsCount());
	printf("[CANTIDAD REGISTROS INDICE = 0 bytes]\n");
	
	cadena = (char*) malloc(strlen(buffer->c_str()));
	strcpy(cadena,buffer->c_str());
	statementResult->setResult(cadena);
	
	free(cadena);
	delete buffer;
	return statementResult;
}

void StatsStatement::writeStatementQuery(OutPutter* anOutPutter) {
	anOutPutter->printLine("Sé ejecutó la instrucción StatsStatemet");	
}

StatsStatement::~StatsStatement(){
}
