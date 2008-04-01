#import "stdio.h"
#import "string.h"
#import "FileManager.h"
#import "OutPutter.h"

int main(int argc, char **argv) {
	printf("Hola desde el main de nicolas\n");

	FileManager::FileManager* fileManager = NULL;
	FileManager::FileInfo* fileInfo = NULL;
	OutPutter* outPut = NULL;
	bool verbose = true;
	char* fileName = "/home/nicohen/workspace/Datos/AlmacenX/In/Comandos.7506";
	
	fileManager = new FileManager::FileManager();
	fileInfo = new FileManager::FileInfo(fileManager, fileName);
	outPut = new OutPutter(fileInfo, verbose);
	
	outPut->printLine("Inicio escritura de archivo");
	outPut->moveInputFile();
	outPut->printLine("Archivo copiado correctamente");
	outPut->printLine("Todas las cosas que puedan salir al archivo OUT",false);
	outPut->printLine("Fin escritura de archivo");

	fileManager->Close(fileInfo);
	
	delete fileManager;
	delete outPut;
	
	return 0;
}
