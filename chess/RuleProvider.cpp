#include "headers/RuleProvider.h"


using namespace std;
using placeholders::_1;

RuleProvider::RuleProvider()
{
    init();
}

RuleProvider::~RuleProvider() {}

const auto kingRules = [](Square* from, Square* to, Board* b) 
{
    return ChessMovementRules::canCaptureOpponent(from, to, b) && ChessMovementRules::canKingMove(from, to, b);
};

const auto queenRules = [](Square* from, Square* to, Board* b) 
{
    return (
        ChessMovementRules::isLinear(from, to, b) &&
        ChessMovementRules::canCaptureOpponent(from, to, b) &&
        ChessMovementRules::isClearPath(from, to, b)
    );
};

const auto rookRules = [](Square* from, Square* to, Board* b)
{
    return (
        ChessMovementRules::isOrthogonal(from, to, b) &&
        ChessMovementRules::canCaptureOpponent(from, to, b) &&
        ChessMovementRules::isClearPath(from, to, b)
    );
};

const auto bishopRules = [](Square* from, Square* to, Board* b)
{
    return (
        ChessMovementRules::isDiagonal(from, to, b) &&
        ChessMovementRules::canCaptureOpponent(from, to, b) &&
        ChessMovementRules::isClearPath(from, to, b)
    );
};

const auto knightRules = [](Square* from, Square* to, Board* b)
{
    return (
        ChessMovementRules::canCaptureOpponent(from, to, b) &&
        ChessMovementRules::canKnightMove(from, to, b)
    );
};

const auto pawnRules = [](Square* from, Square* to, Board* b)
{
    return (
        ChessMovementRules::canPawnMove(from, to, b)
    );
};

void RuleProvider::init()
{
    rules.emplace(0, pawnRules);
    rules.emplace(1, rookRules);
    rules.emplace(2, knightRules);
    rules.emplace(3, bishopRules);
    rules.emplace(4, queenRules);
    rules.emplace(5, kingRules);
}

std::map<int, std::function<bool(Square*, Square*, Board*)>> RuleProvider::getMoveRules()
{
    return rules;
}

