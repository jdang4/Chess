#ifndef TERMINALBOARD_H
#define TERMINALBOARD_H

#include <vector>
#include <iostream>
#include "Board.h"

class TerminalBoard {

    public:
        TerminalBoard();
        virtual ~TerminalBoard();
        void printBoard(Board *b);
        TerminalBoard verHistory(int ver);
        void update();
        
    private:  
        int printCount = 0;
        void storeVer();
        std::vector<TerminalBoard*> history; 

};

#endif
