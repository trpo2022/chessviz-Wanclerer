#pragma once

#define COL 8
#define RAW 8

typedef struct
{
    char Map[COL][RAW];
} ChessBoard;

static inline ChessBoard init_board()
{
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}}};
    return board;
}