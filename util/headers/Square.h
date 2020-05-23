#ifndef SQUARE_H
#define SQUARE_H

#include <cstdlib>

class Square {
    
    public:
    Square(int r, int y);
    virtual ~Square();

    static Square* makeSquare(int r, int y);
    int getRow() { return row; }
    int getColumn() { return column; }
    int distanceTo(Square* dest);


    private:
    int row;
    char column;

};

#endif