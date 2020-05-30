#ifndef SQUARE_H
#define SQUARE_H

#include <cstdlib>
#include <iostream>
#include <tuple>

class Square {

    public:

    bool operator ==(const Square &s2) const { return s2.row == row && s2.column == column; }
    
    /*
    * referenced @ https://stackoverflow.com/questions/17761892/c-map-find-overloading-for-different-class
    */
    bool operator<(const Square& s) const
    { 
        return std::tie(row, column) < std::tie(s.row, s.column);
    } 

    Square(int r, int y);
    virtual ~Square();

    static Square* makeSquare(int r, int y);
    int getRow() const { return row; }
    int getColumn() const { return column; }
    void setPosition(int r, int c) { row = r; column = c; }
    int distanceTo(Square* dest);

    private:
    int row;
    int column;

};

#endif