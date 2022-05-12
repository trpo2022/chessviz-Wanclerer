#include <ctype.h>
#include <libchessviz/include/direction_module.h>
#include <libchessviz/include/figures_moves_module.h>

int check_transform(char choise, Color color)
{
    char figures[] = {'r', 'n', 'b', 'q'};
    if (color == ColorWhite)
        for (int i = 0; i < sizeof(figures); ++i)
            figures[i] = toupper(figures[i]);
    for (int i = 0; i < sizeof(figures); ++i)
        if (figures[i] == choise)
            return 1;
    return 0;
}

MoveErrorType check_white_pawn(ChessBoard* board, ChessMove* move)
{
    if ((board->Map[move->NextPos.Y][move->NextPos.X] == ' ') && (move->CurrentPos.Y == 1) &&
        (move->CurrentPos.X == move->NextPos.X) && (move->NextPos.Y - move->CurrentPos.Y > 0) &&
        (move->NextPos.Y - move->CurrentPos.Y < 3) && check_direction_y(board, move))
        return MoveErrorTypeNoError;
    if ((board->Map[move->NextPos.Y][move->NextPos.X] == ' ') && (move->NextPos.X == move->CurrentPos.X) &&
        (move->NextPos.Y - move->CurrentPos.Y == 1))
        return MoveErrorTypeRequiredToTransform;
    if ((board->Map[move->NextPos.Y][move->NextPos.X] < 's' && board->Map[move->NextPos.Y][move->NextPos.X] > 'a') &&
        ((move->NextPos.X - move->CurrentPos.X == 1) || (move->NextPos.X - move->CurrentPos.X == -1)) &&
        (move->NextPos.Y - move->CurrentPos.Y == 1) && (move->Type == 'x'))
        return MoveErrorTypeNoError;
    return MoveErrorTypeFailedMove;
}

MoveErrorType check_black_pawn(ChessBoard* board, ChessMove* move)
{
    if ((board->Map[move->NextPos.Y][move->NextPos.X] == ' ') && (move->CurrentPos.Y == 6) &&
        (move->CurrentPos.X == move->NextPos.X) && (move->CurrentPos.Y - move->NextPos.Y > 0) &&
        (move->CurrentPos.Y - move->NextPos.Y < 3) && check_direction_y(board, move))
        return MoveErrorTypeNoError;
    if ((board->Map[move->NextPos.Y][move->NextPos.X] == ' ') && (move->NextPos.X == move->CurrentPos.X) &&
        (move->CurrentPos.Y - move->NextPos.Y == 1))
        return MoveErrorTypeRequiredToTransform;
    if ((board->Map[move->NextPos.Y][move->NextPos.X] < 'S' && board->Map[move->NextPos.Y][move->NextPos.X] > 'A') &&
        ((move->CurrentPos.X - move->NextPos.X == 1) || (move->CurrentPos.X - move->NextPos.X == -1)) &&
        (move->CurrentPos.Y - move->NextPos.Y == 1) && (move->Type == 'x'))
        return MoveErrorTypeNoError;
    return MoveErrorTypeFailedMove;
}

MoveErrorType check_rock(ChessBoard* board, ChessMove* move)
{
    if ((move->NextPos.Y == move->CurrentPos.Y) && (check_direction_x(board, move)))
        return MoveErrorTypeNoError;
    if ((move->NextPos.X == move->CurrentPos.X) && (check_direction_y(board, move)))
        return MoveErrorTypeNoError;
    return MoveErrorTypeFailedMove;
}

MoveErrorType check_horse(ChessBoard* board, ChessMove* move)
{
    if ((move->CurrentPos.Y - move->NextPos.Y == 2) && (move->CurrentPos.X - move->NextPos.X == 1))
        return MoveErrorTypeNoError;
    if ((move->NextPos.Y - move->CurrentPos.Y == 2) && (move->NextPos.X - move->CurrentPos.X == 1))
        return MoveErrorTypeNoError;
    if ((move->NextPos.Y - move->CurrentPos.Y == 2) && (move->CurrentPos.X - move->NextPos.X == 1))
        return MoveErrorTypeNoError;
    if ((move->CurrentPos.Y - move->NextPos.Y == 2) && (move->NextPos.X - move->CurrentPos.X == 1))
        return MoveErrorTypeNoError;
    if ((move->CurrentPos.Y - move->NextPos.Y == 1) && (move->NextPos.X - move->CurrentPos.X == 2))
        return MoveErrorTypeNoError;
    if ((move->NextPos.Y - move->CurrentPos.Y == 1) && (move->NextPos.X - move->CurrentPos.X == 2))
        return MoveErrorTypeNoError;
    if ((move->CurrentPos.Y - move->NextPos.Y == 1) && (move->CurrentPos.X - move->NextPos.X == 2))
        return MoveErrorTypeNoError;
    if ((move->NextPos.Y - move->CurrentPos.Y == 1) && (move->CurrentPos.X - move->NextPos.X == 2))
        return MoveErrorTypeNoError;
    return MoveErrorTypeFailedMove;
}

MoveErrorType check_bishop(ChessBoard* board, ChessMove* move)
{
    return (MoveErrorType)check_direction_d(board, move);
}

MoveErrorType check_king(ChessBoard* board, ChessMove* move)
{
    return (MoveErrorType)(move->CurrentPos.Y - move->NextPos.Y != 1 && move->NextPos.Y - move->CurrentPos.Y != 1 &&
                           move->CurrentPos.X - move->NextPos.X != 1 && move->NextPos.X - move->CurrentPos.X != 1);
}

MoveErrorType check_queen(ChessBoard* board, ChessMove* move)
{
    int result = check_direction_x(board, move) || check_direction_y(board, move) || check_direction_d(board, move);
    return (MoveErrorType)(result);
}
