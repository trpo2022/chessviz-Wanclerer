#include <libchessviz/include/direction_module.h>

int check_direction_y(ChessBoard* board, ChessMove* move)
{
    int i, c1 = move->CurrentPos.Y, c2 = move->NextPos.Y;
    if (move->CurrentPos.X != move->NextPos.X)
        return 0;
    if (move->CurrentPos.Y > move->NextPos.Y)
    {
        c1 = move->NextPos.Y;
        c2 = move->CurrentPos.Y;
    }
    for (i = c1 + 1; i < c2; i++)
        if ((board->Map[i][move->CurrentPos.X] > 'a' && board->Map[i][move->CurrentPos.X] < 's') ||
            (board->Map[i][move->CurrentPos.X] > 'A' && board->Map[i][move->CurrentPos.X] < 'S'))
            return 0;
    return 1;
}

int check_direction_x(ChessBoard* board, ChessMove* move)
{
    int i, c1 = move->CurrentPos.X, c2 = move->NextPos.X;
    if (move->CurrentPos.Y != move->NextPos.Y)
        return 0;
    if (move->CurrentPos.X > move->NextPos.X)
    {
        c1 = move->NextPos.X;
        c2 = move->CurrentPos.X;
    }
    for (i = c1 + 1; i < c2; i++)
        if ((board->Map[move->CurrentPos.Y][i] > 'a' && board->Map[move->CurrentPos.Y][i] < 's') ||
            (board->Map[move->CurrentPos.Y][i] > 'A' && board->Map[move->CurrentPos.Y][i] < 'S'))
            return 0;
    return 1;
}

int check_direction_d(ChessBoard* board, ChessMove* move)
{
    int i, j, c1 = move->NextPos.Y, c2 = move->CurrentPos.Y, ci, cj;

    if (((move->NextPos.Y - move->CurrentPos.Y) != (move->NextPos.X - move->CurrentPos.X)) &&
        ((move->NextPos.Y - move->CurrentPos.Y) != (move->CurrentPos.X - move->NextPos.X)))
        return 0;

    if (move->NextPos.Y > move->CurrentPos.Y)
    {
        c1 = move->CurrentPos.Y;
        c2 = move->NextPos.Y;
        ci = 1;
    }
    else
    {
        ci = -1;
    }

    if (move->NextPos.X > move->CurrentPos.X)
        cj = 1;
    else
        cj = -1;

    i = move->CurrentPos.Y + ci;
    j = move->CurrentPos.X + cj;

    while ((i < c2) && (i > c1))
    {
        if (((board->Map[i][j] > 'a') && (board->Map[i][j] < 's')) ||
            ((board->Map[i][j] > 'A') && (board->Map[i][j] < 'S')))
            return 0;
        i += ci;
        j += cj;
    }
    return 1;
}