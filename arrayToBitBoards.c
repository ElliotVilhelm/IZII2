/*
 * File Name: arrayToBitBoards.c
 * Author: Elliot Pourmand
 * Description: This files purpose is to take an 8x8  char array and
 *              generate the respective bitboards
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "izii2.h"
#include <stdio.h>

void arrayToBitBoards(char board[][BOARD_SIZE],
                      long * WP, long * WN, long * WB,
                      long * WR, long * WQ, long * WK,
                      long * BP, long * BN, long * BB,
                      long * BR, long * BQ, long * BK) {
    for (int rank = 0; rank < BOARD_SIZE; rank++) {
        for (int file = 0; file < BOARD_SIZE; file++) {
            int boardPos = rank * BOARD_SIZE + file;
            int bitPos = abs(boardPos - N_TILES + 1);
            long mask = (long) pow(2, bitPos);
            switch (board[rank][file]) {
                case 'P':
                    *WP |= mask;
                    break;
                case 'N':
                    *WN |= mask;
                    break;
                case 'B':
                    *WB |= mask;
                    break;
                case 'R':
                    *WR |= mask;
                    break;
                case 'Q':
                    *WQ |= mask;
                    break;
                case 'K':
                    *WK |= mask;
                    break;
                case 'p':
                    *BP |= mask;
                    break;
                case 'n':
                    *BN |= mask;
                    break;
                case 'b':
                    *BB |= mask;
                    break;
                case 'r':
                    *BR |= mask;
                    break;
                case 'q':
                    *BQ |= mask;
                    break;
                case 'k':
                    *BK |= mask;
                    break;
                default:
                    break;
            }
        }
    }
    printf("arrayToBitBoards!\n");
}
