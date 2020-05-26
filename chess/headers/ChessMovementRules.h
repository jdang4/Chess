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

    static int getColor(Square* coord, Board* board);

    static bool notSameCoordinate(Square* from, Square* to, Board* board);
    static bool isOrthogonal(Square* from, Square* to, Board* board);
    static bool isDiagonal(Square* from, Square* to, Board* board);
    static bool isAdjacent(Square* from, Square* to, Board* board);
    static bool isLinear(Square* from, Square* to, Board* board);
    static bool isValidTarget(Square* from, Square* to, Board* board);
    static bool isClearPath(Square* from, Square* to, Board* board);

    // pawns check
    static bool hasPawnMoved(Square* from, Square* to, Board* board);
    /*
    static bool isPawnOneForward(Square* from, Square* to, Board* board);
    static bool isPawnTwoForward(Square* from, Square* to, Board* board);
    static bool isPawnOneDiagonal(Square* from, Square* to, Board* board);
    static bool isCaptureOpponent(Square* from, Square* to, Board* board);
    static bool canPawnMove(Square* from, Square* to, Board* board);

    // knight check
    static bool canKnightMove(Square* from, Square* to, Board* board);

    // king check
    static bool canKingMove(Square* from, Square* to, Board* board);
    */
    /*
    // castling check
    static bool isPossibleCastlingMove(Square* from, Square* to, Board* board);
    static bool canCastle(Square* from, Square* to, Board* board);
    static bool castlingCheck(Square* from, Square* to, Board* board);
    */
    
};

#endif