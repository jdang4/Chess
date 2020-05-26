#include "headers/Board.h"

#define MAX_SIZE 8
#define WHITE_COLOR 0
#define BLACK_COLOR 1

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
    for(int i = 1; i <= MAX_SIZE; i++) {
        gameBoard.emplace(Square(2, i), *factory->makePiece(new ChessPieceDescriptor(WHITE, PAWN)));
        gameBoard.emplace(Square(7, i), *factory->makePiece(new ChessPieceDescriptor(BLACK, PAWN)));

        int nameEnum = i % 5;
        if(nameEnum == 1) nameEnum++;
        Name piece = static_cast<Name>(nameEnum);

        gameBoard.emplace(Square(1, i), *factory->makePiece(new ChessPieceDescriptor(WHITE, piece)));    
        gameBoard.emplace(Square(8, i), *factory->makePiece(new ChessPieceDescriptor(BLACK, piece)));
    }
    
    // std::cout << gameBoard.size() << std::endl;

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