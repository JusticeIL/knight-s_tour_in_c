#include "searchesFrees.h"
#include "treePath.h"

chessPosList* findKnightPathCoveringAllBoard(pathTree *path_tree) {

    chessPosList* res;
    res = (chessPosList*)malloc(sizeof(chessPosList));
    CHECK_ALLOCATION(res)
    //create list of positions

    makeEmptyChessPosList(res);//initialize list

    bool isFound = false;

    findRec(res, path_tree->root, &isFound, 1);//fill list with positions of in order knight tour that covers all board

    if (!isFound)//if such tour doesn't exist
    {
        free(res);
        return NULL;
    }

    return res;
}

void findRec(chessPosList* lst, treeNode* pos, bool* isFound, int level) {

    if (isEmptyTreeList(&pos->next_possible_positions))//if reached end of tour
    {
        if (level == SIZE_ROW*SIZE_COL)//if amount of moves in tour equal to number of positions on board
        {
            *isFound = true;//update isFound
            insertDataToStartList(lst, pos->position);//start inserting positions of current tour into res list
        }
        return;
    }

    else
    {
        treeNodeListCell *curr;
        for (curr = pos->next_possible_positions.head; curr != NULL && !(*isFound); curr = curr->next)
            //for every possible move from position ,until on desired route for sure
            findRec(lst, curr->node, isFound, level+1);//continue to search

        if (*isFound == true)//if on desired tour
        {
            insertDataToStartList(lst, pos->position);//continue to insert positions of current tour into res list
            return;
        }
    }
}

void makeEmptyChessPosList(chessPosList* lst) {
    lst->head = lst->tail = NULL;
}

bool isEmptyChessPosList(chessPosList* lst) {
    return (lst->head == NULL);
}

void insertDataToStartList(chessPosList* lst, chessPos toAdd) {

    chessPosCell* newChessPosListNode;
    newChessPosListNode = createNewChessPosCell(toAdd, NULL);

    if (isEmptyChessPosList(lst))
        lst->head = lst->tail = newChessPosListNode;
    else
    {
        newChessPosListNode->next = lst->head;
        lst->head = newChessPosListNode;
    }
}

chessPosCell* createNewChessPosCell(chessPos data, chessPosCell* next) {

    chessPosCell* newChessPosListNode;
    newChessPosListNode = (chessPosCell*)malloc(sizeof(chessPosCell));
    CHECK_ALLOCATION(newChessPosListNode)

    newChessPosListNode->next = next;
    newChessPosListNode->position[0] = data[0];
    newChessPosListNode->position[1] = data[1];

    return newChessPosListNode;
}

bool isLegalInput (char row, char col) {

    return ((row>=MIN_ROW && row<=MAX_ROW) && (col>=MIN_COL && col<=MAX_COL));//checks if position is legal
}

void freeKnightMoves(chessPosArray*** boardArr) {

    int i,j;

    for (i=0 ; i<SIZE_ROW ; i++)//for every row
    {
        for (j=0 ; j<SIZE_COL ; j++)//for every collum in row
        {
            free(boardArr[i][j]->positions);//free array of positions
            free(boardArr[i][j]);//free struct of positions
        }
        free(boardArr[i]);//free row
    }
    free(boardArr);//free collums
}

void freeChessPosList(chessPosList* lst) {

    chessPosCell *curr, *next;
    curr = lst->head;

    while (curr != NULL)
    {
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(lst);
}

void freePathTree(pathTree* tr) {

    freeTreeRec(tr->root->next_possible_positions.head);//free all items in tree starting with the list of the root
    free(tr->root);//free root
}

void freeTreeRec(treeNodeListCell* head) {

    while (head != NULL)//while list of root not empty,
    {
        treeNodeListCell *next = head->next;
        freeTreeRec(head->node->next_possible_positions.head);//free all items in tree starting with the list of the root of current list node
        free(head->node);//free treenode in head of list
        free(head);//free head of list
        head = next;
    }
}
