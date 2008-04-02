#include "Demon.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"
#include "FileInfo.h"
#include "FileManager.h"
#include "OutPutter.h"

Demon::Demon(int sleepTime, int bufferSize, bool verbose){
	_sleepTime= sleepTime;
	_bufferSize= bufferSize;
	_verbose = verbose;
}

void Demon::run(void){
	FileManager::FileManager* fileManager = new FileManager::FileManager();
	FileManager::FileInfo* inputFile = NULL;
	OutPutter::OutPutter* outPutter = NULL;
	for(int i=1;;i++) {
		try{
			printf("Iteracion: %i\n",i);
			inputFile = fileManager->CreateFileInfo("In/Comandos.7506");
			
			inputFile->open();
			
			outPutter = new OutPutter(fileManager, inputFile, true);
			outPutter->debug("Inicio escritura de archivo");
			outPutter->debug("Archivo copiado correctamente");
			outPutter->printLine("Todas las cosas que puedan salir al archivo OUT");
			outPutter->printLine("Mas cosas...");
			outPutter->debug("Fin escritura de archivo");

			inputFile->delet();
			
			delete outPutter;
			delete inputFile;

			inputFile->close();

		} catch(FileManager::IOException e){
			printf("file not found!\n");
		}
		sleep(_sleepTime);

	}
	delete fileManager;
}

Demon::~Demon(){
}
