#ifndef CHESSMOVEMENTRULES_H
#define CHESSMOVEMENTRULES_H

#include <cstdlib>
#include "../../../Chess/util/headers/Board.h"
#include "../../../Chess/util/headers/Square.h"

class Square;
class Board;

class ChessMovementRules 
{
    public:

    ChessMovementRules();
    virtual ~ChessMovementRules();

    static int getColor(Square* coord, Board* b);

    static bool notSameCoordinate(Square* from, Square* to, Board* b);
    static bool isOrthogonal(Square* from, Square* to, Board* b);
    static bool isDiagonal(Square* from, Square* to, Board* b);
    static bool isAdjacent(Square* from, Square* to, Board* b);
    static bool isLinear(Square* from, Square* to, Board* b);
    static bool isValidTarget(Square* from, Square* to, Board* b);
    static bool isClearPath(Square* from, Square* to, Board* b);
    static bool canCaptureOpponent(Square* from, Square* to, Board* b);

    // pawns check
    static bool hasPawnMoved(Square* from, Square* to, Board* b);  
    static bool isPawnOneForward(Square* from, Square* to, Board* b);
    static bool isPawnTwoForward(Square* from, Square* to, Board* b);
    static bool isPawnOneDiagonal(Square* from, Square* to, Board* b);
    static bool canPawnMove(Square* from, Square* to, Board* b);
    
    
    // knight check
    static bool canKnightMove(Square* from, Square* to, Board* b);
    
    // king check
    static bool canKingMove(Square* from, Square* to, Board* b);
    
    /*
    // castling check
    static bool isPossibleCastlingMove(Square* from, Square* to, Board* b);
    static bool canCastle(Square* from, Square* to, Board* b);
    static bool castlingCheck(Square* from, Square* to, Board* b);
    */
    
};

#endif