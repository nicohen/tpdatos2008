#include "Files.h"
#include "Board.h"
#include <stdio.h>
#include <string.h>

int setUpBoardFromFile(TDA_Board* board, char* fileName){
	int x,y;
	int result=1;
	FILE* entrada= fopen(fileName,"r");
	if (entrada==NULL){
		return 0;
	}
	while ((!feof(entrada))&&(result)){
		fscanf(entrada,"%d %d\n",&x,&y);
		result=setCharAtPosition(board,x-1,y-1,'1');
	}
	fclose(entrada);
	return result;
}

int createPBMFromBoad(TDA_Board* board, char* prefix, int iteration){
	int i,j;
	char buffer[50];
	FILE* salida;
	sprintf(buffer,"%s_%d.pbm",prefix,iteration);
	salida=fopen(buffer,"w");
	if (salida==NULL){
		return 0;
	}
	fprintf(salida,"P1\n");
	fprintf(salida,"%d %d\n",board->columns,board->rows);
	for(i=0;i<board->rows;i++){
		for(j=0;j<board->columns-1;j++){
			fprintf(salida,"%c",getCharAtPosition(board,i,j));
		}
		fprintf(salida,"%c\n",getCharAtPosition(board,i,j));
	}
	fclose(salida);
	return 1;
}
