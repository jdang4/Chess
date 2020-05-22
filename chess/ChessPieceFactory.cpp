#include "headers/ChessPieceFactory.h"
#include "headers/ChessPiece.h"
#include "headers/ChessPieceDescriptor.h"

ChessPiece* ChessPieceFactory::makePiece(ChessPieceDescriptor* des) {
    ChessPiece* piece = new ChessPiece(des);
    return piece;
}
