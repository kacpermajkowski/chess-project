
#include <boost/test/unit_test.hpp>
#include "model/UnitDir/Pawn.h"
#include "model/State.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Knight.h"

using namespace std;

struct TestSuitePawnFixture {

    BoardPtr board = make_shared<Board>(vector<FieldPtr>());
    StatePtr state = make_shared<State>(board);

};

BOOST_FIXTURE_TEST_SUITE(TestSuitePawn, TestSuitePawnFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorPawn){
        UnitPtr whitePawn = make_shared<Pawn>(WHITE);
        BOOST_TEST(whitePawn->getColor() == WHITE);
        UnitPtr blackPawn = make_shared<Pawn>(BLACK);
        BOOST_TEST(blackPawn->getColor() == BLACK);
    }

    BOOST_AUTO_TEST_CASE(TestMoveForwardPawn){
        UnitPtr whitePawn = make_shared<Pawn>(WHITE);
        FieldPtr whitePawnField = state->getBoard()->getField(make_shared<Position>(D, _2));
        whitePawnField->setUnit(whitePawn);

        vector<MovePtr> moves = whitePawn->getLegalMoves(state);
        list<PositionPtr> positons {
                std::make_shared<Position>(D, _3),
                std::make_shared<Position>(D, _4),
        };

        BOOST_TEST(positons.size() == moves.size());
        for(PositionPtr p: positons){
            bool hasCorrespondingMove = false;
            for(MovePtr m : moves){
                BOOST_TEST(m->getCurrentField() == whitePawnField);
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

    BOOST_AUTO_TEST_CASE(TestRegularTakePawn){
        UnitPtr whitePawn = make_shared<Pawn>(WHITE);
        UnitPtr blackKnight1 = make_shared<Knight>(BLACK);
        UnitPtr blackKnight2 = make_shared<Knight>(BLACK);

        FieldPtr whitePawnField = state->getBoard()->getField(make_shared<Position>(D, _2));
        FieldPtr blackKnightField1 = state->getBoard()->getField(make_shared<Position>(C, _3));
        FieldPtr blackKnightField2 = state->getBoard()->getField(make_shared<Position>(D, _4));

        BOOST_REQUIRE(whitePawnField != nullptr);
        BOOST_REQUIRE(blackKnightField1 != nullptr);
        BOOST_REQUIRE(blackKnightField2 != nullptr);
        whitePawnField->setUnit(whitePawn);
        blackKnightField1->setUnit(blackKnight1);
        blackKnightField2->setUnit(blackKnight2);

        vector<MovePtr> moves = whitePawn->getLegalMoves(state);
        list<PositionPtr> positons {
                std::make_shared<Position>(D, _3),
                std::make_shared<Position>(C, _3),
        };

        BOOST_TEST(positons.size() == moves.size());
        for(const PositionPtr& p: positons){
            bool hasCorrespondingMove = false;
            for(const MovePtr& m : moves){
                BOOST_TEST(m->getCurrentField() == whitePawnField);
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
