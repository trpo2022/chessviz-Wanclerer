#include <libchessviz/include/core_module.h>
#include <libchessviz/include/figures_moves_module.h>
#include <stdio.h>
#include <string.h>

MoveErrorType make_move(ChessBoard* board, ChessMove* move, Color color)
{
    return color ? move_white(board, move) : move_black(board, move);
}

static void transform_pawn(ChessBoard* board, ChessMove* move, Color color)
{
    char left = color == ColorBlack ? 'p' : 'P';
    char right = color == ColorBlack ? 0 : 7;
    char pawn;
    if ((board->Map[move->CurrentPos.Y][move->CurrentPos.X] == left) && (move->NextPos.Y == right))
    {
        while (1)
        {
            printf("Enter new figure to transform pawn: ");
            pawn = getchar();
            if (check_transform(pawn, color))
                break;
            printf("Incorrect input. Avaliable: 'r', 'n', 'b', 'q'. Check case. Try again!\n");
        }
        board->Map[move->CurrentPos.Y][move->CurrentPos.X] = pawn;
    }
}

MoveErrorType move_white(ChessBoard* board, ChessMove* move)
{
    char next_tile = board->Map[move->NextPos.Y][move->NextPos.X];
    if ((move->Type == '-') && (next_tile != ' '))
        return MoveErrorTypeNotEmptyMotionPosition;
    if ((next_tile > 'A') && (next_tile < 'S'))
        return MoveErrorTypeUnknownFigureToTake;
    MoveErrorType err;
    switch (board->Map[move->CurrentPos.Y][move->CurrentPos.X])
    {
    case 'P':
        err = check_white_pawn(board, move);
        if (err == MoveErrorTypeRequiredToTransform)
        {
            transform_pawn(board, move, ColorWhite);
            return MoveErrorTypeNoError;
        }
        return err;
    case 'R':
        return check_rock(board, move);
    case 'N':
        return check_horse(board, move);
    case 'B':
        return check_bishop(board, move);
    case 'K':
        return check_king(board, move);
    case 'Q':
        return check_queen(board, move);
    }
    return MoveErrorTypeUnknownFigureToTake;
}

MoveErrorType move_black(ChessBoard* board, ChessMove* move)
{
    char next_tile = board->Map[move->NextPos.Y][move->NextPos.X];
    if ((move->Type == '-') && (next_tile != ' '))
        return MoveErrorTypeNotEmptyMotionPosition;
    if ((next_tile > 'a') && (next_tile < 's'))
        return MoveErrorTypeUnknownFigureToTake;
    MoveErrorType err;
    switch (board->Map[move->CurrentPos.Y][move->CurrentPos.X])
    {
    case 'p':
        err = check_black_pawn(board, move);
        if (err == MoveErrorTypeRequiredToTransform)
        {
            transform_pawn(board, move, ColorBlack);
            return MoveErrorTypeNoError;
        }
        return err;
    case 'r':
        return check_rock(board, move);
    case 'n':
        return check_horse(board, move);
    case 'b':
        return check_bishop(board, move);
    case 'k':
        return check_king(board, move);
    case 'q':
        return check_queen(board, move);
    }
    return MoveErrorTypeUnknownFigureToTake;
}

void update_board(ChessBoard* board, ChessMove* move)
{
    board->Map[move->NextPos.Y][move->NextPos.X] = board->Map[move->CurrentPos.Y][move->CurrentPos.X];
    board->Map[move->CurrentPos.Y][move->CurrentPos.X] = ' ';
}

int is_gameover(ChessBoard* board, Color status)
{
    int i, j, player = 0;
    int game_over = 1;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (board->Map[i][j] == ((status == ColorBlack) ? 'k' : 'K'))
            {
                game_over = 0;
            }
        }
    }
    if (game_over)
        player = !status;
    return player;
}