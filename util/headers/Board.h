#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
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
        // bool isOccupied(Square *sq);
        bool isOccupied(Square sq);
        void removePiece(Square sq, Color color);
        void updateKey(int r, int c, Square sq);
        ChessPiece* getChessPiece(Square sq);
        std::vector<Square> getAllbPieces() { return bPieces; }
        std::vector<Square> getAllwPieces() { return wPieces; }
        std::map<Square, ChessPiece*> getGameBoard() { return gameBoard; } // for testing purposes


    private:   
        // Square **chessBoard = new Square*[8];
        const int MAX_ROWS = 8;
        const int MAX_COLUMNS = 8;
        const int WHITE = 0;
        const int BLACK = 0;

        void initBoard();
        void populateVect();
        std::map<Square, ChessPiece*> gameBoard;

        //prolly don't need these anymore since we can compare directly
        std::vector<Square> bPieces;
        std::vector<Square> wPieces;
        
};

#endif
