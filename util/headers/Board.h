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
        bool isPathClear(Square* from, Square* to);
        
        ChessPiece* getChessPiece(Square sq);
        std::vector<Square> getAllbPieces() { return bPieces; }
        std::vector<Square> getAllwPieces() { return wPieces; }
        std::map<Square, ChessPiece> getGameBoard() { return gameBoard; } // for testing purposes


    private:   
        // Square **chessBoard = new Square*[8];

        void initBoard();
        void populateVect();
        std::map<Square, ChessPiece> gameBoard; 

        //prolly don't need these anymore since we can compare directly
        std::vector<Square> bPieces;
        std::vector<Square> wPieces;
        
};

#endif
