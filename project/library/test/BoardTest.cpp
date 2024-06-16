#include <boost/test/unit_test.hpp>
#include "model/Board.h"
#include "model/unit/Rook.h"
#include "model/unit/Knight.h"
#include "model/unit/Pawn.h"
#include "model/unit/Bishop.h"
#include "model/unit/King.h"
#include "model/unit/Queen.h"
#include <type_traits>

//test for getField()
using namespace std;

struct TestSuiteBoardFixture{

    BoardPtr emptyBoard = make_shared<Board>(vector<FieldPtr>());
    FieldPtr testField = make_shared<Field>(make_shared<Position>(H, _7), make_shared<Pawn>(WHITE));
    BoardPtr boardWithOneUnit = make_shared<Board>(vector<FieldPtr>{ testField });

    std::map<PositionPtr, UnitPtr> defaults {
            {std::make_shared<Position>(A, _1), std::make_shared<Rook>(WHITE)},
            {std::make_shared<Position>(B, _1), std::make_shared<Knight>(WHITE)},
            {std::make_shared<Position>(C, _1), std::make_shared<Bishop>(WHITE)},
            {std::make_shared<Position>(D, _1), std::make_shared<Queen>(WHITE)},
            {std::make_shared<Position>(E, _1), std::make_shared<King>(WHITE)},
            {std::make_shared<Position>(F, _1), std::make_shared<Bishop>(WHITE)},
            {std::make_shared<Position>(G, _1), std::make_shared<Knight>(WHITE)},
            {std::make_shared<Position>(H, _1), std::make_shared<Rook>(WHITE)},

            {std::make_shared<Position>(A, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(B, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(C, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(D, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(E, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(F, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(G, _2), std::make_shared<Pawn>(WHITE)},
            {std::make_shared<Position>(H, _2), std::make_shared<Pawn>(WHITE)},

            {std::make_shared<Position>(A, _8), std::make_shared<Rook>(BLACK)},
            {std::make_shared<Position>(B, _8), std::make_shared<Knight>(BLACK)},
            {std::make_shared<Position>(C, _8), std::make_shared<Bishop>(BLACK)},
            {std::make_shared<Position>(D, _8), std::make_shared<Queen>(BLACK)},
            {std::make_shared<Position>(E, _8), std::make_shared<King>(BLACK)},
            {std::make_shared<Position>(F, _8), std::make_shared<Bishop>(BLACK)},
            {std::make_shared<Position>(G, _8), std::make_shared<Knight>(BLACK)},
            {std::make_shared<Position>(H, _8), std::make_shared<Rook>(BLACK)},

            {std::make_shared<Position>(A, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(B, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(C, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(D, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(E, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(F, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(G, _7), std::make_shared<Pawn>(BLACK)},
            {std::make_shared<Position>(H, _7), std::make_shared<Pawn>(BLACK)},
    };

};

bool checkAllFieldsInitialized(BoardPtr board){
    bool initialized = true;
    for(int i = 0; i<= 7; i++){
        for(int j = 0; j <= 7; j++){
            if(board->getField(make_shared<Position>(LetterIndex(i), NumberIndex(i))) == nullptr){
                initialized = false;
                break;
            }
        }
        if(!initialized) break;
    }
    return initialized;
}

bool checkContainsNoUnits(BoardPtr board){
    return board->getUnits().empty();
}

BOOST_AUTO_TEST_SUITE(TestSuiteBoard)

    BOOST_FIXTURE_TEST_CASE(TestConstructorsFieldsInitialized, TestSuiteBoardFixture){
        BoardPtr board = make_shared<Board>();
        BOOST_TEST(board->getFields().size() == 64);
        BOOST_TEST(checkAllFieldsInitialized(board));

        BOOST_TEST(emptyBoard->getFields().size() == 64);
        BOOST_TEST(checkAllFieldsInitialized(emptyBoard));

        BOOST_TEST(boardWithOneUnit->getFields().size() == 64);
        BOOST_TEST(checkAllFieldsInitialized(boardWithOneUnit));

        //TODO: make it throw exception when there are two fields with the same position and test that throw
    }

    BOOST_FIXTURE_TEST_CASE(TestGetField, TestSuiteBoardFixture){
        BOOST_TEST(boardWithOneUnit->getField(testField->getPosition()) == testField);
    }

    BOOST_FIXTURE_TEST_CASE(TestGetUnits, TestSuiteBoardFixture){
        BOOST_REQUIRE(!boardWithOneUnit->getUnits().empty());
        BOOST_TEST(boardWithOneUnit->getUnits()[0] == testField->getUnit());
    }

    BOOST_FIXTURE_TEST_CASE(TestGetKing, TestSuiteBoardFixture){
        BoardPtr board = make_shared<Board>();
        BOOST_TEST(board->getKingField(WHITE)->getPosition()->equals(make_shared<Position>(E, _1)));
        BOOST_TEST(board->getKingField(BLACK)->getPosition()->equals(make_shared<Position>(E, _8)));
    }

    BOOST_FIXTURE_TEST_CASE(TestConstructorsPiecesInitialized, TestSuiteBoardFixture){
        BoardPtr board = make_shared<Board>();
        for(const auto& kv : defaults){
            FieldPtr field = board->getField(kv.first);
            UnitPtr unit = field->getUnit();

            BOOST_TEST(unit->getColor() == kv.second->getColor());
            //TODO: solve with is_same
//            BOOST_TEST(false/*areSameType(unit, kv.second)*/);
        }

        BOOST_TEST(checkContainsNoUnits(emptyBoard));

        BOOST_REQUIRE(!boardWithOneUnit->getUnits().empty());
        BOOST_TEST(boardWithOneUnit->getUnits()[0] == testField->getUnit());
    }



BOOST_AUTO_TEST_SUITE_END()