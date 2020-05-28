#include "headers/TerminalBoard.h"

/**
 *   * Game Board *
 * 8 bR bH bB bQ bK bB bH bR   Player 1: Tom (Black)
 * 7 bP bP bP bP bP bP bP bP   Player 2: Bob (White) 
 * 6                           Turn: printCount
 * 5                           
 * 4                           Tom's Pieces: *White pieces
 * 3                           Bob's Pieces: *Black Pieces
 * 2 wP wP wP wP wP wP wP wP
 * 1 wR wH wB wQ wK wB wH wR
 *   a  b  c  d  e  f  g  h
 * 
 * keys are actually reversed but appearance is what matters...
 * b: ♔ ♕ ♖ ♗ ♘ ♙
 * w: ♚ ♛ ♜ ♝ ♞ ♟
 */

TerminalBoard::TerminalBoard() { }

void TerminalBoard::printBoard(Board *b) {
    auto board = b->getGameBoard();
    // █
    if(printCount != 0) {
        // add to history bank
    }

    for(int i = 1; i <= 8; i++) {
        std::cout << "| ";
        for(int j = 1; j <= 8; j++) {
            if(j % 2 == 0 && i % 2 != 0) std::cout << "██  ";
            else if(j % 2 != 0 && i % 2 == 0) std::cout << "  ██";
        }
        std::cout << " |\n";
    }
    printCount++;
}

/**
 * @brief 
 * 
 * @param ver 
 * @return TerminalBoard 
 */
TerminalBoard TerminalBoard::verHistory(int ver) {
    return *history.at(ver);
}

/**
 * @brief 
 * 
 */
void TerminalBoard::storeVer() {
    history.push_back(this);
}

TerminalBoard::~TerminalBoard() { }