/*
 * File Name: arrayToBitBoards.c
 * Author: Elliot Pourmand
 * Description: print a pretty chess board from bitboards
 */

#include <printf.h>
#include <stdlib.h>
#include "izii2.h"

void printBoard(long WP, long WN, long WB,
                long WR, long WQ, long WK,
                long BP, long BN, long BB,
                long BR, long BQ, long BK) {
    char board[N_TILES+1] = {0};
    for (int sq = 0; sq < N_TILES; sq++) {
        board[sq] = ' ';
        if (WP >> sq & 1 == 1) board[sq] = 'P';
        if (WN >> sq & 1 == 1) board[sq] = 'N';
        if (WB >> sq & 1 == 1) board[sq] = 'B';
        if (WR >> sq & 1 == 1) board[sq] = 'P';
        if (WQ >> sq & 1 == 1) board[sq] = 'Q';
        if (WK >> sq & 1 == 1) board[sq] = 'K';
        if (BP >> sq & 1 == 1) board[sq] = 'p';
        if (BN >> sq & 1 == 1) board[sq] = 'n';
        if (BB >> sq & 1 == 1) board[sq] = 'b';
        if (BR >> sq & 1 == 1) board[sq] = 'r';
        if (BQ >> sq & 1 == 1) board[sq] = 'q';
        if (BK >> sq & 1 == 1) board[sq] = 'k';
    }
    board[N_TILES] = '\0';

    for (int sq = 0; sq < N_TILES; sq++) {
        if (sq % BOARD_SIZE == 0) {
            printf("\n%d|", abs((sq / BOARD_SIZE) - BOARD_SIZE));
        }
        printf("%c|", board[sq]);
    }
    printf("\n  A B C D E F G H");
    printf("\n\n");
}
