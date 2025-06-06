#include "megaArray.h"
#include "searchesFrees.h"

chessPosArray*** validKnightMoves() {

    chessPosArray ***res;
    res = (chessPosArray***)malloc(SIZE_ROW *sizeof(chessPosArray**));
    CHECK_ALLOCATION(res)
    char row, col;

    for (row=MIN_ROW ; row<=MAX_ROW ; row++)//for every row in board
    {
        res[row-MIN_ROW] = (chessPosArray**)malloc(SIZE_COL* sizeof(chessPosArray*));
        CHECK_ALLOCATION(res[row-MIN_ROW])

        for (col=MIN_COL ; col<=MAX_COL ; col++)//for every position in row
        {
            res[row-MIN_ROW][col-MIN_COL] = validKnightFromPos(row, col);//insert posible moves fo knight from position
        }
    }

    return res;
}

chessPosArray* validKnightFromPos(char row, char col) {

    potenialPoint NE, EN, ES, SE, SW, WS, WN, NW;//potential moves relative to position
    chessPosArray *res;
    chessPos *canJumpToArr;
    unsigned int sum = 0;
    int i;

    res = (chessPosArray*)malloc(sizeof(chessPosArray));
    CHECK_ALLOCATION(res)

    initPos(&NE,row-2, col+1);
    initPos(&EN, row-1, col+2);
    initPos(&ES, row+1, col+2);
    initPos(&SE, row+2, col+1);
    initPos(&SW, row+2, col-1);
    initPos(&WS, row+1, col-2);
    initPos(&WN, row-1, col-2);
    initPos(&NW, row-2, col-1);
    //initialize place on board for all moves

    potenialPoint ppArr [] = {NE, EN, ES, SE, SW, WS, WN, NW};//insert moves into array

    for (i=0 ; i<MAX_POINT ; i++)//for every potential move in array
    {
        ppArr[i].isValid = isLegalInput(ppArr[i].pos[0], ppArr[i].pos[1]);//check if position of move is legal
        if (ppArr[i].isValid)
            sum++;
    }

    canJumpToArr = (chessPos*)malloc(sum*sizeof(chessPos));//create res arr
    CHECK_ALLOCATION(canJumpToArr)

    addValidPointsToArr(canJumpToArr, ppArr, sum);//insert legal moves from arr into res arr

    res->size = sum;//update size
    res->positions = canJumpToArr;//update positions list of returned struct

    return res;
}

void initPos(potenialPoint* pPos, char row, char col) {

    pPos->pos[0] = row;
    pPos->pos[1] = col;
}

void addValidPointsToArr(chessPos* arr, potenialPoint* ppArr, unsigned int sum) {

    int i,j;
    j=0;

    for (i=0 ; j<sum ; i++)//for every move in ppArr or untill all legal moves were proccesed
    {
        if (ppArr[i].isValid)//if a move is legal
        {
            arr[j][0] = ppArr[i].pos[0];
            arr[j][1] = ppArr[i].pos[1];//insert position of move to arr
            j++;
        }
    }
}