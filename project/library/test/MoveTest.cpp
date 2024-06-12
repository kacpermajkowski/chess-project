#include <boost/test/unit_test.hpp>
#include "model/move/Move.h"
#include "model/UnitDir/Queen.h"

// tests for Move.cpp and Action.cpp

struct TestSuiteMoveFixture {

    UnitPtr unit = new Queen(WHITE);
    PositionPtr currentPosition = new Position(A, _5);
    PositionPtr targetPosition = new Position(A, _6);

    FieldPtr currentField = new Field(currentPosition, unit);
    FieldPtr targetField = new Field(targetPosition, nullptr);

    ActionPtr action_capture = new Action(CAPTURE, targetField);

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMove, TestSuiteMoveFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorMove){
        Move move(unit, currentField, targetField);
        BOOST_TEST(move.getCurrentField() == currentField);
        BOOST_TEST(move.getTargetField() == targetField);
        BOOST_TEST(move.getMovedUnit() == unit);
        BOOST_TEST(move.getAction() == nullptr);
    }

    BOOST_AUTO_TEST_CASE(TestActionSetterMove){
        Move move(unit, currentField, targetField);
        BOOST_TEST(move.getAction() == nullptr);

        move.setAction(action_capture);

        BOOST_TEST(move.getAction() == action_capture);
    }

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(TestSuiteAction, TestSuiteMoveFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorAction){
        Action action(CAPTURE, targetField);
        BOOST_TEST(action.getActionField() == targetField);
        BOOST_TEST(action.getType() == CAPTURE);
    }


BOOST_AUTO_TEST_SUITE_END()