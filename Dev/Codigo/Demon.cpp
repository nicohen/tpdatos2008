#include "Demon.h"
#include "Tokenizer.h"
#include "Token.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "unistd.h"
#include "FileInfo.h"
#include "FileManager.h"

Demon::Demon(int sleepTime, int bufferSize, bool vervose){
	_sleepTime= sleepTime;
	_bufferSize= bufferSize;
	_vervose= vervose;
}

void Demon::run(void){
	FileManager::FileManager* fileManager = new FileManager::FileManager();
	FileManager::FileInfo *input;
	Parcers::Tokenizer *tokenizer;
	Parcers::Token *token;
	for(int i=0;i<10;i++){
		input = fileManager->CreateFileInfo("In/pablo.txt");
		try{
			tokenizer = new Parcers::Tokenizer(input," ",1);
				token = tokenizer->getNextToken(false);
				while (token!=NULL){
					printf(token->getContent());
					delete(token);
					token = tokenizer->getNextToken(false);
				}	
			delete(tokenizer);
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
