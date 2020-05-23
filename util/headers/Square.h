#ifndef SQUARE_H
#define SQUARE_H

#include <cstdlib>

class Square {
    
    public:
    Square(int r, char y);
    virtual ~Square();

    static Square* makeSquare(int r, char y);
    int getRow() { return row; }
    char getColumn() { return column; }
    int distanceTo(Square* dest);


    private:
    int row;
    char column;

};

#endif