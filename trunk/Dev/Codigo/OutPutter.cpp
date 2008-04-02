#include "OutPutter.h"
#include "time.h"
#include "string.h"
#include "iostream.h"
#include "fstream.h"

using namespace std;

OutPutter::OutPutter(FileManager::FileInfo* aFileInfoIn, bool verbose) {
	this->_fileInfoIn = aFileInfoIn;
	FileManager::FileManager* fileManager = new FileManager::FileManager();	

	string strBuffer;
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];
	char* fileNameOut;
	
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);

	strBuffer.append("Out/[");
	strBuffer.append(buffer);
	strBuffer.append("] Comandos.7506");

	fileNameOut = (char*) malloc(strlen(strBuffer.c_str()));
	strcpy(fileNameOut,strBuffer.c_str());

	ifstream in("In/Comandos.7506");
	ofstream out(fileNameOut);
	out<<in.rdbuf();

	this->_fileInfoOut = new FileManager::FileInfo(fileManager,fileNameOut);
	
	this->_fileInfoIn->close();
	this->_fileInfoOut->close();
	
	this->_verbose = verbose;
	
	free(fileNameOut);
}

OutPutter::~OutPutter(){
//	free(this->_fileInfoIn);
	delete this->_fileInfoIn;
	if (this->_fileInfoOut != NULL) {
//		free(this->_fileInfoOut);
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
		struct tm* timeinfo;
		char buffer[80];
		string stringMessage;
		char* charMsg;
		
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(buffer,80,"%Y-%m-%d %H:%M:%S",timeinfo);
		
		this->_fileInfoOut->open("ab");

		stringMessage.append("[");
		stringMessage.append(buffer);
		stringMessage.append("] ");
		stringMessage.append(message);
		
		charMsg = (char*) malloc(strlen(stringMessage.c_str()));
		strcpy(charMsg,stringMessage.c_str());
		
		this->_fileInfoOut->write(charMsg,strlen(charMsg));
		this->_fileInfoOut->close();

		free(charMsg);

	}
}
