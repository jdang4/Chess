#include "headers/ChessMovementRules.h"

#define WHITE_COLOR 0
#define BLACK_COLOR 1

ChessMovementRules::ChessMovementRules() {}

ChessMovementRules::~ChessMovementRules() {}

int ChessMovementRules::getColor(Square* coord, Board* b)
{
    ChessPiece* pieceAtCoordinate = b->getChessPiece(coord);

    return pieceAtCoordinate->getPieceColor();
}

bool ChessMovementRules::notSameCoordinate(Square* from, Square* to, Board* b)
{
    return !(from == to);
}

bool ChessMovementRules::isOrthogonal(Square* from, Square* to, Board* b)
{
    return from->getRow() == to->getRow() || from->getColumn() == to->getColumn();
}

bool ChessMovementRules::isDiagonal(Square* from, Square* to, Board* b)
{
    return abs(from->getRow() - to->getRow()) == abs(from->getColumn() - to->getColumn());
}

bool ChessMovementRules::isAdjacent(Square* from, Square* to, Board* b)
{
    return from->distanceTo(to) == 1;
}

bool ChessMovementRules::isLinear(Square* from, Square* to, Board* b)
{
    return isOrthogonal(from, to, b) || isDiagonal(from, to, b);
}

bool ChessMovementRules::isValidTarget(Square* from, Square* to, Board* b)
{
    ChessPiece* pieceAtDest = b->getChessPiece(to); 

    return (pieceAtDest == NULL || getColor(to, b) != getColor(from, b));
}

bool ChessMovementRules::isClearPath(Square* from, Square* to, Board* b)
{
    return b->isPathClear(from, to);
}

bool ChessMovementRules::canCaptureOpponent(Square* from, Square* to, Board* b)
{
    return (b->getChessPiece(to) != NULL && getColor(from, b) != getColor(to, b));
}

bool ChessMovementRules::hasPawnMoved(Square* from, Square* to, Board* b)
{   
    return ( (getColor(from, b) == WHITE_COLOR && from->getRow() == 2) ||
            (getColor(from, b) == BLACK_COLOR && from->getRow() == 7) );
}

bool ChessMovementRules::isPawnOneForward(Square* from, Square* to, Board* b)
{
    return ( 
        (from->getColumn() == to->getColumn()) &&
        (b->getChessPiece(to) == NULL) &&
        ( (getColor(from, b) == WHITE_COLOR) ? 
            from->getRow() == to->getRow() - 1 : from->getRow() == to->getRow() + 1
        )
    );
}

bool ChessMovementRules::isPawnTwoForward(Square* from, Square* to, Board* b)
{
    return ( 
        (from->getColumn() == to->getColumn()) &&
        (b->getChessPiece(to) == NULL) &&
        ( (getColor(from, b) == WHITE_COLOR) ? 
            from->getRow() == to->getRow() - 2 : from->getRow() == to->getRow() + 2
        )
    );
}

bool ChessMovementRules::isPawnOneDiagonal(Square* from, Square* to, Board* b)
{
    return (
        (isDiagonal(from, to, b)) &&
        ( (getColor(from, b) == WHITE_COLOR) ? 
            from->getRow() == to->getRow() - 1 : from->getRow() == to->getRow() + 1
        )
    );
}

bool ChessMovementRules::canPawnMove(Square* from, Square* to, Board* b)
{
    return ( 
        isPawnOneForward(from, to, b) ||
        (hasPawnMoved(from, to, b) && isPawnTwoForward(from, to, b) && isClearPath(from, to, b)) ||
        (isPawnOneDiagonal(from, to, b) && canCaptureOpponent(from, to, b))
    );
}

bool ChessMovementRules::canKnightMove(Square* from, Square* to, Board* b)
{
    return (
        (
            abs(from->getRow() - to->getRow() == 2) && 
            abs(from->getColumn() - to->getColumn() == 1)
        ) ||
        (
            abs(from->getRow() - to->getRow() == 1) && 
            abs(from->getColumn() - to->getColumn() == 2)
        ) 
    );
}

bool ChessMovementRules::canKingMove(Square* from, Square* to, Board* b)
{
    return isAdjacent(from, to, b);
}