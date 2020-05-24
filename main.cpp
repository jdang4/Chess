#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>

#include "chess/headers/ChessPieceDescriptor.h"
#include "chess/headers/ChessPiece.h"
#include "chess/headers/ChessPieceFactory.h"
#include "util/headers/Square.h"
#include "util/headers/Board.h"

using namespace std;

int main() {

    ChessPieceDescriptor* des = new ChessPieceDescriptor(Color::WHITE, Name::KING);

    cout << des->getPieceName() << endl;

    ChessPieceFactory* factory = new ChessPieceFactory();

    ChessPiece* piece = factory->makePiece(des);

    Square* start = Square::makeSquare(1, 1);
    Square* dest = Square::makeSquare(2, 2);

    cout << start->distanceTo(dest) << endl;

    Board *b = new Board();
    vector<Square*> bPieces = b->getAllbPieces();
    for(int i = 0; i < bPieces.size(); i++) 
        cout << bPieces.at(i)->getRow() << endl;

    if(b->isOccupied(bPieces.at(1))) cout << "TRUE" << endl;
    
    Square* s1 = new Square(1, 2);
    Square* s2 = new Square(1, 2);

    if(*s1 == *s2) cout << "Comparator overload worked..." << endl;

    return 0;
}
