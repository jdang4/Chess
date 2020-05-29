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

#define MAX_SIZE 8
// #define WHITE_COLOR 0
// #define BLACK_COLOR 1

class Square;
class ChessPiece;

class Board {

    public:
        Board();
        virtual ~Board();
        // bool isOccupied(Square *sq);
        bool isOccupied(Square sq);
        void removePiece(Square sq, Color color);
        bool updateKey(int r, int c, Square sq);
        bool isPathClear(Square* from, Square* to);
        
        ChessPiece* getChessPiece(Square* sq);
        std::vector<ChessPiece*> getAllbPieces() { return bPieces; }
        std::vector<ChessPiece*> getAllwPieces() { return wPieces; }
        std::map<Square, ChessPiece> getGameBoard() { return gameBoard; } // for testing purposes


    private:   
        // Square **chessBoard = new Square*[8];

        void initBoard();
        void populateVect(ChessPiece* p);
        std::map<Square, ChessPiece> gameBoard; 

        std::vector<ChessPiece*> bPieces;
        std::vector<ChessPiece*> wPieces;
        
};

#endif
