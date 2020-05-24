#ifndef BOARD_H
#define BOARD_H

#include <unordered_map>
#include <vector>
#include "../../chess/headers/ChessPiece.h"
#include "../../chess/headers/ChessPieceDescriptor.h"
#include "../../chess/headers/ChessPieceFactory.h"
#include "../headers/Square.h"


class Square;
class ChessPiece;

class Board {
    public:
        Board();
        virtual ~Board();
        bool isOccupied(Square *sq);
        void removePiece(Square *sq, Color color);
        ChessPiece* getChessPiece(Square *sq);
        std::vector<Square*> getAllbPieces() { return bPieces; }
        std::vector<Square*> getAllwPieces() { return wPieces; }


    private:
        // Square **chessBoard = new Square*[8];
        const int MAX_ROWS = 8;
        const int MAX_COLUMNS = 8;
        const int WHITE = 0;
        const int BLACK = 0;


        void initBoard();
        void populateVect();
        std::unordered_map<Square*, ChessPiece*> gameBoard; 
        std::vector<Square*> bPieces;
        std::vector<Square*> wPieces;


};

#endif
