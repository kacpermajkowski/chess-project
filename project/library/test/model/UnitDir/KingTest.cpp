//
// Created by user on 15.06.2024.
//

#include <boost/test/unit_test.hpp>
#include "model/UnitDir/Rook.h"
#include "model/State.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Knight.h"
#include "model/UnitDir/Pawn.h"

using namespace std;

struct TestSuiteKingFixture {

    BoardPtr board = make_shared<Board>(vector<FieldPtr>{
            make_shared<Field>(make_shared<Position>(D, _4), make_shared<Rook>(WHITE)),
            make_shared<Field>(make_shared<Position>(D, _6), make_shared<Queen>(WHITE)),
            make_shared<Field>(make_shared<Position>(G, _4), make_shared<Knight>(BLACK)),
            make_shared<Field>(make_shared<Position>(A, _8), make_shared<King>(WHITE)),
            make_shared<Field>(make_shared<Position>(A, _1), make_shared<King>(BLACK)),
            make_shared<Field>(make_shared<Position>(B, _7), make_shared<Pawn>(WHITE)),
    });

    StatePtr state = make_shared<State>(board);

    FieldPtr whiteKingField = state->getBoard()->getField(make_shared<Position>(A, _8));
    FieldPtr whiteRookField = state->getBoard()->getField(make_shared<Position>(D, _4));
    FieldPtr whiteQueenField = state->getBoard()->getField(make_shared<Position>(D, _6));
    FieldPtr blackKnightField = state->getBoard()->getField(make_shared<Position>(G, _4));

    UnitPtr whiteKing = whiteKingField->getUnit();
    UnitPtr whiteRook = whiteRookField->getUnit();
    UnitPtr whiteQueen = whiteQueenField->getUnit();
    UnitPtr blackKnight = blackKnightField->getUnit();
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteKing, TestSuiteKingFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorAndGetterKing){
        BOOST_TEST(whiteKing->getColor() == WHITE);
    }

    BOOST_AUTO_TEST_CASE(TestGetPossibleMovesKing){
        list<MoveVectorPtr> expectedVectors {
                make_shared<MoveVector>(0,1),
                make_shared<MoveVector>(1,1),
                make_shared<MoveVector>(-1,1),
                make_shared<MoveVector>(1,0),
                make_shared<MoveVector>(-1,0),
                make_shared<MoveVector>(1,-1),
                make_shared<MoveVector>(-1,-1),
                make_shared<MoveVector>(0,-1),
        };

        auto possibleMoves = whiteKing->getPossibleMoves();
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

    BOOST_AUTO_TEST_CASE(TestLegalMovesNoCheckKing){
        vector<MovePtr> moves = whiteKing->getLegalMoves(state);
        list<PositionPtr> positons {
                std::make_shared<Position>(A, _7),
                std::make_shared<Position>(B, _8),
        };

        BOOST_TEST(positons.size() == moves.size());
        for(PositionPtr p: positons){
            bool hasCorrespondingMove = false;
            for(MovePtr m : moves){
                BOOST_TEST(m->getCurrentField() == whiteKingField);
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
