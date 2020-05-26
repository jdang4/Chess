#include "headers/ChessPieceDescriptor.h"
#include <iostream>

ChessPieceDescriptor::ChessPieceDescriptor(Color pieceColor, Name pieceName) {
    color = pieceColor;
    name = pieceName;
}

ChessPieceDescriptor::~ChessPieceDescriptor(){}

int ChessPieceDescriptor::getColor() {
    return color;
}

int ChessPieceDescriptor::getPieceName() {
    return name;
}

void ChessPieceDescriptor::setColor(Color c) {
    color = c;
}

void ChessPieceDescriptor::setName(Name n) {
    name = n;
}
