#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "chess/headers/ChessPieceDescriptor.h"
#include "chess/headers/ChessPiece.h"
#include "chess/headers/ChessPieceFactory.h"
#include "util/headers/Coordinate.h"

using namespace std;

int main() {

    ChessPieceDescriptor* des = new ChessPieceDescriptor(Color::WHITE, Name::KING);

    cout << des->getPieceName() << endl;

    ChessPieceFactory* factory = new ChessPieceFactory();

    ChessPiece* piece = factory->makePiece(des);

    Coordinate* start = Coordinate::makeCoordinate(1, 1);
    Coordinate* dest = Coordinate::makeCoordinate(2, 2);

    cout << start->distanceTo(dest) << endl;

}
