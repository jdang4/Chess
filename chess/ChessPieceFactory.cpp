#include "headers/ChessPieceFactory.h"
#include "headers/ChessPiece.h"
#include "headers/ChessPieceDescriptor.h"

ChessPieceFactory::ChessPieceFactory() {}

ChessPieceFactory::~ChessPieceFactory() {}

ChessPiece* ChessPieceFactory::makePiece(ChessPieceDescriptor* des) {
    ChessPiece* piece = new ChessPiece(des);
    return piece;
}
