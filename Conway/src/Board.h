#ifndef BOARD_H_
#define BOARD_H_
typedef struct{
	char* board;
	int columns;
	int rows;
} TDA_Board;
TDA_Board* createBoard(int columns,int rows);
void deleteBoard(TDA_Board* board);
char getCharAtPosition(TDA_Board* board,int column, int row);
int setCharAtPosition(TDA_Board* board,int column,int row,char value);
int nextState(TDA_Board* board);
void toString(TDA_Board* board);
#endif /*BOARD_H_*/
