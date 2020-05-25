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

    cout << des->getPieceName() << " KING" << endl;

    ChessPieceFactory* factory = new ChessPieceFactory();

    ChessPiece* piece = factory->makePiece(des);

    Square* start = Square::makeSquare(1, 1);
    Square* dest = Square::makeSquare(2, 2);

    cout << start->distanceTo(dest) << endl;

    puts("----------Testing Board and Square-----------");
    Board *b = new Board();
    map<Square, ChessPiece*> gameA = b->getGameBoard();
    vector<Square> bPieces = b->getAllbPieces();
    vector<Square> wPieces = b->getAllwPieces();
    Square squareNoPtr(1,1);
    Square squareNoPtr1(1,1);

    cout << "Black Pieces: ";
    for(int i = 0; i < bPieces.size(); i++) 
        cout << bPieces.at(i).getRow() << " ";

    cout << "\nWhite Pieces: ";
    for(int i = 0; i < wPieces.size(); i++) 
        cout << wPieces.at(i).getRow() << " ";

    if(b->isOccupied(squareNoPtr)) cout << "\nisOccupied works" << endl;
    if(squareNoPtr1 == squareNoPtr) cout << "Comparator overload of object worked..." << endl;
    puts("---------------------------------------------");

    return 0;
}
