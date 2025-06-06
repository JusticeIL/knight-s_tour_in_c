#include "structsDefs.h"
#include "treePath.h"
#include "searchesFrees.h"
#include "megaArray.h"

pathTree findAllPossibleKnightPaths(chessPos* startingPosition) {

    pathTree res;
    res.root = createNewTreeNode(*startingPosition);//create root for res tree
    chessPosArray ***knightMoves = validKnightMoves();//create 2d array of posibble moves from every position

    bool matrixBool[SIZE_ROW][SIZE_COL] = {false};
    //creates matrix, each position indicates whether a position has been processed by the algorythm before

    int row = (*startingPosition)[0]-(MIN_ROW);
    int col = (*startingPosition)[1]-(MIN_COL);
    matrixBool[row][col] = true;//update matrix to know starting position has been visited

    findAllPossibleKnightPathsRec(res.root, knightMoves , matrixBool);//create the rest of the tree
    freeKnightMoves(knightMoves);//free the 2d array
    return res;
}

void findAllPossibleKnightPathsRec (treeNode* root, chessPosArray*** arr, bool matrix[][SIZE_COL]) {

    int row = root->position[0] - MIN_ROW;
    int col = root->position[1] - MIN_COL;
    //gets row and collum of position in root

    chessPosArray* validMovesArr = arr[row][col];//gets from arr, an array of legal moves from starting position

    int i;
    for (i=0 ; i<validMovesArr->size ; i++)//for every legal move from position
    {
        chessPos nextPos;
        nextPos[0] = validMovesArr->positions[i][0];
        nextPos[1] = validMovesArr->positions[i][1];

        if (!isAlready(nextPos, matrix))//if position of move has been visited
        {
            treeNode *childNode = createNewTreeNode(nextPos);//create a new tree node containing the position
            insertChildToTree(root, childNode);//insert the node into the list of the root
            findAllPossibleKnightPathsRec(childNode, arr, matrix);//create rest of tree that branches from move position
        }
    }
    matrix[row][col] = false; //Unmark current position after processing all its moves
}

bool isAlready (chessPos pos, bool matrixBool[][SIZE_COL]) {

    if (matrixBool[pos[0]-MIN_ROW][pos[1]-MIN_COL])//if a position has been visited
        return true;
    else
    {
        matrixBool[pos[0]-MIN_ROW][pos[1]-MIN_COL] = true; //Mark current position as visited
        return false;
    }
}

treeNode* createNewTreeNode (chessPos pos) {

    treeNode *newNode;
    newNode = (treeNode*)malloc(sizeof(treeNode));
    CHECK_ALLOCATION(newNode)
    //create new tree node

    newNode->position[0] = pos[0];
    newNode->position[1] = pos[1];
    //initialize new nodes position

    makeEmptyTreeNodeList(&newNode->next_possible_positions);
    //initialize nodes list

    return newNode;
}

void insertChildToTree(treeNode* root, treeNode* newChild) {

    treeNodeListCell *newCell;
    newCell = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
    CHECK_ALLOCATION(newCell)
    //create new cell

    newCell->node = newChild;//insert tree node into cell
    newCell->next = NULL;

    insertChildToTreeInList(&root->next_possible_positions, newCell);//insert list cell into list
}

void insertChildToTreeInList(treeNodeList* treeList, treeNodeListCell* newCell) {

    if (isEmptyTreeList(treeList))//if list is empty
        treeList->head = treeList->tail = newCell;
    else
    {
        treeList->tail->next = newCell;
        treeList->tail = newCell;
    }
}

void makeEmptyTreeNodeList (treeNodeList* lst) {
    lst->head = lst->tail = NULL;
}

bool isEmptyTreeList(treeNodeList* trLst) {

    return (trLst->head == NULL);
}
