#ifndef TERMINALBOARD_H
#define TERMINALBOARD_H

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <iostream>
#include "Board.h"
#include "../../chess/headers/ChessPieceDescriptor.h"

class TerminalBoard {

    public:
        TerminalBoard(char *p1, char *p2);
        virtual ~TerminalBoard();
        void printBoard(Board *b);
        TerminalBoard verHistory(int ver);
        void updatePieces(Board* b);
        
    private:  
        int printCount = 0;
        const char* player1;
        const char* player2;
        void storeVer();
        void printPieces(Board* b);
        std::string returnChesspiecePrint(ChessPieceDescriptor c);
        std::vector<TerminalBoard*> history; 
        std::vector<ChessPiece*> P1Pieces; 
        std::vector<ChessPiece*> P2Pieces;
        const std::string w[6] = {"♟", "♜", "♞", "♝", "♛", "♚"};
        const std::string b[6] = {"♙", "♖", "♘", "♙", "♕", "♔"};

};

#endif
