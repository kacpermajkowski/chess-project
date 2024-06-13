
#include <boost/test/unit_test.hpp>
#include "model/UnitDir/Rook.h"
#include "model/State.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Knight.h"

using namespace std;

struct TestSuiteRookFixture {

    BoardPtr board = make_shared<Board>(vector<FieldPtr>());
    StatePtr state = make_shared<State>(board);

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRook, TestSuiteRookFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorRook){
        UnitPtr whiteRook = make_shared<Rook>(WHITE);
        BOOST_TEST(whiteRook->getColor() == WHITE);
        UnitPtr blackRook = make_shared<Rook>(BLACK);
        BOOST_TEST(blackRook->getColor() == BLACK);
    }

    BOOST_AUTO_TEST_CASE(TestLegalMovesRook){
        UnitPtr whiteRook = make_shared<Rook>(WHITE);
        UnitPtr whiteQueen = make_shared<Queen>(WHITE);
        UnitPtr blackKnight = make_shared<Knight>(BLACK);

        FieldPtr whiteRookField = state->getBoard()->getField(make_shared<Position>(D, _4));
        FieldPtr whiteQueenField = state->getBoard()->getField(make_shared<Position>(D, _6));
        FieldPtr blackKnightField = state->getBoard()->getField(make_shared<Position>(G, _4));

        BOOST_REQUIRE(whiteRookField != nullptr);
        BOOST_REQUIRE(whiteQueenField != nullptr);
        BOOST_REQUIRE(blackKnightField != nullptr);
        whiteRookField->setUnit(whiteRook);
        whiteQueenField->setUnit(whiteQueen);
        blackKnightField->setUnit(blackKnight);

        vector<MovePtr> moves = whiteRook->getLegalMoves(state);
        list<PositionPtr> positons {
            std::make_shared<Position>(D, _5),
            std::make_shared<Position>(D, _3),
            std::make_shared<Position>(D, _2),
            std::make_shared<Position>(D, _1),
            std::make_shared<Position>(A, _4),
            std::make_shared<Position>(B, _4),
            std::make_shared<Position>(C, _4),
            std::make_shared<Position>(E, _4),
            std::make_shared<Position>(F, _4),
            std::make_shared<Position>(G, _4),
        };

        BOOST_TEST(positons.size() == moves.size());
        for(PositionPtr p: positons){
            bool hasCorrespondingMove = false;
            for(MovePtr m : moves){
                BOOST_TEST(m->getCurrentField() == whiteRookField);
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
