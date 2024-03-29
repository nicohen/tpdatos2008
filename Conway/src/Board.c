#include "Board.h"
#include <stdlib.h>
#include <stdio.h>
#include "Vecinos.h"

TDA_Board* createBoard(int rows,int columns){
	if ((columns<1)||(rows<1)){
		return NULL;
	}
	int i,j;
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
	}
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			board->board[(i*rows)+j]='0';
		}
	}
	return board;
}

void deleteBoard(TDA_Board* board){
	free(board->board);
}

int validateCell(TDA_Board* board,int column, int row){
	if ((0>row)&&(row>board->rows)){
		return 0;
	}
	if ((0>column)&&(column>board->columns)){
		return 0;
	}
	return 1;
}

char getCharAtPosition(TDA_Board* board,int row,int column){
	if (validateCell(board,row,column)){
		return board->board[(row*board->columns)+column];
	}else{
		return 0;
	}
}
int setCharAtPosition(TDA_Board* board,int row,int column,char value){
	if (validateCell(board,row,column)){
		board->board[(row*board->columns)+column]=value;
		return 1;
	}else{
		return 0;
	}
}
void nextState(TDA_Board* board){
	unsigned int activos;
	TDA_Board* newBoard= createBoard(board->rows,board->columns);
	int i,j;
	for(i=0;i<board->rows;i++){
		for(j=0;j<board->columns;j++){
			activos=vecinos((unsigned char*)board->board,i,j,board->rows,board->columns);
			if ((activos<2)||(activos>3)){
				setCharAtPosition(newBoard,i,j,'0');
			}else{
				if(getCharAtPosition(board,i,j)=='1'){
					setCharAtPosition(newBoard,i,j,'1');	
				}else if (activos==3){
					setCharAtPosition(newBoard,i,j,'1');
				}
		 	}
		}
	}
	copy(newBoard,board);
	deleteBoard(newBoard);
}

void copy(TDA_Board* inBoard,TDA_Board* outBoard){
	int i,j;
	char value;
	for(i=0;i<inBoard->rows;i++){
		for(j=0;j<inBoard->columns;j++){
			value=getCharAtPosition(inBoard,i,j);
			setCharAtPosition(outBoard,i,j,value);
		}
	}
}

void toString(TDA_Board* board){
	int i,j;
	for(i=0;i<board->rows;i++){
		for(j=0;j<board->columns-1;j++){
			printf("%c,",getCharAtPosition(board,i,j));
		}
		printf("%c\n",getCharAtPosition(board,i,j));
	}
}
