#include <ctest.h>
#include <libchessviz/include/core_module.h>
#include <libchessviz/include/parser_module.h>

CTEST(module_core, update_board)
{
    ChessBoard board = init_board();
    ChessMove move;
    parse_input(&board, &move, "a2-a4");
    update_board(&board, &move);
    ASSERT_EQUAL(' ', board.Map[move.CurrentPos.Y][move.CurrentPos.X]);
    ASSERT_EQUAL('P', board.Map[move.NextPos.Y][move.NextPos.X]);
}

CTEST(module_core, game_over_white)
{
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', ' ', 'p', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', ' ', 'b', 'n', 'r'}}};
    ASSERT_EQUAL(ColorWhite, is_gameover(&board, ColorBlack));
}

CTEST(module_core, game_over_black)
{
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', ' ', 'B', 'N', 'R'},
                                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', ' ', 'p', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}}};
    ASSERT_EQUAL(ColorBlack, is_gameover(&board, ColorWhite));
}