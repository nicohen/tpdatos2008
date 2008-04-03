#include "Demon.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"
#include "FileInfo.h"
#include "FileManager.h"
#include "KillDaemonException.h"
#include "StatementParser.h"
#include "Tokenizer.h"

Demon::Demon(int sleepTime, int bufferSize){
	_sleepTime= sleepTime;
	_bufferSize= bufferSize;
	_finishDaemon = false;
}

void Demon::run(void){
	FileManager::FileManager* fileManager = new FileManager::FileManager();
	FileManager::FileInfo* inputFile = NULL;
	OutPutter::OutPutter* outPutter = NULL;
	DataManager* dataManager = new DataManager();
	BufferedDataManager* bufferedDataManager = new BufferedDataManager(dataManager); 
	
	for(int i=1;!_finishDaemon;i++) {
		try{
			printf("Iteracion: %i\n",i);
			inputFile = fileManager->CreateFileInfo("In/Comandos.7506");
			
			inputFile->open();
			
			outPutter = new OutPutter(fileManager);
			DEBUG("Inicio escritura de archivo");
			outPutter->writeOutputFile(inputFile);
			DEBUG("Archivo copiado correctamente");

			processInputStatements(bufferedDataManager, outPutter, inputFile);

			outPutter->printLine("Escribo en el archivo Out...");
			DEBUG("Fin escritura en archivo Out");

			
			inputFile->close();
			inputFile->delet();
			
			delete inputFile;
			delete outPutter;

		} catch (FileManager::IOException e){
			printf("file not found!\n");
		} 
		sleep(_sleepTime);

	}
	delete fileManager;
	debug("Fin del programa");
}

Demon::~Demon(){
}

void Demon::debug(char* msg) {
	printf("%s\n",msg);
}

void Demon::processInputStatements(BufferedDataManager* bufferedDataManager, OutPutter* outPutter, FileManager::FileInfo* inputFile) {
	Statement* statement = NULL;

	char delimiters[]= {' ','[',']',';',',','\n','|'};
	char* keywords[]= {"CREAR","CONSULTAR","hash","INGRESAR","QUITAR","ELIMINAR","ESTADISTICA","FINALIZAR","ACTUALIZAR","secuencial","indexado","secIndexado"};
 	
 	Parsing::Tokenizer* tokenizer = new Parsing::Tokenizer(inputFile,'\'',delimiters,7,keywords,12);
	StatementParser* statementParser = new StatementParser(tokenizer,outPutter);

	try {
		statement = statementParser->getNext();
		while (statement != NULL) {
			bufferedDataManager->executeStatement(statement,outPutter);
			delete statement;
			statement = statementParser->getNext();
		}
	} catch(KillDaemonException* kde) {
		_finishDaemon = true;
		debug("Se llamo a la instruccion finalizar");
	}
	
	delete statementParser;
	delete tokenizer;

}
