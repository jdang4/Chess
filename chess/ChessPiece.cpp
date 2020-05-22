#include <iostream>
#include <cstdlib>
#include "headers/ChessPiece.h"
#include "headers/ChessPieceDescriptor.h"

ChessPiece::ChessPiece(ChessPieceDescriptor* des) {
    
    descriptor = des;
    hasMoved = false;
}

ChessPiece::~ChessPiece() {}

bool ChessPiece::getHasMoved() {
    return hasMoved;
}

ChessPieceDescriptor* ChessPiece::getDescriptor() {
    return descriptor;
}
