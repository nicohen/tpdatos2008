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
	FileManager::FileInfo *input;
	for(int i=0;i<10;i++){
		input = fileManager->CreateFileInfo("In/Comandos.7506");
		try{
			input->open();
			input->close();
		}catch(FileManager::IOException e){
			printf("file not found!\n");
			sleep(_sleepTime);			
		}
		delete input;		
	}
	delete fileManager;
}

Demon::~Demon(){
}
