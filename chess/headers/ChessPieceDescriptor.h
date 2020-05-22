#ifndef CHESSPIECEDESCRIPTOR_H
#define CHESSPIECEDESCRIPTOR_H 

enum Color {WHITE, BLACK};
enum Name {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};

class ChessPieceDescriptor {

    public:

    ChessPieceDescriptor(Color color, Name name);
    virtual ~ChessPieceDescriptor();

    char const* getColor();
    char const* getPieceName();

    private:
    Color color;
    Name name;

};



#endif
