#include <boost/test/unit_test.hpp>
#include "model/Move.h"

BOOST_AUTO_TEST_SUITE(TestSuiteMove)

    PositionPtr start = new Position(A, _5);
    PositionPtr target = new Position(C, _3);
    Move move(start, target);

    BOOST_AUTO_TEST_CASE(TestConstructorMove){
        BOOST_TEST(move.getStartingPosition() == start);
        BOOST_TEST(move.getTargetPosition() == target);
    }

BOOST_AUTO_TEST_SUITE_END()
