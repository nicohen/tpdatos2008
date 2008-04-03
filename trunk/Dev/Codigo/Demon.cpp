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

Demon::Demon(int sleepTime, int bufferSize, bool verbose){
	_sleepTime= sleepTime;
	_bufferSize= bufferSize;
	_verbose = verbose;
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
			
			outPutter = new OutPutter(fileManager, true);
			outPutter->debug("Inicio escritura de archivo");
			outPutter->writeOutputFile(inputFile);
			outPutter->debug("Archivo copiado correctamente");
			outPutter->printLine("Todas las cosas que puedan salir al archivo OUT");
			outPutter->printLine("Mas cosas...");
			outPutter->debug("Fin escritura de archivo");

			processInputStatements(bufferedDataManager, outPutter, inputFile);

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
		statement = statementParser->getNext();
		while ((statement = statementParser->getNext()) != NULL) {
			bufferedDataManager->executeStatement(statement,outPutter);
			delete statement;
		}
	} catch(KillDaemonException* kde) {
		_finishDaemon = true;
		debug("Se llamo a la instruccion finalizar");
	}
	
	delete statementParser;
	delete tokenizer;

}
