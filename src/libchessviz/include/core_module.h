#pragma once

#include <libchessviz/include/chess_board.h>
#include <libchessviz/include/chess_move.h>

MoveErrorType make_move(ChessBoard* board, ChessMove* move, Color flag);
int is_gameover(ChessBoard* board, Color status);
MoveErrorType move_white(ChessBoard* board, ChessMove* move);
MoveErrorType move_black(ChessBoard* board, ChessMove* move);
void update_board(ChessBoard* board, ChessMove* move);