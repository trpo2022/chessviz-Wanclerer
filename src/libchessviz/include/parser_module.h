#pragma once

#include <libchessviz/include/chess_board.h>
#include <libchessviz/include/chess_move.h>

typedef enum
{
    ParserErrorTypeNoError,
    ParserErrorTypeUndefinedMoveType,
    ParserErrorTypeEmptyTakePosition,
    ParserErrorTypeEmptyIncorrectCoordinates,
} ParserErrorType;

ParserErrorType parse_input(ChessBoard* board, ChessMove* move, char* input);