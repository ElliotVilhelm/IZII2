/*
 * File Name: izii2.h
 * Author: Elliot Pourmand
 * Description: function prototypes and constants
 */

/* Constants */
#define BOARD_SIZE 8
#define N_TILES 64

/* Function Prototypes */
void arrayToBitBoards(char[][BOARD_SIZE],
                      long *, long *, long *,
                      long *, long *, long *,
                      long *, long *, long *,
                      long *, long *, long *);
void printBoard(long, long, long,
                long, long, long,
                long, long, long,
                long, long, long);