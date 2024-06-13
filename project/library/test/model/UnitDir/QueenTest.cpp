
#include <boost/test/unit_test.hpp>
#include "model/UnitDir/Queen.h"
#include "model/State.h"
#include "model/UnitDir/Rook.h"
#include "model/UnitDir/Knight.h"

using namespace std;

struct TestSuiteQueenFixture {

    BoardPtr board = make_shared<Board>(vector<FieldPtr>());
    StatePtr state = make_shared<State>(board);

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteQueen, TestSuiteQueenFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorQueen){
        UnitPtr whiteQueen = make_shared<Queen>(WHITE);
        BOOST_TEST(whiteQueen->getColor() == WHITE);
        UnitPtr blackQueen = make_shared<Queen>(BLACK);
        BOOST_TEST(blackQueen->getColor() == BLACK);
    }

    BOOST_AUTO_TEST_CASE(TestLegalMovesQueen){
        UnitPtr whiteQueen = make_shared<Queen>(WHITE);
        UnitPtr whiteRook = make_shared<Rook>(WHITE);
        UnitPtr blackKnight1 = make_shared<Knight>(BLACK);
        UnitPtr blackKnight2 = make_shared<Knight>(BLACK);

        FieldPtr whiteQueenField = state->getBoard()->getField(make_shared<Position>(C, _7));
        FieldPtr whiteRookField = state->getBoard()->getField(make_shared<Position>(C, _6));
        FieldPtr blackKnightField1 = state->getBoard()->getField(make_shared<Position>(D, _6));
        FieldPtr blackKnightField2 = state->getBoard()->getField(make_shared<Position>(E, _7));

        BOOST_REQUIRE(whiteQueenField != nullptr);
        BOOST_REQUIRE(whiteRookField != nullptr);
        BOOST_REQUIRE(blackKnightField1 != nullptr);
        BOOST_REQUIRE(blackKnightField2 != nullptr);
        whiteQueenField->setUnit(whiteQueen);
        whiteRookField->setUnit(whiteRook);
        blackKnightField1->setUnit(blackKnight1);
        blackKnightField2->setUnit(blackKnight2);

        vector<MovePtr> moves = whiteQueen->getLegalMoves(state);
        list<PositionPtr> positons {
                std::make_shared<Position>(A, _7),
                std::make_shared<Position>(B, _7),
                std::make_shared<Position>(D, _7),
                std::make_shared<Position>(E, _7),
                std::make_shared<Position>(C, _8),

                std::make_shared<Position>(B, _8),
                std::make_shared<Position>(D, _6),

                std::make_shared<Position>(A, _5),
                std::make_shared<Position>(B, _6),
                std::make_shared<Position>(D, _7),
        };

        BOOST_TEST(positons.size() == moves.size());
        for(PositionPtr p: positons){
            bool hasCorrespondingMove = false;
            for(MovePtr m : moves){
                BOOST_TEST(m->getCurrentField() == whiteQueenField);
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
