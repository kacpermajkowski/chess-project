
#include <boost/test/unit_test.hpp>
#include "model/unit/Bishop.h"
#include "model/State.h"
#include "model/unit/Queen.h"
#include "model/unit/Knight.h"

using namespace std;

struct TestSuiteBishopFixture {

    BoardPtr board = make_shared<Board>(vector<FieldPtr>{
            make_shared<Field>(make_shared<Position>(D, _4), make_shared<Bishop>(WHITE)),
            make_shared<Field>(make_shared<Position>(D, _6), make_shared<Queen>(WHITE)),
            make_shared<Field>(make_shared<Position>(G, _4), make_shared<Knight>(BLACK)),
            make_shared<Field>(make_shared<Position>(C, _5), make_shared<Queen>(BLACK)),
            make_shared<Field>(make_shared<Position>(A, _8), make_shared<King>(BLACK)),
            make_shared<Field>(make_shared<Position>(A, _1), make_shared<King>(WHITE)),
    });

    StatePtr state = make_shared<State>(board);

    FieldPtr whiteBishopField = state->getBoard()->getField(make_shared<Position>(D, _4));
    FieldPtr whiteQueenField = state->getBoard()->getField(make_shared<Position>(D, _6));
    FieldPtr blackKnightField = state->getBoard()->getField(make_shared<Position>(G, _4));

    UnitPtr whiteBishop = whiteBishopField->getUnit();
    UnitPtr whiteQueen = whiteQueenField->getUnit();
    UnitPtr blackKnight = blackKnightField->getUnit();
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBishop, TestSuiteBishopFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorAndGetterBishop){
        BOOST_TEST(whiteBishop->getColor() == WHITE);
        BOOST_TEST(blackKnight->getColor() == BLACK);
    }

    BOOST_AUTO_TEST_CASE(TestGetPossibleMovesBishop){
        list<MoveVectorPtr> expectedVectors {
                make_shared<MoveVector>(1,1),
                make_shared<MoveVector>(2,2),
                make_shared<MoveVector>(3,3),
                make_shared<MoveVector>(4,4),
                make_shared<MoveVector>(5,5),
                make_shared<MoveVector>(6,6),
                make_shared<MoveVector>(7,7),
                make_shared<MoveVector>(-1,-1),
                make_shared<MoveVector>(-2,-2),
                make_shared<MoveVector>(-3,-3),
                make_shared<MoveVector>(-4,-4),
                make_shared<MoveVector>(-5,-5),
                make_shared<MoveVector>(-6,-6),
                make_shared<MoveVector>(-7,-7),

                make_shared<MoveVector>(1,-1),
                make_shared<MoveVector>(2,-2),
                make_shared<MoveVector>(3,-3),
                make_shared<MoveVector>(4,-4),
                make_shared<MoveVector>(5,-5),
                make_shared<MoveVector>(6,-6),
                make_shared<MoveVector>(7,-7),
                make_shared<MoveVector>(-1,1),
                make_shared<MoveVector>(-2,2),
                make_shared<MoveVector>(-3,3),
                make_shared<MoveVector>(-4,4),
                make_shared<MoveVector>(-5,5),
                make_shared<MoveVector>(-6,6),
                make_shared<MoveVector>(-7,7),
        };

        auto possibleMoves = whiteBishop->getBranchesOfPossibleMoveVectors();
        int possibleMovesCummulativeSize = 0;
        for(const auto& branch : possibleMoves){
            possibleMovesCummulativeSize +=  branch.size();
        }
        BOOST_TEST(possibleMovesCummulativeSize == expectedVectors.size());
        for(auto possibleVector : expectedVectors){
            bool contains = false;
            for(const auto& branch : possibleMoves){
                for(auto moveVector : branch){
                    if(moveVector->getColumnOffset() == possibleVector->getColumnOffset() && moveVector->getRowOffset() == possibleVector->getRowOffset()){
                        contains = true;
                        break;
                    }
                }
                if(contains) break;
            }
            BOOST_TEST(contains);
        }
    }

    BOOST_AUTO_TEST_CASE(TestLegalMovesNoCheckBishop){
        vector<MovePtr> moves = whiteBishop->getLegalMoves(state);
        list<PositionPtr> positons {
                std::make_shared<Position>(C, _5),
                std::make_shared<Position>(C, _3),
                std::make_shared<Position>(B, _2),
                std::make_shared<Position>(E, _5),
                std::make_shared<Position>(F, _6),
                std::make_shared<Position>(G, _7),
                std::make_shared<Position>(H, _8),
                std::make_shared<Position>(E, _3),
                std::make_shared<Position>(F, _2),
                std::make_shared<Position>(G, _1),
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
            cout << p->getLetterIndex() << " " << p->getNumberIndex() << endl;
            BOOST_TEST(hasCorrespondingMove);
        }

    }

BOOST_AUTO_TEST_SUITE_END()
