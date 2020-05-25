#ifndef SQUARE_H
#define SQUARE_H

#include <cstdlib>

class Square {

    public:

    bool operator ==(const Square &s2) const { return s2.row == row && s2.column == column; }
    bool operator<(const Square& t) const
    { 
        return (column + t.column) + (row + t.row); 
    } 
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