#include <ctype.h>
#include <libchessviz/include/parser_module.h>

#define COORD_MIN_BOUND 0
#define COORD_MAX_BOUND 7
#define COORDS_COUNT 4

static int in_range(int value)
{
    return (value >= COORD_MIN_BOUND) && (value <= COORD_MAX_BOUND);
}

static void fill_point(PointInt* point, int x, int y)
{
    point->X = x;
    point->Y = y;
}

ParserErrorType parse_input(ChessBoard* board, ChessMove* move, char* input)
{
    if ((input[2] != '-') && (input[2] != 'x'))
        return ParserErrorTypeUndefinedMoveType;
    int coords[] = {toupper((int)input[0]) - 'A', (int)input[1] - '1', toupper((int)input[3]) - 'A',
                    (int)input[4] - '1'};
    for (int i = 0; i < COORDS_COUNT; ++i)
        if (!in_range(coords[i]))
            return ParserErrorTypeEmptyIncorrectCoordinates;
    if ((input[2] == 'x') && (board->Map[coords[3]][coords[2]] == ' '))
        return ParserErrorTypeEmptyTakePosition;
    move->Type = input[2];
    fill_point(&(move->CurrentPos), coords[0], coords[1]);
    fill_point(&(move->NextPos), coords[2], coords[3]);
    return ParserErrorTypeNoError;
}