#ifndef CHESSPIECEFACTORY_H
#define CHESSPIECEFACTORY_H

class ChessPiece;
class ChessPieceDescriptor;

class ChessPieceFactory {

    public:

	// constructor
	ChessPieceFactory();

	// destructor
	virtual ~ChessPieceFactory();

	// class methods
	ChessPiece* makePiece(ChessPieceDescriptor* des);
};

#endif
