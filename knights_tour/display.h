#ifndef MTA_FINISH_PROJECT_KNIGHT_CHESS_DISPLAY_H
#define MTA_FINISH_PROJECT_KNIGHT_CHESS_DISPLAY_H

#include "structsDefs.h"

//Functions Declarations
void display(chessPosList* lst);
//delete all positions that were previousy listed in the list
//and print a board with positions numbered corresponding to their apperance in the list
void deleteDoublePos(chessPosList* lst);
//delete all positions that were previousy listed in the list
void printBoard(chessPosList* lst);
//print a board with positions numbered corresponding to their apperance in the list
void deleteCellFromList (chessPosList* lst, chessPosCell* prev);
//removes list node from list
void deleteCellFromEndofList (chessPosList* lst, chessPosCell* prev);
//removes last node from list
void deleteCellFromMidList(chessPosCell* prev);
//remove node from middle position in list

#endif //MTA_FINISH_PROJECT_KNIGHT_CHESS_DISPLAY_H