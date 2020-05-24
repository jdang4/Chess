#ifndef SQUARE_H
#define SQUARE_H

#include <cstdlib>

class Square {
    friend bool operator ==(const Square &s1, const Square &s2) { return s2.row == s1.row && s2.column == s1.column; }

    public:
    Square(int r, int y);
    virtual ~Square();

    static Square* makeSquare(int r, int y);
    int getRow() { return row; }
    int getColumn() { return column; }
    void setPosition(int r, int c) { r = row; c = column; }
    // bool compareTo(Square *s1) { return (row == s1->row && column == s1->column); }
    int distanceTo(Square* dest);

    private:
    int row;
    int column;

};

// bool operator== (Square *s1, Square *s2) { 
//     return (s1->getRow() == s2->getRow() && s1->getColumn() == s2->getColumn()); 
// }

#endif