/*
 * File Name: arrayToBitBoards.c
 * Author: Elliot Pourmand
 * Description: This files purpose is to take an 8x8  char array and
 *              generate the respective bitboards
 */

#include <stdio.h>
#include "constants.h"
#include "izii2.h"

void arrayToBitBoards(char board[][BOARD_SIZE],
                      long * WP, long * WN, long * WB,
                      long * WR, long * WQ, long * WK,
                      long * BP, long * BN, long * BB,
                      long * BR, long * BQ, long * BK) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int file = 0; file < BOARD_SIZE; file++) {
            printf("board[row][file] %c\n", board[row][file]);
            switch (board[row][file]) {

                default:break;
            }
        }

    }
    printf("arrayToBitBoards!");
}
