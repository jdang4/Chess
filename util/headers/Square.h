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
    void setPosition(int r, int c) { r = row; c = column; }
    int distanceTo(Square* dest);


    private:
    int row;
    int column;

};

#endif