
#include <boost/test/unit_test.hpp>
#include "model/UnitDir/Rook.h"
#include "model/State.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Knight.h"

using namespace std;

struct TestSuiteRookFixture {

    BoardPtr board = make_shared<Board>(vector<FieldPtr>{
            make_shared<Field>(make_shared<Position>(D, _4), make_shared<Rook>(WHITE)),
            make_shared<Field>(make_shared<Position>(D, _6), make_shared<Queen>(WHITE)),
            make_shared<Field>(make_shared<Position>(G, _4), make_shared<Knight>(BLACK)),
            make_shared<Field>(make_shared<Position>(A, _8), make_shared<King>(WHITE)),
            make_shared<Field>(make_shared<Position>(A, _1), make_shared<King>(BLACK)),
    });

    StatePtr state = make_shared<State>(board);

    FieldPtr whiteRookField = state->getBoard()->getField(make_shared<Position>(D, _4));
    FieldPtr whiteQueenField = state->getBoard()->getField(make_shared<Position>(D, _6));
    FieldPtr blackKnightField = state->getBoard()->getField(make_shared<Position>(G, _4));

    UnitPtr whiteRook = whiteRookField->getUnit();
    UnitPtr whiteQueen = whiteQueenField->getUnit();
    UnitPtr blackKnight = blackKnightField->getUnit();
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRook, TestSuiteRookFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorAndGetterRook){
        BOOST_TEST(whiteRook->getColor() == WHITE);
        BOOST_TEST(blackKnight->getColor() == BLACK);
    }

    BOOST_AUTO_TEST_CASE(TestGetPossibleMovesRook){
        list<MoveVectorPtr> expectedVectors {
                make_shared<MoveVector>(0,1),
                make_shared<MoveVector>(0,2),
                make_shared<MoveVector>(0,3),
                make_shared<MoveVector>(0,4),
                make_shared<MoveVector>(0,5),
                make_shared<MoveVector>(0,6),
                make_shared<MoveVector>(0,7),
                make_shared<MoveVector>(0,-1),
                make_shared<MoveVector>(0,-2),
                make_shared<MoveVector>(0,-3),
                make_shared<MoveVector>(0,-4),
                make_shared<MoveVector>(0,-5),
                make_shared<MoveVector>(0,-6),
                make_shared<MoveVector>(0,-7),

                make_shared<MoveVector>(1,0),
                make_shared<MoveVector>(2,0),
                make_shared<MoveVector>(3,0),
                make_shared<MoveVector>(4,0),
                make_shared<MoveVector>(5,0),
                make_shared<MoveVector>(6,0),
                make_shared<MoveVector>(7,0),
                make_shared<MoveVector>(-1,0),
                make_shared<MoveVector>(-2,0),
                make_shared<MoveVector>(-3,0),
                make_shared<MoveVector>(-4,0),
                make_shared<MoveVector>(-5,0),
                make_shared<MoveVector>(-6,0),
                make_shared<MoveVector>(-7,0),
        };

        auto possibleMoves = whiteRook->getBranchesOfPossibleMoveVectors();
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

    BOOST_AUTO_TEST_CASE(TestLegalMovesNoCheckRook){
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
