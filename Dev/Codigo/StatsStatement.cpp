#include "StatsStatement.h"
#include "Utils.h"
#include <sstream>

StatsStatement::StatsStatement(char* filename):Statement(filename){
}

StatementResult* StatsStatement::execute(DataManager* dataManager) {
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
	 */
	StatementResult* statementResult = new StatementResult();
	string* buffer = new string();
	char* cadena;
	ostringstream dataUsedSpace;
	ostringstream fileSize;
	ostringstream dataFreeSpace;
	ostringstream dataRecordsCount;
	ostringstream hitsCount;
	ostringstream missCount;
	ostringstream bufferBlocksCount;
	ostringstream bufferBlocksCurrentSize;
	ostringstream bufferBlocksTotalSize;
	
	try{
		DataFile* dataFile = dataManager->getFile(this->getFileName());
		dataUsedSpace<<dataFile->getDataUsedSpace();
		fileSize<<dataFile->getFileSize();
		dataFreeSpace<<dataFile->getDataFreeSpace();
		dataRecordsCount<<dataFile->getDataRecordsCount();
		hitsCount<<dataManager->getBufferHitsCount();
		missCount<<dataManager->getBufferMissCount();
		bufferBlocksCount<<dataManager->getBufferBlocksCount();
		bufferBlocksCurrentSize<<dataManager->getBufferCurrentSize();
		bufferBlocksTotalSize<<dataManager->getBufferTotalSize();

		buffer->append("'Estadisticas solicitadas del archivo ");
		buffer->append(this->getFileName());
		buffer->append("'\nESPACIO OCUPADO\n");
		buffer->append("\tDatos------> ");
		buffer->append(dataUsedSpace.str());
		buffer->append(" bytes\n");
		buffer->append("\tIndice-----> 0 bytes\n");
		buffer->append("\tNeto-------> ");
		buffer->append(fileSize.str());
		buffer->append(" bytes\n");
		buffer->append("ESPACIO LIBRE\n");
		buffer->append("\tDatos------> ");
		buffer->append(dataFreeSpace.str());
		buffer->append(" bytes\n");
		buffer->append("\tIndice-----> 0 bytes\n");
		buffer->append("CANTIDAD REGISTROS/ENTRADAS\n");
		buffer->append("\tDatos------> ");
		buffer->append(dataRecordsCount.str());
		buffer->append(" registros\n");
		buffer->append("\tIndice-----> 0 registros\n");
		buffer->append("BUFFER\n");
		//Cantidad de Hits
		buffer->append("\tHits-------------> ");
		buffer->append(hitsCount.str());
		//Cantidad de Miss
		buffer->append("\n\tMiss-------------> ");
		buffer->append(missCount.str());
		//Cantidad de Bloques
		buffer->append("\n\tBloques----------> ");
		buffer->append(bufferBlocksCount.str());
		//Cantidad de Bloques
		buffer->append("\n\tTamaño actual----> ");
		buffer->append(bufferBlocksCurrentSize.str());
		//Cantidad de Bloques
		buffer->append("\n\tTamaño total-----> ");
		buffer->append(bufferBlocksTotalSize.str());
	}catch(FileNotFoundException* ex){
		buffer->append(" Error al buscar registros(");
		buffer->append(ex->toString());
		buffer->append("). Res=0"); 
		delete ex;
	}	
	
	cadena = cloneStr(buffer->c_str()); 
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
