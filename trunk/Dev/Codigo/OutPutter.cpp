#include "OutPutter.h"
#include "time.h"
#include "string.h"
#include <iostream>
#include <fstream>

using namespace std;

OutPutter::OutPutter(FileManager::FileManager* aFileManager) {
	this->_fileManager = aFileManager;
}

OutPutter::~OutPutter(){
	if (this->_fileInfoOut != NULL)
		delete this->_fileInfoOut;
}

void OutPutter::writeOutputFile(FileManager::FileInfo* inputFile) {
	string strBuffer;
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	char* fileNameOut;

	//Crea el time y lo formatea 
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,80,"%Y%m%d_%H%M%S",timeinfo);

	//Realiza un append del nombre de la carpeta formateado
	strBuffer.append("Out/Resultados_");
	strBuffer.append(buffer);
	strBuffer.append(".7506");

	fileNameOut = (char*) malloc(strlen(strBuffer.c_str()));
	strcpy(fileNameOut,strBuffer.c_str());

	//Copia el archivo de la carpeta In en la carpeta Out
	ifstream in(inputFile->getFileName());
	ofstream out(fileNameOut);
	out<<in.rdbuf();

	//Crea el fileInfoOut
	this->_fileInfoOut = this->_fileManager->CreateFileInfo(fileNameOut);
	this->_fileInfoOut->close();
	
	free(fileNameOut);

}

void OutPutter::printLine(char* message) {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	string stringMessage;
	char* myMessage = cloneStr(message);
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,80,"%Y%m%d_%H%M%S",timeinfo);
	
	this->_fileInfoOut->open("ab");

	stringMessage.append("\n[");
	stringMessage.append(buffer);
	stringMessage.append("] ");
	stringMessage.append(myMessage);
		
	this->_fileInfoOut->write((void*)stringMessage.c_str(),stringMessage.size());
	this->_fileInfoOut->close();

	free(myMessage);
}
