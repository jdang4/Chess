#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <vector>

#include "chess/headers/ChessPieceDescriptor.h"
#include "chess/headers/ChessPiece.h"
#include "chess/headers/ChessPieceFactory.h"
#include "chess/headers/ChessMovementRules.h"
#include "chess/headers/RuleProvider.h"
#include "util/headers/Square.h"
#include "util/headers/Board.h"

using namespace std;

int main() {

    ChessPieceDescriptor* des = new ChessPieceDescriptor(Color::WHITE, Name::KING);

    ChessPieceFactory* factory = new ChessPieceFactory();

    ChessPiece* piece = factory->makePiece(des);

    Square* start = Square::makeSquare(1, 1);
    Square* dest = Square::makeSquare(2, 2);

    cout << start->distanceTo(dest) << endl;

    puts("----------Testing Board and Square-----------");
    Board *b = new Board();
    map<Square, ChessPiece> gameA = b->getGameBoard();
    vector<Square> bPieces = b->getAllbPieces();
    vector<Square> wPieces = b->getAllwPieces();
    Square squareNoPtr(1,1);
    Square squareNoPtr1(1,1);
    Square squareNoPtr2(2,2);

    cout << "Black Pieces: ";
    for(int i = 0; i < bPieces.size(); i++) 
        cout << bPieces.at(i).getRow() << " ";

    cout << "\nWhite Pieces: ";
    for(int i = 0; i < wPieces.size(); i++) 
        cout << wPieces.at(i).getRow() << " ";

    if(b->isOccupied(squareNoPtr)) cout << "\nisOccupied works" << endl;
    if(squareNoPtr1 == squareNoPtr) cout << "Comparator overload of Square object worked..." << endl;

    b->updateKey(4, 4, Square(1, 1)); // move Rook to spot 4, 4    
    if(!b->isOccupied(squareNoPtr1) && b->isOccupied(Square(4, 4))) cout << "updateKey() works..." << endl;

    puts("---------------------------------------------");

    auto foundKey = gameA.find(squareNoPtr);

    if (foundKey != gameA.end())
    {
        cout << "FOUND KEY" << endl;
        cout << foundKey->second.getPieceColor() << endl;
        cout << foundKey->second.getPieceName() << endl;
    }

    else
    {
        cout << "CAN'T FIND" << endl;
    }

    ChessMovementRules* rules = new ChessMovementRules();

    cout << rules->isValidTarget(Square::makeSquare(7, 2), Square::makeSquare(5, 2), b) << endl << endl;
    cout << rules->isPawnOneForward(Square::makeSquare(7, 2), Square::makeSquare(8, 2), b) << endl;

    RuleProvider* r = new RuleProvider();

    map<int, std::function<bool(Square*, Square*, Board*)>> myMap = r->getMoveRules();

    auto pieceKey = myMap.find(0);

    if (pieceKey != myMap.end())
    {
        cout << pieceKey->second(Square::makeSquare(2, 5), Square::makeSquare(3, 5), b) << endl;
    }

    return 0;
}
