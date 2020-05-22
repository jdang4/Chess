#include "headers/Board.h"
#include "headers/Square.h"

/**
 * TODO: Hashmap of <Square, Piece>
 *  - Compare if something exists on Hashmap
 *  - Check if a square exists on coordinate
 *  - check what piece is on the square
 *  - Remove piece
 *  - check boundaries with square - is it valid?
 *  - Populate with proper starting coordinates of each unit  
 */


Board::Board() {
    for(int r = 0; r < MAX_ROWS; r++) {
        chessBoard[r] = new Square(0,0); // will fix
    }
}

Board::~Board() {}