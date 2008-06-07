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
	ostringstream dataIndexUsedSpace;
	ostringstream dataFileSize;
	ostringstream dataFreeSpace;
	ostringstream dataRecordsCount;

	//Buffer de bloques
	ostringstream bufferBlocksHitsCount;
	ostringstream bufferBlocksMissCount;
	ostringstream bufferBlocksBlocksCount;
	ostringstream bufferBlocksBlocksCurrentSize;
	ostringstream bufferBlocksBlocksTotalSize;

	//Buffer de File Descriptor
	ostringstream bufferFileDescriptorHitsCount;
	ostringstream bufferFileDescriptorMissCount;
	ostringstream bufferFileDescriptorBlocksCount;
	ostringstream bufferFileDescriptorBlocksCurrentSize;
	ostringstream bufferFileDescriptorBlocksTotalSize;
	
	try{
		DataFile* dataFile = dataManager->getFile(this->getFileName());
		dataUsedSpace<<dataFile->getDataUsedSpace();
		dataFileSize<<dataFile->getFileSize();
		dataFreeSpace<<dataFile->getDataFreeSpace();
		dataRecordsCount<<dataFile->getDataRecordsCount();

		//Buffer de bloques
		bufferBlocksHitsCount<<dataManager->getBufferHitsCount();
		bufferBlocksMissCount<<dataManager->getBufferMissCount();
		bufferBlocksBlocksCount<<dataManager->getBufferBlocksCount();
		bufferBlocksBlocksCurrentSize<<dataManager->getBufferCurrentSize();
		bufferBlocksBlocksTotalSize<<dataManager->getBufferTotalSize();
		
		//Buffer de File Descriptor
		bufferFileDescriptorHitsCount<<dataManager->getFilesBufferHitsCount();
		bufferFileDescriptorMissCount<<dataManager->getFilesBufferMissCount();
		bufferFileDescriptorBlocksCount<<dataManager->getFilesBufferBlocksCount();
		bufferFileDescriptorBlocksCurrentSize<<dataManager->getFilesBufferCurrentSize();
		bufferFileDescriptorBlocksTotalSize<<dataManager->getFilesBufferTotalSize();

		buffer->append("'Estadisticas solicitadas del archivo ");
		buffer->append(this->getFileName());
		buffer->append("'\nESPACIO OCUPADO\n");
		buffer->append("\tDatos------> ");
		buffer->append(dataUsedSpace.str());
		buffer->append(" bytes\n");
		buffer->append("\tIndice-----> 0 bytes\n");
		buffer->append("\tNeto-------> ");
		buffer->append(dataFileSize.str());
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
		
		//Buffer de bloques
		buffer->append("BUFFER (BLOQUES)\n");
		//Cantidad de Hits
		buffer->append("\tHits-------------> ");
		buffer->append(bufferBlocksHitsCount.str());
		//Cantidad de Miss
		buffer->append("\n\tMiss-------------> ");
		buffer->append(bufferBlocksMissCount.str());
		//Cantidad de Bloques
		buffer->append("\n\tBloques----------> ");
		buffer->append(bufferBlocksBlocksCount.str());
		//Cantidad de Bloques
		buffer->append("\n\tTamaño actual----> ");
		buffer->append(bufferBlocksBlocksCurrentSize.str());
		//Cantidad de Bloques
		buffer->append("\n\tTamaño total-----> ");
		buffer->append(bufferBlocksBlocksTotalSize.str());
		
		//Buffer del File Descriptor
		buffer->append("\nBUFFER (FILE DESCRIPTOR)\n");
		//Cantidad de Hits
		buffer->append("\tHits-------------> ");
		buffer->append(bufferFileDescriptorHitsCount.str());
		//Cantidad de Miss
		buffer->append("\n\tMiss-------------> ");
		buffer->append(bufferFileDescriptorMissCount.str());
		//Cantidad de Bloques
		buffer->append("\n\tBloques----------> ");
		buffer->append(bufferFileDescriptorBlocksCount.str());
		//Cantidad de Bloques
		buffer->append("\n\tTamaño actual----> ");
		buffer->append(bufferFileDescriptorBlocksCurrentSize.str());
		//Cantidad de Bloques
		buffer->append("\n\tTamaño total-----> ");
		buffer->append(bufferFileDescriptorBlocksTotalSize.str());
		buffer->append("\n");
		dataFile->toString(buffer);
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
