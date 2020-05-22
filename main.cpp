#include <iostream>
#include <cstdlib>
#include <stdlib.h>

#include "chess/headers/ChessPieceDescriptor.h"

using namespace std;

int main() {

    ChessPieceDescriptor* des = new ChessPieceDescriptor(Color::WHITE, Name::KING);

    cout << des->getPieceName() << endl;
}
