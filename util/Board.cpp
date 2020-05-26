#include "headers/Board.h"

#define MAX_SIZE 8
#define WHITE_COLOR 0
#define BLACK_COLOR 1

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

   auto foundKey = gameBoard.find(sq);

   if (foundKey != gameBoard.end())
   {
       return true;
   }

    return false;
}

/**
 * @brief returns pointer to ChessPiece
 * 
 * @param sq square to look at
 * @return ChessPiece* this
 */
ChessPiece* Board::getChessPiece(Square* sq) {
    if(isOccupied(*sq)) {
        std::map<Square, ChessPiece>::iterator it = gameBoard.find(*sq);
        return &it->second;
    }

    
    
    return nullptr;
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

bool Board::isPathClear(Square* from, Square* to)
{
    int from_r = from->getRow();
    int from_c = from->getColumn();

    int to_r = to->getRow();
    int to_c = to->getColumn();

    int rIncrementor = (from_r == to_r) ? 0 : ((to_r > from_r) ? 1 : -1);
    int cIncrementor =(from_c == to_c) ? 0 : ((to_c > from_c) ? 1 : -1); 

    int r = from_r + rIncrementor;
    int c = from_c + cIncrementor;

    Square* s = Square::makeSquare(r, c);

    bool result = true;

    while (result && !(s == to))
    {
        result = result && getChessPiece(Square::makeSquare(r, c)) == NULL;
        r += rIncrementor;
        c += cIncrementor;

        s = Square::makeSquare(r, c);
    }

    return result;
}
/**
 * @brief initialize map of <Square, ChessPiece*>
 * 
 */
void Board::initBoard() {
    ChessPieceFactory* factory = new ChessPieceFactory();  

    gameBoard.emplace(Square(1, 1), *factory->makePiece(new ChessPieceDescriptor(WHITE, ROOK)));    
    gameBoard.emplace(Square(1, 2), *factory->makePiece(new ChessPieceDescriptor(WHITE, KNIGHT)));
    gameBoard.emplace(Square(1, 3), *factory->makePiece(new ChessPieceDescriptor(WHITE, BISHOP)));
    gameBoard.emplace(Square(1, 4), *factory->makePiece(new ChessPieceDescriptor(WHITE, QUEEN)));
    gameBoard.emplace(Square(1, 5), *factory->makePiece(new ChessPieceDescriptor(WHITE, KING)));
    gameBoard.emplace(Square(1, 6), *factory->makePiece(new ChessPieceDescriptor(WHITE, BISHOP)));
    gameBoard.emplace(Square(1, 7), *factory->makePiece(new ChessPieceDescriptor(WHITE, KNIGHT)));
    gameBoard.emplace(Square(1, 8), *factory->makePiece(new ChessPieceDescriptor(WHITE, ROOK)));

    for (int col = 1; col <= MAX_SIZE; col++) 
    {
        gameBoard.emplace(Square(2, col), *factory->makePiece(new ChessPieceDescriptor(WHITE, PAWN)));
    }

    gameBoard.emplace(Square(8, 1), *factory->makePiece(new ChessPieceDescriptor(BLACK, ROOK)));
    gameBoard.emplace(Square(8, 2), *factory->makePiece(new ChessPieceDescriptor(BLACK, KNIGHT)));
    gameBoard.emplace(Square(8, 3), *factory->makePiece(new ChessPieceDescriptor(BLACK, BISHOP)));
    gameBoard.emplace(Square(8, 4), *factory->makePiece(new ChessPieceDescriptor(BLACK, QUEEN)));
    gameBoard.emplace(Square(8, 5), *factory->makePiece(new ChessPieceDescriptor(BLACK, KING)));
    gameBoard.emplace(Square(8, 6), *factory->makePiece(new ChessPieceDescriptor(BLACK, BISHOP)));
    gameBoard.emplace(Square(8, 7), *factory->makePiece(new ChessPieceDescriptor(BLACK, KNIGHT)));
    gameBoard.emplace(Square(8, 8), *factory->makePiece(new ChessPieceDescriptor(BLACK, ROOK)));

    for (int col = 1; col <= MAX_SIZE; col++)
    {
        gameBoard.emplace(Square(7, col), *factory->makePiece(new ChessPieceDescriptor(BLACK, PAWN)));
    }
    
    //std::cout << gameBoard.size() << std::endl;

}

void Board::populateVect() {
    std::map<Square, ChessPiece>::iterator it = gameBoard.begin();
    while(it != gameBoard.end()) {
        ChessPiece* p = &it->second;
        
        if(p->getPieceColor() == WHITE_COLOR) wPieces.push_back(it->first);
        else                            bPieces.push_back(it->first);
        it++;
    }
}

/*
* needs testing for the new find implementation
*/
void Board::movePiece(int r, int c, Square* sq) {
   auto foundKey = gameBoard.find(*sq);
   Square p = foundKey->first;
   ChessPiece piece = foundKey->second;
   
   removePiece(*sq, static_cast<Color>(piece.getPieceColor()));

   p.setPosition(r, c);
   gameBoard.emplace(p, piece);
}

Board::~Board() {}