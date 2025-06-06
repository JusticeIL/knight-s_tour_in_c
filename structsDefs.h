#ifndef MTA_FINISH_PROJECT_KNIGHT_CHESS_STRUCTS_DEFS
#define MTA_FINISH_PROJECT_KNIGHT_CHESS_STRUCTS_DEFS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MIN_ROW 'A'
#define MAX_ROW 'E'
#define MIN_COL '1'
#define MAX_COL '5'
#define SIZE_ROW 5
#define SIZE_COL 5
#define MAX_POINT 8

#define CHECK_ALLOCATION(ptr) \
                                      if((ptr) == NULL) {\
                                       printf("Memory Allocation Failed!\n");\
                                       exit(1);\
                                       }

typedef char chessPos[2];

typedef struct _chessPosArray {
    unsigned int size;
    chessPos *positions;
} chessPosArray;

typedef struct PotentialPoint {
    chessPos pos;
    bool isValid;
}potenialPoint;

typedef struct _chessPosCell {
    chessPos position;
    struct _chessPosCell *next;
}chessPosCell;

typedef struct _chessPosList {
    chessPosCell *head;
    chessPosCell *tail;
}chessPosList;

typedef struct _treeNodeList {
    struct _treeNodeListCell *head;
    struct _treeNodeListCell *tail;
} treeNodeList;

typedef struct _treeNode{
    chessPos position;
    treeNodeList next_possible_positions; 
} treeNode;
typedef struct _treeNodeListCell {
    treeNode *node;
    struct _treeNodeListCell *next;
} treeNodeListCell;
typedef struct _pathTree {
    treeNode *root;
} pathTree;

#endif