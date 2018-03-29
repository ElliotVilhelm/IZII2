#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "izii2.h"
#include <string.h>

static long FILE_A = 72340172838076673L;
static long FILE_H = 9187201950435737472L;
static long FILE_AB = 217020518514230019L;
static long RANK_8 = 255L;
static long RANK_4 = 1095216660480L;
static long NOT_WHITE_PIECES;
static long BLACK_PIECES;
static long EMPTY;
char * get_moves_W(char * history,
                   long WP, long WN, long WB,
                   long WR, long WQ, long WK,
                   long BP, long BN, long BB,
                   long BR, long BQ, long BK) {
    NOT_WHITE_PIECES = ~(WP|WN|WB|WR|WQ|WK|BK);
    BLACK_PIECES = BP|BN|BB|BR|BQ;
    EMPTY = ~(WP|WN|WB|WR|WQ|WK|BP|BN|BB|BR|BQ|BK);
    char * moves = get_moves_WP(history, WP);

}
char * get_moves_WP(char * history, long WP) {
    long PAWN_MOVES;
    char * moves;
    moves = malloc(BUFSIZ);
    moves[0] = 0;

    /* represents all right captures */
    PAWN_MOVES = (WP>>7) & BLACK_PIECES & ~RANK_8 & ~ FILE_A;
    for (int i = 0; i < N_TILES; i++) {
        if ((PAWN_MOVES>>i) & 1 == 1) {
            strcat(moves, i/8 + 1);
            strcat(moves, i%8 - 1);
            strcat(moves, i/8);
            strcat(moves, i%8);
        }
    }
    PAWN_MOVES = (WP>>9) & BLACK_PIECES & ~RANK_8 & ~FILE_H;
    for (int i = 0; i < N_TILES; i++) {
        if ((PAWN_MOVES>>i) & 1 == 1) {
            strcat(moves, i/8 + 1); // from rank
            strcat(moves, i%8 + 1); // from file
            strcat(moves, i/8); // to rank
            strcat(moves, i%8); // to file
        }
    }
    PAWN_MOVES = (WP>>8) & EMPTY & ~RANK_8;
    for (int i = 0; i < N_TILES; i++) {
        if ((PAWN_MOVES>>i) & 1 == 1) {
            strcat(moves, i/8 + 1); // from rank
            strcat(moves, i%8); // from file
            strcat(moves, i/8); // to rank
            strcat(moves, i%8); // to file
        }
    }
    PAWN_MOVES = (WP>>16) & EMPTY & (EMPTY>>8) & RANK_4;
    for (int i = 0; i < N_TILES; i++) {
        if ((PAWN_MOVES>>i) & 1 == 1) {
            strcat(moves, i/8 + 2); // from rank
            strcat(moves, i%8); // from file
            strcat(moves, i/8); // to rank
            strcat(moves, i%8); // to file
        }
    }

    /* promotions */
    /* capture right */
    PAWN_MOVES = (WP>>7) & BLACK_PIECES & RANK_8 & ~FILE_A;
    for (int i = 0; i < N_TILES; i++) {
        if ((PAWN_MOVES>>i) & 1 == 1) {
            strcat(moves, i%8-1); // from file
            strcat(moves, i%8); // to file
            strcat(moves, "QP"); // queen promotion
            strcat(moves, i%8-1); // from file
            strcat(moves, i%8); // to file
            strcat(moves, "RP"); // queen promotion
        }
    }
    /* capture left */
    PAWN_MOVES = (WP>>9) & BLACK_PIECES & RANK_8 & ~FILE_H;
    for (int i = 0; i < N_TILES; i++) {
        if ((PAWN_MOVES>>i) & 1 == 1) {
            strcat(moves, i%8+1); // from file
            strcat(moves, i%8); // to file
            strcat(moves, "QP"); // queen promotion
            strcat(moves, i%8+1); // from file
            strcat(moves, i%8); // to file
            strcat(moves, "RP"); // queen promotion
        }
    }
    /* forward promotion */
    PAWN_MOVES = (WP>>8) & EMPTY & RANK_8;
    for (int i = 0; i < N_TILES; i++) {
        if ((PAWN_MOVES >> i) & 1 == 1) {
            strcat(moves, i%8); // from file
            strcat(moves, i%8); // to file
            strcat(moves, "QP"); // queen promotion
            strcat(moves, i%8); // from file
            strcat(moves, i%8); // to file
            strcat(moves, "RP"); // queen promotion
        }
    }
    /* add enpassant */
}
