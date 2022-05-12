#pragma once

#include <libchessviz/include/chess_board.h>
#include <libchessviz/include/chess_move.h>

int check_direction_y(ChessBoard* board, ChessMove* move);
int check_direction_x(ChessBoard* board, ChessMove* move);
int check_direction_d(ChessBoard* board, ChessMove* move);
