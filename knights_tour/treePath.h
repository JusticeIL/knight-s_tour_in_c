#ifndef MTA_FINISH_PROJECT_KNIGHT_CHESS_TREEPATH_H
#define MTA_FINISH_PROJECT_KNIGHT_CHESS_TREEPATH_H

#include "structsDefs.h"


pathTree findAllPossibleKnightPaths( chessPos *startingPosition);
//returns tree that each branch in tree is a knight tour that visits every square once from a starting position
void findAllPossibleKnightPathsRec (treeNode* root, chessPosArray*** arr, bool matrix[][SIZE_COL]);
//creates knight tour that visits every square once from a starting position, remembering previous moves
bool isAlready (chessPos pos, bool matrixBool[][SIZE_COL]);
//checks if a potision has been visited
treeNode* createNewTreeNode (chessPos pos);
//creates new tree node
void insertChildToTree(treeNode* root, treeNode* newChild);
//inserts new tree node to root
void insertChildToTreeInList(treeNodeList* treeList, treeNodeListCell* newCell);
//inserts new tree node to roots list
void makeEmptyTreeNodeList (treeNodeList* lst);
//initialize list to empty
bool isEmptyTreeList(treeNodeList* trLst);
//checks if tree is empty

#endif //MTA_FINISH_PROJECT_KNIGHT_CHESS_TREEPATH_H