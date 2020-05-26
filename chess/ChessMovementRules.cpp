#include "headers/ChessMovementRules.h"

#define WHITE_COLOR 0
#define BLACK_COLOR 1

ChessMovementRules::ChessMovementRules() {}

ChessMovementRules::~ChessMovementRules() {}

int ChessMovementRules::getColor(Square* coord, Board* board)
{
    Square c(coord->getRow(), coord->getColumn());
    ChessPiece* pieceAtCoordinate = board->getChessPiece(c);

    std::cout << pieceAtCoordinate->getPieceColor() << std::endl;

    return pieceAtCoordinate->getPieceColor();
}

bool ChessMovementRules::notSameCoordinate(Square* from, Square* to, Board* board)
{
    return !(from == to);
}

bool ChessMovementRules::isOrthogonal(Square* from, Square* to, Board* board)
{
    return from->getRow() == to->getRow() || from->getColumn() == to->getColumn();
}

bool ChessMovementRules::isDiagonal(Square* from, Square* to, Board* board)
{
    return abs(from->getRow() - to->getRow()) == abs(from->getColumn() - to->getColumn());
}

bool ChessMovementRules::isAdjacent(Square* from, Square* to, Board* board)
{
    return from->distanceTo(to) == 1;
}

bool ChessMovementRules::isLinear(Square* from, Square* to, Board* board)
{
    return isOrthogonal(from, to, board) || isDiagonal(from, to, board);
}

bool ChessMovementRules::isValidTarget(Square* from, Square* to, Board* board)
{
    ChessPiece* pieceAtDest = board->getChessPiece((*to)); 

    return (pieceAtDest == NULL || getColor(to, board) != getColor(from, board));
}

bool ChessMovementRules::isClearPath(Square* from, Square* to, Board* board)
{
    return board->isPathClear(from, to);
}

bool ChessMovementRules::hasPawnMoved(Square* from, Square* to, Board* board)
{   
    return ( (getColor(from, board) == WHITE_COLOR && from->getRow() == 2) ||
            (getColor(from, board) == BLACK_COLOR && from->getRow() == 7) );
    
   //return true;
}

