#ifndef TERMINALBOARD_H
#define TERMINALBOARD_H

#include <vector>
#include <iostream>
#include <string>
#include "Board.h"

class TerminalBoard {

    public:
        TerminalBoard(char *p1, char *p2);
        virtual ~TerminalBoard();
        void printBoard(Board *b);
        TerminalBoard verHistory(int ver);
        void updatePieces(Board* board);
        
    private:  
        int printCount = 0;
        const char* player1;
        const char* player2;
        void storeVer();
        void printChessPiece();
        std::vector<TerminalBoard*> history; 
        std::vector<ChessPiece*> P1Pieces; 
        std::vector<ChessPiece*> P2Pieces; 

};

#endif
