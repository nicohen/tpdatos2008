#ifndef FILES_H_
#define FILES_H_
#include "Board.h"
int setUpBoardFromFile(TDA_Board* board, char* fileName);
int createPBMFromBoad(TDA_Board* board, char* prefix, int iteration);
#endif /*FILES_H_*/
