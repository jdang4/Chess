#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
    
    public:
    Coordinate(int r, int y);
    virtual ~Coordinate();

    static Coordinate* makeCoordinate(int r, int y);
    int getRow();
    int getColumn();
    int distanceTo(Coordinate* dest);


    private:
    int row;
    int column;

};

#endif