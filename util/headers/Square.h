#ifndef SQUARE_H
#define SQUARE_H

class Square {
    
    public:
    Square(int r, int y);
    virtual ~Square();

    static Square* makeSquare(int r, int y);
    int getRow();
    int getColumn();
    int distanceTo(Square* dest);


    private:
    int row;
    int column;

};

#endif