
#include <boost/test/unit_test.hpp>
#include "model/UnitDir/Bishop.h"
#include "model/State.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Knight.h"

using namespace std;

struct TestSuiteBishopFixture {

    BoardPtr board = make_shared<Board>(vector<FieldPtr>());
    StatePtr state = make_shared<State>(board);

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBishop, TestSuiteBishopFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorBishop){
        UnitPtr whiteBishop = make_shared<Bishop>(WHITE);
        BOOST_TEST(whiteBishop->getColor() == WHITE);
        UnitPtr blackBishop = make_shared<Bishop>(BLACK);
        BOOST_TEST(blackBishop->getColor() == BLACK);
    }

    BOOST_AUTO_TEST_CASE(TestLegalMovesBishop){
        UnitPtr whiteBishop = make_shared<Bishop>(WHITE);
        UnitPtr whiteQueen = make_shared<Queen>(WHITE);
        UnitPtr blackKnight = make_shared<Knight>(BLACK);

        FieldPtr whiteBishopField = state->getBoard()->getField(make_shared<Position>(D, _4));
        FieldPtr whiteQueenField = state->getBoard()->getField(make_shared<Position>(B, _6));
        FieldPtr blackKnightField = state->getBoard()->getField(make_shared<Position>(G, _7));

        BOOST_REQUIRE(whiteBishopField != nullptr);
        BOOST_REQUIRE(whiteQueenField != nullptr);
        BOOST_REQUIRE(blackKnightField != nullptr);
        whiteBishopField->setUnit(whiteBishop);
        whiteQueenField->setUnit(whiteQueen);
        blackKnightField->setUnit(blackKnight);

        vector<MovePtr> moves = whiteBishop->getLegalMoves(state);
        list<PositionPtr> positons {
                std::make_shared<Position>(C, _5),
                std::make_shared<Position>(C, _3),
                std::make_shared<Position>(B, _2),
                std::make_shared<Position>(A, _1),
                std::make_shared<Position>(E, _3),
                std::make_shared<Position>(F, _2),
                std::make_shared<Position>(G, _1),
                std::make_shared<Position>(E, _5),
                std::make_shared<Position>(F, _6),
                std::make_shared<Position>(G, _7),
        };

        BOOST_TEST(positons.size() == moves.size());
        for(PositionPtr p: positons){
            bool hasCorrespondingMove = false;
            for(MovePtr m : moves){
                BOOST_TEST(m->getCurrentField() == whiteBishopField);
                PositionPtr target = m->getTargetField()->getPosition();
                if(target->getLetterIndex() == p->getLetterIndex()){
                    if(target->getNumberIndex() == p->getNumberIndex()){
                        hasCorrespondingMove = true;
                        break;
                    }
                }
            }

            BOOST_TEST(hasCorrespondingMove);
        }

    }



BOOST_AUTO_TEST_SUITE_END()
