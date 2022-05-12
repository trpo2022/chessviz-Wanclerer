#include <ctest.h>
#include <libchessviz/include/parser_module.h>

CTEST(module_parser, parse_move_motion)
{
    ChessBoard board = init_board();
    ChessMove move;
    char input[] = "a2-a4";
    ASSERT_EQUAL(ParserErrorTypeNoError, parse_input(&board, &move, input));
}

CTEST(module_parser, parse_move_take)
{
    ChessBoard board = init_board();
    ChessMove move;
    char input[] = "a2xa7";
    ASSERT_EQUAL(ParserErrorTypeNoError, parse_input(&board, &move, input));
}

CTEST(module_parser, parse_unknown_move_type)
{
    ChessBoard board = init_board();
    ChessMove move;
    char input[] = "e2~e4";
    ASSERT_EQUAL(ParserErrorTypeUndefinedMoveType, parse_input(&board, &move, input));
}

CTEST(module_parser, parse_coordinates)
{
    ChessBoard board = init_board();
    ChessMove move;
    for (int i = 0; i < 8; ++i)
    {
        char input[] = {i + 'a', i + '1', '-', 'h' - i, '8' - i};
        ASSERT_EQUAL(ParserErrorTypeNoError, parse_input(&board, &move, input));
    }
}

CTEST(module_parser, parse_incorrect_coordinates)
{
    ChessBoard board = init_board();
    ChessMove move;

    char input[] = "q1xq4";
    ASSERT_EQUAL(ParserErrorTypeEmptyIncorrectCoordinates, parse_input(&board, &move, input));
}

CTEST(module_parser, parse_input)
{
    ChessBoard board = init_board();
    ChessMove move;

    char input[] = "d2-d4";
    parse_input(&board, &move, input);

    ASSERT_EQUAL(3, move.CurrentPos.X);
    ASSERT_EQUAL(1, move.CurrentPos.Y);
    ASSERT_EQUAL(3, move.NextPos.X);
    ASSERT_EQUAL(3, move.NextPos.Y);
    ASSERT_EQUAL('-', move.Type);
}