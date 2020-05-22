#include "headers/ChessPieceDescriptor.h"

ChessPieceDescriptor::ChessPieceDescriptor(Color pieceColor, Name pieceName) {
    color = pieceColor;
    name = pieceName;
}

ChessPieceDescriptor::~ChessPieceDescriptor(){}

char const* ChessPieceDescriptor::getColor() {
    char const* pieceColor;

    switch(color) {
        case 1 :
            pieceColor = "WHITE";
            break;

        case 2 :
            pieceColor = "BLACK";
            break;

        default :
            pieceColor = "";
            break;
    }

    return pieceColor;
}

char const* ChessPieceDescriptor::getPieceName() {
    char const* pieceName;

    switch(name) {

        case 1 :
            pieceName = "PAWN";
            break;
            
        case 2 :
            pieceName = "ROOK";
            break;

        case 3 :
            pieceName = "KNIGHT";
            break;

        case 4 :
            pieceName = "QUEEN";
            break;

        case 5 :
            pieceName = "KING";
            break;
        
        default :
            pieceName = "";
            break;
    }

    return pieceName;
}
