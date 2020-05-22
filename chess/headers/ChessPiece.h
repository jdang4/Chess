#ifndef CHESSPIECE_H
#define CHESSPIECE_H

class ChessPieceDescriptor;

class ChessPiece {

    public :

	// constructor
	ChessPiece(ChessPieceDescriptor *descriptor);

	// destructor
	virtual ~ChessPiece();

	// class methods
	bool getHasMoved();
	ChessPieceDescriptor* getDescriptor();
	char const* getPieceName();
	char const* getPieceColor();
    
    private :
	// class attributes
	bool hasMoved; 
	ChessPieceDescriptor* descriptor;
};

#endif
