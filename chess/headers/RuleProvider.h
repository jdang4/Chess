#ifndef RULEPROVIDER_H
#define RULEPROVIDER_H

#include <map>
#include <functional>
#include "../headers/ChessMovementRules.h"
#include "../../../Chess/util/headers/Board.h"
#include "../../../Chess/util/headers/Square.h"

class Square;
class Board;
class ChessMovementRules;

class RuleProvider {

    public: 
        RuleProvider();
        ~RuleProvider();
        void test(Square* from, Square* to, Board* b);
        std::map<int, std::function<bool(Square*, Square*, Board*)>> getMoveRules();

    private:
        std::map<int, std::function<bool(Square*, Square*, Board*)>> rules;
        void init();

};

#endif