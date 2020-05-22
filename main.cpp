#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "chess/headers/ChessPieceDescriptor.h"
#include "chess/headers/ChessPiece.h"
#include "chess/headers/ChessPieceFactory.h"
#include "util/headers/Square.h"

using namespace std;

int main() {

    ChessPieceDescriptor* des = new ChessPieceDescriptor(Color::WHITE, Name::KING);

    cout << des->getPieceName() << endl;

    ChessPieceFactory* factory = new ChessPieceFactory();

    ChessPiece* piece = factory->makePiece(des);

    Square* start = Square::makeSquare(1, 1);
    Square* dest = Square::makeSquare(2, 2);

    cout << start->distanceTo(dest) << endl;
    
    return -1;
}
