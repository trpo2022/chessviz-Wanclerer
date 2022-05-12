#include <ctest.h>
#include <libchessviz/include/figures_moves_module.h>
#include <libchessviz/include/parser_module.h>

CTEST(module_figures_moves, check_transform_white)
{
    char choises[] = "RNBQ";
    for (int i = 0; i < 4; ++i)
        ASSERT_EQUAL(1, check_transform(choises[i], ColorWhite));
    ASSERT_EQUAL(0, check_transform('k', ColorWhite));
    ASSERT_EQUAL(0, check_transform('K', ColorWhite));
    ASSERT_EQUAL(0, check_transform('X', ColorWhite));
}

CTEST(module_figures_moves, check_transform_black)
{
    char choises[] = "rnbq";
    for (int i = 0; i < 4; ++i)
        ASSERT_EQUAL(1, check_transform(choises[i], ColorBlack));
    ASSERT_EQUAL(0, check_transform('K', ColorBlack));
    ASSERT_EQUAL(0, check_transform('k', ColorBlack));
    ASSERT_EQUAL(0, check_transform('X', ColorBlack));
}

CTEST(module_figures_moves, move_white_pawn)
{
    ChessBoard board = init_board();
    ChessMove move;
    parse_input(&board, &move, "a2-a4");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_white_pawn(&board, &move));

    parse_input(&board, &move, "a7-a5");
    ASSERT_EQUAL(MoveErrorTypeFailedMove, check_white_pawn(&board, &move));
}

CTEST(module_figures_moves, take_white_pawn)
{
    ChessMove move;
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                {' ', ' ', 'p', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', ' ', 'p', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}}};

    parse_input(&board, &move, "d2xc3");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_white_pawn(&board, &move));
}

CTEST(module_figures_moves, transform_white_pawn)
{
    ChessMove move;
    ChessBoard transform_board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                          {'P', 'P', ' ', 'P', 'P', 'P', 'P', 'P'},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {'p', 'p', 'P', 'p', 'p', 'p', 'p', 'p'},
                                          {'r', 'n', ' ', 'q', 'k', 'b', 'n', 'r'}}};

    parse_input(&transform_board, &move, "c7-c8");
    ASSERT_EQUAL(MoveErrorTypeRequiredToTransform, check_white_pawn(&transform_board, &move));
}

CTEST(module_figures_moves, move_black_pawn)
{
    ChessBoard board = init_board();
    ChessMove move;
    parse_input(&board, &move, "a7-a6");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_black_pawn(&board, &move));

    parse_input(&board, &move, "a2-a4");
    ASSERT_EQUAL(MoveErrorTypeFailedMove, check_black_pawn(&board, &move));
}

CTEST(module_figures_moves, take_black_pawn)
{
    ChessMove move;
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                {'P', 'P', 'P', ' ', 'P', 'P', 'P', 'P'},
                                {' ', ' ', ' ', 'P', ' ', ' ', ' ', ' '},
                                {' ', ' ', 'p', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', ' ', 'p', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}}};

    parse_input(&board, &move, "c4xd3");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_black_pawn(&board, &move));
}

CTEST(module_figures_moves, transform_black_pawn)
{
    ChessMove move;
    ChessBoard transform_board = {.Map = {{'R', 'N', ' ', 'Q', 'K', 'B', 'N', 'R'},
                                          {'P', 'P', 'p', 'P', 'P', 'P', 'P', 'P'},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                          {'p', 'p', ' ', 'p', 'p', 'p', 'p', 'p'},
                                          {'r', 'n', ' ', 'q', 'k', 'b', 'n', 'r'}}};

    parse_input(&transform_board, &move, "c2-c1");
    ASSERT_EQUAL(MoveErrorTypeRequiredToTransform, check_black_pawn(&transform_board, &move));
}

CTEST(module_figures_moves, move_rock)
{
    ChessMove move;
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', 'R', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', ' ', 'p', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}}};

    parse_input(&board, &move, "c3-h3");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_rock(&board, &move));

    parse_input(&board, &move, "c3-c2");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_rock(&board, &move));
}

CTEST(module_figures_moves, move_bishop)
{
    ChessMove move;
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', ' ', ' ', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', ' ', 'b', 'n', 'r'}}};

    parse_input(&board, &move, "c6-f3");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_bishop(&board, &move));
}

CTEST(module_figures_moves, move_queen)
{
    ChessMove move;
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {'p', 'p', ' ', ' ', 'p', 'p', 'p', 'p'},
                                {'r', 'n', 'b', 'q', ' ', 'b', 'n', 'r'}}};

    parse_input(&board, &move, "d5-e5");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));

    parse_input(&board, &move, "d5-c5");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));

    parse_input(&board, &move, "d5-d4");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));

    parse_input(&board, &move, "d5-d6");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));

    parse_input(&board, &move, "d5-c6");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));

    parse_input(&board, &move, "d5-c4");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));

    parse_input(&board, &move, "d5-e5");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));

    parse_input(&board, &move, "d5-e4");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_queen(&board, &move));
}

/*CTEST(module_figures_moves, move_horse)
{
    ChessMove move;
    ChessBoard board = {.Map = {{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {' ', ' ', 'N', ' ', ' ', ' ', ' ', ' '},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                     {'p', 'p', ' ', 'p', 'p', 'p', 'p', 'p'},
                                     {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}}};

    parse_input(&board, &move, "c3-h3");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_rock(&board, &move));

    parse_input(&board, &move, "c3-c2");
    ASSERT_EQUAL(MoveErrorTypeNoError, check_rock(&board, &move));
}*/