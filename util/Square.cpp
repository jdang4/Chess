#include "headers/Square.h"

Square::Square(int r, int c) {
    row = r;
    column = c;
}

Square::~Square() {}

Square* Square::makeSquare(int r, int c) {
    Square* coord = new Square(r, c);

    return coord;
}

const auto orthoCheck = [](Square* start, Square* end) 
{
    return start->getRow() == end->getRow() || start->getColumn() == end->getColumn();
};

const auto diagonalCheck = [](Square* start, Square* end)
{
    return abs(start->getRow() - end->getRow()) == abs(start->getColumn() - end->getColumn());
};

/**
 * @brief Gets the distance between the calling Square to the destination Square
 * 
 * @param dest the Square to get the distance to
 * @return int the calculated distance between the 2 Squares or -1 if not moving in a straight line
 */
int Square::distanceTo(Square* dest) {
    int distance = -1;
    bool isOrthogonel = orthoCheck(this, dest);
    bool isDiagonal = diagonalCheck(this, dest);

    if (isOrthogonel) {
        distance = abs(this->getRow() - dest->getRow()) + abs(this->getColumn() - dest->getColumn());
    
    } else if (isDiagonal) {
        // only need to get row difference since row diff == col diff for diagonal
        distance = abs(this->getRow() - dest->getRow());
    }

    return distance;
}
