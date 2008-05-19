#ifndef BOARD_H_
#define BOARD_H_
typedef struct{
	char* board;
	int columns;
	int rows;
} TDA_Board;
TDA_Board* createBoard(int rows,int columns);
void deleteBoard(TDA_Board* board);
char getCharAtPosition(TDA_Board* board,int row,int column);
int setCharAtPosition(TDA_Board* board,int row,int column,char value);
void nextState(TDA_Board* board);
void copy(TDA_Board* inBoard,TDA_Board* outBoard);
void toString(TDA_Board* board);
#endif /*BOARD_H_*/
