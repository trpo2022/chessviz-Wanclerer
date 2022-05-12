#include <libchessviz/include/board_print_module.h>
#include <libchessviz/include/core_module.h>
#include <libchessviz/include/game_module.h>
#include <libchessviz/include/io_module.h>
#include <libchessviz/include/parser_module.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int read_input(char** inp)
{
    uptr_t length;
    *inp = readline(&length);
    if (strlen(*inp) != 6) {
        free(*inp);
        return 0;
    }
    return 1;
}

void print_parser_error(ParserErrorType err)
{
    switch (err) {
    case ParserErrorTypeUndefinedMoveType:
        writeline("Undefined move type. For move => '-', for take => 'x'.");
        break;
    case ParserErrorTypeEmptyTakePosition:
        writeline("You're trying to take empty position (without figure)!");
        break;
    case ParserErrorTypeEmptyIncorrectCoordinates:
        writeline("Please, check your coordinates. Note: x = [aA-hH], y = [1-8].");
        break;
    default:
        return;
    }
}

void print_move_error(MoveErrorType err)
{
    switch (err) {
    case MoveErrorTypeFailedMove:
        writeline("You can't move like this!");
        break;
    case MoveErrorTypeNotEmptyMotionPosition:
        writeline("You should take in this move! For move => '-', for take => 'x'.");
        break;
    case MoveErrorTypeUnknownFigureToTake:
        writeline("You're trying to take cell without figure or with your figure!");
        break;
    default:
        return;
    }
}

void run()
{
    int status = 0;
    writeline("Chessviz!\nExample motion move: E2-E4.\nExample take move: E2xE4.");

    ChessBoard board = init_board();

    Color color = ColorWhite;
    int is_running = 1;
    int err = 0;
    while (is_running) {
        system("clear");
        err = 0;
        char* inp = NULL;
        print_board(&board);
        printf(color == ColorBlack ? "Black (Lower case):" : "White (Upper case):");
        if (!read_input(&inp)) {
            writeline("Wrong input. Please, try again!");
            continue;
        }
        ChessMove chess_move;
        err = parse_input(&board, &chess_move, inp);
        if (err != ParserErrorTypeNoError) {
            print_parser_error(err);
            continue;
        }
        err = make_move(&board, &chess_move, color);
        if (err != MoveErrorTypeNoError) {
            print_move_error(err);
            continue;
        }
        update_board(&board, &chess_move);
        status = is_gameover(&board, color);
        if (status != 0)
            is_running = 0;
        color = color == ColorBlack ? ColorWhite : ColorBlack;
        free(inp);
    }
    print_board(&board);

    printf("Player %d win\n", status);
}