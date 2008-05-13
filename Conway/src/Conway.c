#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utils.h"
#include "Board.h"
#include "Files.h"

void printVersion(){
	printf("Conway Version 1.1\n");
}

void printHelp(){
	printf("Uso:\n");
	printf("conway -h\n");
	printf("conway -V\n");
	printf("conway i M N inputfile [-o outputprefix]\n");
	printf("Opciones:\n");
	printf("-h, --help Imprime este mensaje.\n");
	printf("-V, --version Da la versión del programa.\n");
	printf("-o Prefijo de los archivos de salida.\n");
	printf("\n");
	printf("Ejemplos:\n");
	printf("conway 10 20 20 glider -o estado\n");
	printf("Representa 10 iteraciones del Juego de la Vida en una matriz de 20x20,\n");
	printf("con un estado inicial tomado del archivo 'glider'.\n");
	printf("Los archivos de salida se llamarán estado_n.pbm.\n");
	printf("Si no se da un prefijo para los archivos de salida,\n");
	printf("el prefijo será el nombre del archivo de entrada.\n");	
}

int main(int argc, char **argv) {
	TDA_Board* board;
	int steps=0;
	int heigth=0;
	int width=0;
	char* sourceFile=NULL;
	char* outputPrefix="";
	int i=1;
	while (i<argc){
		if (strcmp("-V",argv[i])==0){
			printVersion();
			return 1;
		}else if (strcmp("-h",argv[i])==0){
			printHelp();
			return 1;
		}else if(steps==0){
			if(isNumericString(argv[i])!=0){
				steps=atoi(argv[i]);
				if(steps==0){
					printf("Steps debe ser un número positivo mayor que 0");
					return 1;
				}
			}else{
				printf("Steps debe ser un número positivo mayor que 0");
				return 1;
			}
		}else if(heigth==0){
			if(isNumericString(argv[i])!=0){
				heigth=atoi(argv[i]);
				if(heigth==0){
					printf("Heigth debe ser un número positivo mayor que 0.");
					return 1;
				}
			}else{
				printf("Heigth debe ser un número positivo mayor que 0.");
				return 1;
			}
		}else if(width==0){
			if(isNumericString(argv[i])!=0){
				width=atoi(argv[i]);
				if(width==0){
					printf("Width debe ser un número positivo mayor que 0.");
					return 1;
				}
			}else{
				printf("Width debe ser un número positivo mayor que 0.");
				return 1;
			}
		}else if(strcmp("-o",argv[i])==0){
			i++;
			if (i<argc){
				outputPrefix=argv[i];
			}else{
				printf("Luego del un -o debe especificar el prefijo de los archivos de salida.");
				return 1;
			}
		}else if(sourceFile==NULL){
			sourceFile= argv[i];
		}
		i++;
	}
	if(sourceFile==NULL){
		printf("Se debe indicar el nombre del archivo de entrada.");
		return 1;
	}
	if(width==0){
		printf("Se debe indicar el ancho del tablero.");
		return 1;
	}
	if(heigth==0){
		printf("Se debe indicar el alto del tablero.");
		return 1;
	}
	if(steps==0){
		printf("Se debe indicar la cantidad de pasos.");
		return 1;
	}
	board= createBoard(width,heigth);
	printf("-------ANTES------\n");
	toString(board);
	setUpBoardFromFile(board,sourceFile);
	createPBMFromBoad(board,outputPrefix,1);
	printf("------DESPUES-----\n");
	toString(board);
	deleteBoard(board);
	return 0;	
}
