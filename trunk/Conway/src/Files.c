#include "Files.h"
#include "Board.h"
#include <stdio.h>

int setUpBoardFromFile(TDA_Board* board, char* fileName){
	// TODO: hacer validaciones
	int x,y;
	FILE* entrada= fopen(fileName,"r");
	if (entrada!=NULL){
		while (!feof(entrada)){
			fscanf(entrada,"%d %d\n",&x,&y);
			setCharAtPosition(board,x,y,'1');
		}
		fclose(entrada);
	}
	return 1;
}
