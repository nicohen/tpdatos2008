#include "Board.h"
#include <stdlib.h>

TDA_Board* createBoard(int columns,int rows){
	TDA_Board* board= (TDA_Board*) malloc(sizeof(TDA_Board));
	if (board==NULL){
		return NULL;
	}
	board->columns= columns;
	board->rows= rows;
	board->board= (char*) malloc(columns*rows*sizeof(char));
	if (board->board==NULL){
		free(board);
		return NULL;
	}else{
		return board;
	}
}

void deleteBoard(TDA_Board* board){
	free(board->board);
}

int validateCell(TDA_Board* board,int column, int row){
	if ((0>column)&&(column>board->columns)){
		return 0;
	}
	if ((0>row)&&(row>board->rows)){
		return 0;
	}
	return 1;
}

char getCharAtPosition(TDA_Board* board,int column, int row){
	if (validateCell(board,column,row)){
		return board->board[(column*board->rows)+row];
	}else{
		return 0;
	}
}
int setCharAtPosition(TDA_Board* board,int column,int row,char value){
	if (validateCell(board,column,row)){
		board->board[(column*board->rows)+row]=value;
		return 1;
	}else{
		return 0;
	}
}
void nextState(TDA_Board* board){
	
}
