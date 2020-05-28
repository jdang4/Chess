#include "headers/TerminalBoard.h"

/**
 *   * Game Board *
 * 8 bR bH bB bQ bK bB bH bR   Player 1: Tom (Black)
 * 7 bP bP bP bP bP bP bP bP   Player 2: Bob (White) 
 * 6                           Turn: printCount
 * 5                           
 * 4                           Tom: *White pieces
 * 3                           Bob: *Black Pieces
 * 2 wP wP wP wP wP wP wP wP
 * 1 wR wH wB wQ wK wB wH wR
 *   a  b  c  d  e  f  g  h
 * 
 * keys are actually reversed but appearance is what matters...
 * ■ █
 * b: ♔ ♕ ♖ ♗ ♘ ♙
 * w: ♚ ♛ ♜ ♝ ♞ ♟
 */

TerminalBoard::TerminalBoard(char *p1, char *p2) {
    player1 = p1;
    player2 = p2;
 }

void TerminalBoard::printBoard(Board *b) {
    auto board = b->getGameBoard();

    if(printCount != 0) {
        // add to history bank
    }

    for(int i = 1; i <= 8; i++) {
        std::cout << "| ";
        for(int j = 1; j <= 8; j++) {
            if     (j % 2 == 0 && i % 2 != 0) std::cout << "█ "; // double if you want Square, won't look good with chess pieces though
            else if(j % 2 != 0 && i % 2 == 0) std::cout << " █";
        }
        if(i == 1) printf("|\tPlayer1: %s\n", player1);
        else if(i == 2) printf("|\tPlayer2: %s\n", player2);
        else std::cout << " |\n";
    }
    printCount++;
}

/**
 * @brief 
 * 
 * @param board 
 */
void TerminalBoard::updatePieces(Board* board) {
    std::cout << "\tTom: ";
    // for(int i = 0; i < board->getAllbPieces().size(); i++) {
    //     std::cout << board->getAllbPieces().at(i) << " ";
    // }
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