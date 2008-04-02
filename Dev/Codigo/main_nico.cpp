#import "stdio.h"
#import "string.h"
#import "FileManager.h"
#import "OutPutter.h"

int main(int argc, char **argv) {
	printf("Hola desde el main de nicolas\n");

	FileManager::FileManager* fileManager = NULL;
	FileManager::FileInfo* fileInfo = NULL;
	OutPutter* outPut = NULL;
	char* fileName = "In/Comandos.7506";
	
	fileManager = new FileManager::FileManager();
	fileInfo = fileManager->CreateFileInfo(fileName);
	outPut = new OutPutter(fileManager, fileInfo, true);
	outPut->debug("Inicio escritura de archivo");
	outPut->debug("Archivo copiado correctamente");
	outPut->printLine("Todas las cosas que puedan salir al archivo OUT");
	outPut->printLine("Mas cosas...");
	outPut->debug("Fin escritura de archivo");

	fileManager->Close(fileInfo);
	
	free(fileName);
	delete fileManager;
	delete outPut;
	
	return 0;
}
