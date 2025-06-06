#include "display.h"
#include "treePath.h"

void display(chessPosList* lst) {

    deleteDoublePos(lst);
    printBoard(lst);
}

void deleteDoublePos(chessPosList* lst) {
    bool matrix[SIZE_ROW][SIZE_COL] = {false};
    //creates matrixs, each position indicates whether a position has been processed by the algorythm before

    chessPosCell *prev, *curr, *next;
    prev = NULL;
    curr = lst->head;

    while (curr != NULL)//for every position in list
    {
        next = curr->next;
        if (isAlready(curr->position, matrix))//if position was visited before
            deleteCellFromList(lst, prev);//delete from list
        else
            prev = curr;

        curr = next;
    }
}

void printBoard(chessPosList* lst) {

    int boardMatrix[SIZE_ROW][SIZE_COL] = {0};//initialize board
    int i, count, currCol;
    char currRow;

    chessPosCell *curr = lst->head;

    count=1;
    while (curr != NULL)//for every position in list
    {
        boardMatrix[curr->position[0]-MIN_ROW][curr->position[1]-MIN_COL] = count;//update the numbering of the position in the board
        count++;//update move count
        curr = curr->next;
    }

    printf(" ");
    for (i=1 ; i<=SIZE_COL ; i++)
    {
        printf("  %d" , i);
        if (i==SIZE_COL)
            printf(" ");
    }//print collum numbers

    printf("\n");

    for (currRow=MIN_ROW ; currRow<=MAX_ROW ; currRow++)//for every row
    {
        printf("%c|" , currRow);//print row letter
        for (currCol=0 ; currCol<SIZE_COL ; currCol++)//or every collum in row
        {
            printf("%2d|" , boardMatrix[currRow-MIN_ROW][currCol]);//print position from board
        }
        printf("\n");
    }

}
void deleteCellFromList (chessPosList* lst, chessPosCell* prev) {

    if (lst->tail == prev->next)//if node to delete is last
        deleteCellFromEndofList(lst, prev);
    else
        deleteCellFromMidList(prev);
}

void deleteCellFromEndofList(chessPosList* lst, chessPosCell* prev) {

    chessPosCell *toDelete;
    toDelete = prev->next;

    lst->tail = prev;
    prev->next = NULL;

    free(toDelete);
}

void deleteCellFromMidList(chessPosCell* prev) {

    chessPosCell *toDelete;
    toDelete = prev->next;

    prev->next = prev->next->next;

    free(toDelete);
}
