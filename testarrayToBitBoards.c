/*
 * File Name: testarrayToBitBoards.c
 * Author: Elliot Pourmand
 * Description: test file for arrayToBitBoards()
 */

#include <stdio.h>
#include "izii2.h"

void testarrayToBitBoards() {
    long WP = 0L, WN = 0L, WB = 0L, WR = 0L, WQ = 0L, WK = 0L;
    long BP = 0L, BN = 0L, BB = 0L, BR = 0L, BQ = 0L, BK = 0L;
    char chessBoard[][BOARD_SIZE] = {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    };
    arrayToBitBoards(chessBoard,
                     &WP, &WN, &WB, &WR, &WQ, &WK,
                     &BP, &BN, &BB, &BR, &BQ, &BK);
    printBoard(WP, WN, WB, WR, WQ, WK,
               BP, BN, BB, BR, BQ, BK);
}

int main() {
    printf("Calling testarrayToBitBoards()\n");
    testarrayToBitBoards();
    printf("Finished testarrayToBitBoards()\n");
}

