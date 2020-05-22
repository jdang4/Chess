#include "Headers/Board.h"

Board::Board() {
    for(int r = 0; r < 8; r++) {
        chessBoard[r] = new Square();
    }
}

Board::~Board() {}