#include "headers/Board.h"

/**
 *  - Compare if something exists on Hashmap
 *  - check what piece is on the square
 *  - Remove piece
 *  - check boundaries with square - is it valid?
 *  - Populate with proper starting coordinates of each unit  
 * TODO: refactor with comparator
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

// /**
//  * @brief check to see if a square on the board is occupied
//  * 
//  * @param sq square to check
//  * @return true if square is occupied
//  * @return false if not occoupied
//  */
bool Board::isOccupied(Square sq) {
    if(gameBoard.size() == 0) return false;

    std::map<Square, ChessPiece*>::iterator it = gameBoard.begin();
    while(it != gameBoard.end()) {
        if(sq == it->first) return true;
        it++;
    }
    return false;
}

/**
 * @brief returns pointer to ChessPiece
 * 
 * @param sq square to look at
 * @return ChessPiece* this
 */
ChessPiece* Board::getChessPiece(Square sq) {
    if(isOccupied(sq)) return gameBoard.at(sq);
    else return nullptr;
}

/**
 * @brief remove chess piece from map
 * 
 * @param sq Key - square containing possible piece
 */
void Board::removePiece(Square sq, Color color) {
    if(gameBoard.find(sq) != gameBoard.end()) {
        gameBoard.erase(sq);
        if(color == WHITE) {
            wPieces.erase(std::find(wPieces.begin(), wPieces.end(), sq));
        }
        else bPieces.erase(std::find(bPieces.begin(), bPieces.end(), sq));
    }
}

/**
 * @brief initialize map of <Square, ChessPiece*>
 * 
 */
void Board::initBoard() {
    ChessPieceFactory* factory = new ChessPieceFactory();  

    gameBoard.emplace(Square(1, 1), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::ROOK)));
    gameBoard.emplace(Square(1, 2), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::KNIGHT)));
    gameBoard.emplace(Square(1, 3), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::BISHOP)));
    gameBoard.emplace(Square(1, 4), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::QUEEN)));
    gameBoard.emplace(Square(1, 5), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::KING)));
    gameBoard.emplace(Square(1, 6), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::BISHOP)));
    gameBoard.emplace(Square(1, 7), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::KNIGHT)));
    gameBoard.emplace(Square(1, 8), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::ROOK)));

    for (int col = 1; col < MAX_COLUMNS + 1; col++)
    {
        gameBoard.emplace(Square(2, col), factory->makePiece(new ChessPieceDescriptor(Color::WHITE, Name::PAWN)));
    }

    gameBoard.emplace(Square(8, 1), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::ROOK)));
    gameBoard.emplace(Square(8, 2), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::KNIGHT)));
    gameBoard.emplace(Square(8, 3), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::BISHOP)));
    gameBoard.emplace(Square(8, 4), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::QUEEN)));
    gameBoard.emplace(Square(8, 5), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::KING)));
    gameBoard.emplace(Square(8, 6), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::BISHOP)));
    gameBoard.emplace(Square(8, 7), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::KNIGHT)));
    gameBoard.emplace(Square(8, 8), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::ROOK)));

    for (int col = 1; col < MAX_COLUMNS + 1; col++)
    {
        gameBoard.emplace(Square(7, col), factory->makePiece(new ChessPieceDescriptor(Color::BLACK, Name::PAWN)));
    }
    std::cout << gameBoard.size() << std::endl;
}

void Board::populateVect() {
    std::map<Square, ChessPiece*>::iterator it = gameBoard.begin();
    while(it != gameBoard.end()) {
        ChessPiece* p = it->second;
        
        if(p->getPieceColor() == WHITE) wPieces.push_back(it->first);
        else                            bPieces.push_back(it->first);
        it++;
    }
}

void Board::updateKey(int r, int c, Square sq) {
    std::map<Square, ChessPiece*>::iterator it = gameBoard.begin();
    while(it != gameBoard.end()) {
        Square p = it->first;
        if(p == sq) p.setPosition(r, c);
        
        it++;
    }    
}

Board::~Board() {}