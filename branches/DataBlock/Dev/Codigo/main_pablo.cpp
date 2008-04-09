#include "Tokenizer.h"
#include "Token.h"
#include "stdio.h"
#include "stdlib.h"
#include "FileInfo.h"
#include "FileManager.h"

int main(int argc, char **argv) {
	FileManager::FileManager* fileManager = new FileManager::FileManager();
	FileManager::FileInfo *input;
	char SEPARATORS[]= {' ','!','\n'};
 	char* KEYW[]= {"Hello","CONSULTAR"};
 	Parsing::Tokenizer *tokenizer;
	Parsing::Token *token;

	input = fileManager->CreateFileInfo("In/Comandos.7506");
	try{
		tokenizer = new Parsing::Tokenizer(input,'\'',SEPARATORS,3,KEYW ,2);
		token = tokenizer->getNextToken(false);
		while (token!=NULL){
			printf("(%d)%s ",token->getType(),token->getContent());
			//Ya no harian falta eliminarlos
			//delete(token);
			token = tokenizer->getNextToken(false);
		}
		delete(tokenizer);
	}catch(FileManager::IOException e){}
	delete input;
	delete fileManager;
	return 0;
}
