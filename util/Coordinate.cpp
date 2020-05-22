#include <iostream>
#include <cstdlib>

#include "headers/Coordinate.h"

const auto orthoCheck = [](Coordinate* start, Coordinate* end) 
{
    return start->getRow() == end->getRow() || start->getColumn() == end->getColumn();
};

const auto diagonalCheck = [](Coordinate* start, Coordinate* end)
{
    return abs(start->getRow() - end->getRow()) == abs(start->getColumn() - end->getColumn());
};

Coordinate::Coordinate(int r, int c) {
    row = r;
    column = c;
}

Coordinate::~Coordinate() {}

Coordinate* Coordinate::makeCoordinate(int r, int c) {
    Coordinate* coord = new Coordinate(r, c);

    return coord;
}

/**
 * Gets the distance between the calling coordinate to the destination coordinate
 * 
 * dest - the Coordinate to get the distance to
 * 
 * return 
 *      the calculated distance between the 2 coordinates or -1 if not moving in a straight line
*/
int Coordinate::distanceTo(Coordinate* dest) {
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

int Coordinate::getRow() {
    return row;
}

int Coordinate::getColumn() {
    return column;
}
