#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "../../chess/headers/ChessPieceDescriptor.h"
#include "../../../Chess/util/headers/Board.h"
#include "../../../Chess/util/headers/Square.h"


class ChessPieceDescriptor;
class Board;
class Square;

class ChessPiece {

    public :

	// constructor
	ChessPiece(ChessPieceDescriptor *descriptor);

	// destructor
	virtual ~ChessPiece();

	// class methods
	bool getHasMoved();
	ChessPieceDescriptor* getDescriptor();
	int getPieceName();
	int getPieceColor();
    bool canMove(Board* board, Square* from, Square* to);

    private :
	// class attributes
	bool hasMoved; 
	ChessPieceDescriptor* descriptor;
};

#endif
