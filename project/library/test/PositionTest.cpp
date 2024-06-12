#include <boost/test/unit_test.hpp>
#include "model/Position.h"

BOOST_AUTO_TEST_SUITE(TestSuitePosition)

    Position position(A, _5);
    BOOST_AUTO_TEST_CASE(TestConstructorPosition){
        BOOST_TEST(position.getLetterIndex() == A);
        BOOST_TEST(position.getNumberIndex() == _5);
    }

    //TODO: test applyMoveVector - MoveVectorPtr first

BOOST_AUTO_TEST_SUITE_END()