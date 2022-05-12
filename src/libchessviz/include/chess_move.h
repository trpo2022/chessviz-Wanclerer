#pragma once

typedef struct
{
    int X;
    int Y;
} PointInt;

typedef enum
{
    ColorBlack,
    ColorWhite,
} Color;

typedef struct
{
    PointInt CurrentPos;
    PointInt NextPos;
    char Type;
} ChessMove;

typedef enum
{
    MoveErrorTypeFailedMove,
    MoveErrorTypeNoError,
    MoveErrorTypeNotEmptyMotionPosition,
    MoveErrorTypeUnknownFigureToTake,
    MoveErrorTypeRequiredToTransform,
} MoveErrorType;