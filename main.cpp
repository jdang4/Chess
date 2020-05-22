#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "chess/headers/ChessPieceDescriptor.h"
#include "chess/headers/ChessPiece.h"
#include "chess/headers/ChessPieceFactory.h"

using namespace std;

int main() {

    ChessPieceDescriptor* des = new ChessPieceDescriptor(Color::WHITE, Name::KING);

    cout << des->getPieceName() << endl;

    ChessPieceFactory* factory = new ChessPieceFactory();

    ChessPiece* piece = factory->makePiece(des);

    cout << piece->getHasMoved() << endl;
}
