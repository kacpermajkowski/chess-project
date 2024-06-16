#include <boost/test/unit_test.hpp>
#include "model/move/Move.h"
#include "model/unit/Queen.h"
#include "model/unit/Bishop.h"

struct TestSuiteMoveFixture {

    UnitPtr whiteQueen = std::make_shared<Queen>(WHITE);
    UnitPtr blackBishop = std::make_shared<Bishop>(BLACK);
    PositionPtr currentPosition = std::make_shared<Position>(A, _5);
    PositionPtr occupiedTargetPosition = std::make_shared<Position>(A, _6);
    PositionPtr emptyTargetPosition = std::make_shared<Position>(B, _6);

    FieldPtr currentField = std::make_shared<Field>(currentPosition, whiteQueen);
    FieldPtr occupiedTargetField = std::make_shared<Field>(occupiedTargetPosition, blackBishop);
    FieldPtr emptyTargetField = std::make_shared<Field>(emptyTargetPosition, nullptr);

    ActionPtr action_capture = std::make_shared<Action>(CAPTURE, occupiedTargetField);

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteMove, TestSuiteMoveFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorAndGetters){
        BOOST_CHECK_THROW(std::make_shared<Move>(nullptr, nullptr), std::invalid_argument);
        BOOST_CHECK_THROW(std::make_shared<Move>(currentField, nullptr), std::invalid_argument);
        BOOST_CHECK_THROW(std::make_shared<Move>(nullptr, occupiedTargetField), std::invalid_argument);
        BOOST_CHECK_THROW(std::make_shared<Move>(occupiedTargetField, occupiedTargetField), std::invalid_argument);
        BOOST_CHECK_THROW(std::make_shared<Move>(emptyTargetField, currentField), std::invalid_argument);

        Move move(currentField, occupiedTargetField);
        BOOST_TEST(move.getCurrentField() == currentField);
        BOOST_TEST(move.getTargetField() == occupiedTargetField);
        BOOST_TEST(move.getMovedUnit() == whiteQueen);
        BOOST_TEST(move.getAction() == nullptr);

        move.setAction(action_capture);
        BOOST_TEST(move.getAction() == action_capture);

    }

    BOOST_AUTO_TEST_CASE(TestSetAction){
        Move move(currentField, occupiedTargetField);
        BOOST_TEST(move.getAction() == nullptr);

        move.setAction(action_capture);

        BOOST_TEST(move.getAction() == action_capture);
    }

BOOST_AUTO_TEST_SUITE_END()

