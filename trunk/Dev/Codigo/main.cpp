#import "stdio.h"
#import "string.h"
#import "stdlib.h"
#import "Demon.h"
#import "FileManager.h"

int main(int argc, char **argv) {
	FileManager::FileManager* fileManager = NULL;
	int sleepTime;
	int bufferSize;
	Demon *demon;
	bool verbose = false;

	// VERIFICO LA CANTIDAD MINIMA DE PARAMETROS
	if (argc < 3){
		printf("Cantidad erronea de parametros.\n");
		return 1;
	}
	
	// VALIDO EL PARAMETRO CON EL TIEMPO DE ESPERA
	sleepTime = atol(argv[1]);
	if (sleepTime == 0){
		printf("Valor invalido para el parametro Tiempo.\n");
		return 1;
	}
	// VALIDO EL PARAMETRO CON EL TIEMPO DE ESPERA
	bufferSize = atol(argv[2]);
	if (bufferSize == 0){
		printf("Valor invalido para el parametro Tamaño de Buffer.\n");
		return 1;
	}
	// VALIDAR EL VALOR PARA VERBOSE
	if ((argc==4)&&(strcmp("-d",argv[3])==0)){
		verbose = true;
	}
	printf("%d %d %s\n",sleepTime,bufferSize,verbose?"true":"false");
	fileManager= new FileManager::FileManager();
	demon = new Demon(fileManager,sleepTime,bufferSize,verbose);
	demon->run();
	delete demon;
	delete fileManager;
	return 0;
}
