#include <iostream>
#include <cstdlib>
#include "headers/ChessPiece.h"


ChessPiece::ChessPiece(ChessPieceDescriptor* des) {
    
    descriptor = des;
    hasMoved = true;
}

ChessPiece::~ChessPiece() {}

bool ChessPiece::getHasMoved() {
    return hasMoved;
}

ChessPieceDescriptor* ChessPiece::getDescriptor() const {
    return descriptor;
}

int ChessPiece::getPieceName() {
    return descriptor->getPieceName();
}

int ChessPiece::getPieceColor() {
    return descriptor->getColor();
}

bool ChessPiece::canMove(Board* board, Square* from, Square* to)
{
    return false;
}