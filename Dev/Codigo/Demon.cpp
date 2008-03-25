#include "Demon.h"

Demon::Demon(int sleepTime, int bufferSize, bool vervose){
	_sleepTime= sleepTime;
	_bufferSize= bufferSize;
	_vervose= vervose;
}

void Demon::run(void){
	FileManager::FileInfo *input;
	for(int i=0;i<10;i++){
		input= new FileManager::FileInfo("In/pablo.txt");
		try{
			input->open();
			printf("A file was found!\n");
			input->close();
		}catch(FileManager::IOException e){
			printf("file not found!\n");
			sleep(_sleepTime);			
		}
		delete input;		
	}
}

Demon::~Demon(){
}
