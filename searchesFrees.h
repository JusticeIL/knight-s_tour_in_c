#ifndef MTA_FINISH_PROJECT_KNIGHT_CHESS_SEARCHESFREES_H
#define MTA_FINISH_PROJECT_KNIGHT_CHESS_SEARCHESFREES_H

#include "structsDefs.h"

//Functions Declarations
chessPosList* findKnightPathCoveringAllBoard(pathTree *path_tree);
//return list of chess moves that cover the entire moves
//starting from position of given trees root
void findRec(chessPosList* lst, treeNode* pos, bool* isFound, int level);
//continue to search for knights tour that covers whole board
void makeEmptyChessPosList(chessPosList* lst);
//initialize list of positions
bool isEmptyChessPosList(chessPosList* lst);
//checks if position list is empty
void insertDataToStartList(chessPosList* lst, chessPos toAdd);
//inserts position to beginning of list
chessPosCell* createNewChessPosCell(chessPos data, chessPosCell* next);
//create new list node containing given position
bool isLegalInput (char row, char col);
//checks if move position is in board
void freeKnightMoves(chessPosArray*** boardArr);
//free 2d array of structs containing arrays of positions
void freePathTree(pathTree* tr);
//free three of knight moves
void freeTreeRec(treeNodeListCell* head);
//free branch of tree
void freeChessPosList(chessPosList* lst);
//free list that contains tree nodes

#endif //MTA_FINISH_PROJECT_KNIGHT_CHESS_SEARCHESFREES_H