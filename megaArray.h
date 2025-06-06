#ifndef MTA_FINISH_PROJECT_KNIGHT_CHESS_MEGAARRAY_H
#define MTA_FINISH_PROJECT_KNIGHT_CHESS_MEGAARRAY_H

#include "structsDefs.h"

chessPosArray*** validKnightMoves();
//returns an array of arrays of possible moves that can be made by a knight from corresponding position on a chess board
chessPosArray* validKnightFromPos(char row, char col);
//returns possible moves that can be made by a knight from corresponding position on a chess board
void initPos(potenialPoint* pPos, char row, char col);
//initializes position with given row and collum
void addValidPointsToArr(chessPos* arr, potenialPoint* ppArr, unsigned int sum);
//selects legal moves from array and inserts them into another

#endif //MTA_FINISH_PROJECT_KNIGHT_CHESS_MEGAARRAY_H