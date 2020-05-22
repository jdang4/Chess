#ifndef BOARD_H
#define BOARD_H

#include "Square.h"

class Board {
    public:
        Board();
        virtual ~Board();

    private:
        Square **chessBoard = new Square*[8];

};

#endif
