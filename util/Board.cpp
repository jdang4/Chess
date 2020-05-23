#include "headers/Board.h"

/**
 *  - Compare if something exists on Hashmap
 *  - check what piece is on the square
 *  - Remove piece
 *  - check boundaries with square - is it valid?
 *  - Populate with proper starting coordinates of each unit  
 */

/**
 *   * Game Board *
 * 8
 * 7
 * 6
 * 5
 * 4
 * 3
 * 2
 * 1
 *  a b c d e f g h
 */

/**
 * @brief Construct a new Board:: Board object
 * 
 */
Board::Board() {
    // for(int r = 0; r < MAX_ROWS; r++) chessBoard[r] = new Square(0,0);
    initBoard();
    populateVect();
}

/**
 * @brief check to see if a square on the board is occupied
 * 
 * @param sq square to check
 * @return true if square is occupied
 * @return false if not occoupied
 */
bool Board::isOccupied(Square *sq) {
    if(gameBoard.find(sq) == gameBoard.end()) return false;
    else return true;
}

/**
 * @brief returns pointer to ChessPiece
 * 
 * @param sq square to look at
 * @return ChessPiece* this
 */
ChessPiece* Board::getChessPiece(Square *sq) {
    if(isOccupied(sq)) return gameBoard.at(sq);
    else return nullptr;
}

/**
 * @brief remove chess piece from map
 * 
 * @param sq Key - square containing possible piece
 */
void Board::removePiece(Square *sq) {
    if(gameBoard.find(sq) != gameBoard.end()) gameBoard.erase(sq);
}

/**
 * @brief Hashmap of <Square, Piece>
 * 
 */
void Board::initBoard() {
    ChessPieceFactory* factory = new ChessPieceFactory();  

    gameBoard.insert(std::make_pair(new Square(1, 'A'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::ROOK))));
    gameBoard.insert(std::make_pair(new Square(1, 'B'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::KNIGHT))));
    gameBoard.insert(std::make_pair(new Square(1, 'C'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::BISHOP))));
    gameBoard.insert(std::make_pair(new Square(1, 'D'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::QUEEN))));
    gameBoard.insert(std::make_pair(new Square(1, 'E'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::KING))));
    gameBoard.insert(std::make_pair(new Square(1, 'F'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::BISHOP))));
    gameBoard.insert(std::make_pair(new Square(1, 'G'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::KNIGHT))));
    gameBoard.insert(std::make_pair(new Square(1, 'H'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::ROOK))));

    gameBoard.insert(std::make_pair(new Square(2, 'A'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(2, 'B'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(2, 'C'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(2, 'D'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(2, 'E'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(2, 'F'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(2, 'G'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(2, 'H'), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN))));

    gameBoard.insert(std::make_pair(new Square(8, 'A'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::ROOK))));
    gameBoard.insert(std::make_pair(new Square(8, 'B'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::KNIGHT))));
    gameBoard.insert(std::make_pair(new Square(8, 'C'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::BISHOP))));
    gameBoard.insert(std::make_pair(new Square(8, 'D'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::QUEEN))));
    gameBoard.insert(std::make_pair(new Square(8, 'E'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::KING))));
    gameBoard.insert(std::make_pair(new Square(8, 'F'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::BISHOP))));
    gameBoard.insert(std::make_pair(new Square(8, 'G'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::KNIGHT))));
    gameBoard.insert(std::make_pair(new Square(8, 'H'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::ROOK))));

    gameBoard.insert(std::make_pair(new Square(7, 'A'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(7, 'B'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(7, 'C'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(7, 'D'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(7, 'E'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(7, 'F'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(7, 'G'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));
    gameBoard.insert(std::make_pair(new Square(7, 'H'), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN))));

}

void Board::populateVect() {
    std::unordered_map<Square*, ChessPiece*>::iterator it = gameBoard.begin();
    while(it != gameBoard.end()) {
        ChessPiece* p = it->second;
        if(p->getPieceColor() == "WHITE") wPieces.push_back(it->first);
        else                              bPieces.push_back(it->first);
        it++;
    }
}

Board::~Board() {}