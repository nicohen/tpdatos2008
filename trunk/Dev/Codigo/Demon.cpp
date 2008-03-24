#include "Demon.h"

Demon::Demon(int sleepTime, int bufferSize, bool vervose){
	_sleepTime= sleepTime;
	_bufferSize= bufferSize;
	_vervose= vervose;
}

void Demon::run(void){
	FileInfo *input;
	for(int i=0;i<10;i++){
		printf("Hello from Hell!\n");
		input= new FileInfo("IN/pablo.txt");
		delete input;
		sleep(_sleepTime);
	}
}

Demon::~Demon(){
}
