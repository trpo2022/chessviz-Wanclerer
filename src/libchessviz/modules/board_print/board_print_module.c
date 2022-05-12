#include <libchessviz/include/board_print_module.h>
#include <stdio.h>

void print_board(ChessBoard* board)
{
    int i, j;
    for (i = COL - 1; i >= 0; i--)
    {
        printf("%d ", i + 1);
        for (j = 0; j < RAW; j++)
        {
            printf("%c ", board->Map[i][j]);
        }
        printf("\n");
    }
    printf("  ");
    for (i = 0; i < RAW; i++)
    {
        printf("%c ", i + 'a');
    }
    printf("\n");
}