#include "OutPutter.h"
#include "time.h"
#include "string.h"
#include "iostream.h"
#include "fstream.h"

using namespace std;

OutPutter::OutPutter(FileManager::FileInfo* aFileInfoIn, bool verbose) {
	this->_fileInfoIn = aFileInfoIn;
	FileManager::FileManager* fileManager = new FileManager::FileManager();	
	char* fileNameOut = "Out/Comandos.7506";
	this->_fileInfoOut = new FileManager::FileInfo(fileManager,fileNameOut);
	this->_verbose = verbose; 
}

OutPutter::~OutPutter(){
	free(this->_fileInfoIn);
	delete this->_fileInfoIn;
	if (this->_fileInfoOut != NULL) {
		free(this->_fileInfoOut);
		delete this->_fileInfoOut;
	}
}

void OutPutter::setVerbose(bool verbose) {
	this->_verbose=verbose;
}

bool OutPutter::getVerbose() {
	return this->_verbose;
}

FileManager::FileInfo* OutPutter::getFileInfoIn() {
	return this->_fileInfoIn;
}

void OutPutter::debug(char* message){
	if (this->_verbose) {
		printf("Debug: %s\n",message);
	}
}

void OutPutter::error(char* message){
	if (this->_verbose) {
		printf("Error: %s\n",message);
	}
}

void OutPutter::printLine(char* message, bool verbose) {
	if (verbose!=getVerbose()) {
		setVerbose(verbose);
		printLine(message);
		setVerbose(!verbose);
	} else
		printLine(message);
}

void OutPutter::printLine(char* message) {
	if (getVerbose()) {
		printf("%s\n",message);
	} else {
		time_t rawtime;
		struct tm * timeinfo;
		char* charMsg;
		string stringMessage;
		
		time(&rawtime);
		timeinfo = localtime(&rawtime);

		this->_fileInfoOut->open("ab");

		stringMessage.append("[");
		//Aca abajo me esta haciendo un ENTER demás
		stringMessage.append(asctime(timeinfo));
		stringMessage.append("] ");
		stringMessage.append(message);
		charMsg = (char*) malloc(sizeof(stringMessage));
		strcpy(charMsg,stringMessage.c_str());
		
		this->_fileInfoOut->write(charMsg,strlen(charMsg));
		this->_fileInfoOut->close();
	}
}

void OutPutter::moveInputFile() {
	/* 1) Verificar que existe el archivo en el IN
	 * 2) Crearlo en el OUT
	 * 3) Copiar el contenido del IN al OUT
	 * 4) ¿¿¿ Borrar el archivo del IN ???
	 * 5) Cerrar el archivo del OUT */
	
	ifstream in("In/Comandos.7506");
	ofstream out("Out/Comandos.7506");
	out<<in.rdbuf();
	in.close();
	out.close();
}
