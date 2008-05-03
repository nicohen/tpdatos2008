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
#include "IOException.h"

Demon::Demon(int sleepTime, int bufferSize){
	_sleepTime= sleepTime;
	_bufferSize= bufferSize;
	_finishDaemon = false;
}

void Demon::run(void){
	FileManager::FileManager* fileManager = new FileManager::FileManager();
	FileManager::FileInfo* inputFile = NULL;
	OutPutter::OutPutter* outPutter = NULL;
	DataManager* dataManager = new DataManager("Data/",_bufferSize);
	BufferedDataManager* bufferedDataManager = new BufferedDataManager(dataManager); 
	
	for(int i=1;!_finishDaemon;i++) {
		try{
			inputFile = fileManager->CreateFileInfo("In/Comando.7506");
			
			inputFile->open();
			
			outPutter = new OutPutter(fileManager);
			DEBUG("Inicio escritura de archivo");
			outPutter->writeOutputFile(inputFile);
			DEBUG("Archivo copiado correctamente");

			processInputStatements(bufferedDataManager, outPutter, inputFile);

			inputFile->close();
			//inputFile->delet();
			
			delete inputFile;
			delete outPutter;

		} catch (FileManager::IOException e){
		} 
		sleep(_sleepTime);

	}
	delete fileManager;
	DEBUG("Fin del programa");
}

Demon::~Demon(){
}

void Demon::processInputStatements(BufferedDataManager* bufferedDataManager, OutPutter* outPutter, FileManager::FileInfo* inputFile) {
	Statement* statement = NULL;
	bool fin=false;

	char delimiters[]= {' ','[',']',';',',','\n','|','+','*'};
	char* keywords[]= {"CREAR","CONSULTA","hash","INGRESAR","QUITAR","ELIMINAR","ESTADISTICA","FINALIZAR","ACTUALIZAR","secuencial","indexado","secIndexado","int","string"};
 	
 	Parsing::Tokenizer* tokenizer = new Parsing::Tokenizer(inputFile,'\'',delimiters,9,keywords,14);
	StatementParser* statementParser = new StatementParser(tokenizer,outPutter);
	StatementResult* statementResult = new StatementResult();
	
	while (!fin) {
		try {
			statement = statementParser->getNext();
			if(statement==NULL){
				fin=true;
				break;
			}
			statementResult = bufferedDataManager->executeStatement(statement,outPutter);
			statementResult->write(outPutter);
			delete statementResult;
			delete statement;
		} catch(KillDaemonException* kde) {
			DEBUG("KILL DAEMON");
			_finishDaemon = true;
			fin=true;
			delete kde;
		} catch(FileManager::IOException* ioe) {
			DEBUG("Fin de archivo.");
			fin=true;
			delete ioe;
		} catch(StatementParserException* spe) {
			outPutter->printLine(spe->getMessage());
			delete spe;
		}
	}
	
	delete statementParser;
	delete tokenizer;

}
