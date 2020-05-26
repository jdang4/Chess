#ifndef CHESSPIECEDESCRIPTOR_H
#define CHESSPIECEDESCRIPTOR_H 

enum Color {WHITE, BLACK};
enum Name {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};

class ChessPieceDescriptor {

    public:

    ChessPieceDescriptor(Color color, Name name);
    virtual ~ChessPieceDescriptor();

    int getColor();
    int getPieceName();
    void setColor(Color c);
    void setName(Name n);

    private:
    Color color;
    Name name;

};

#endif
