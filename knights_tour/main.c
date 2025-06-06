#define _CRT_SECURE_NO_WARNINGS

#include "structsDefs.h"
#include "display.h"
#include "treePath.h"
#include "searchesFrees.h"

void main() {

    chessPos startingPosition;
    char extraChar;
    pathTree tr;
    chessPosList* pathList;

    scanf("%c %c", &startingPosition[0],&startingPosition[1]);


    while ((extraChar = getchar()) != '\n' && extraChar != EOF)
    {
        printf("Invalid input\n");
        exit(1);
    }

    if (!isLegalInput(startingPosition[0],startingPosition[1]))
    {
        printf("Invalid input\n");
        exit(1);
    }

    tr = findAllPossibleKnightPaths(&startingPosition);
    pathList = findKnightPathCoveringAllBoard(&tr);



    if (pathList != NULL)
    {
        display(pathList);
        freeChessPosList(pathList);
    }
    else
    {
        printf("No knight's tour\n");
    }

    freePathTree(&tr);
}