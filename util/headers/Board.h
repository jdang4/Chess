#ifndef BOARD_H
#define BOARD_H

class Square;

class Board {
    public:
        Board();
        virtual ~Board();

    private:
        Square **chessBoard = new Square*[8];
        const int MAX_ROWS = 8;
        const int MAX_COLUMNS = 8;

};

#endif
