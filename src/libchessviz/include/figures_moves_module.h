#pragma once

#include <libchessviz/include/chess_board.h>
#include <libchessviz/include/chess_move.h>

int check_transform(char choise, Color color);
MoveErrorType check_white_pawn(ChessBoard* board, ChessMove* move);
MoveErrorType check_black_pawn(ChessBoard* board, ChessMove* move);
MoveErrorType check_rock(ChessBoard* board, ChessMove* move);
MoveErrorType check_horse(ChessBoard* board, ChessMove* move);
MoveErrorType check_bishop(ChessBoard* board, ChessMove* move);
MoveErrorType check_king(ChessBoard* board, ChessMove* move);
MoveErrorType check_queen(ChessBoard* board, ChessMove* move);