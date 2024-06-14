#include <boost/test/unit_test.hpp>
#include "model/move/MoveVector.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteMoveVector)

    BOOST_AUTO_TEST_CASE(TestConstructor){
    MoveVector moveVector(2, 4);
        BOOST_TEST(moveVector.getColumnOffset() == 2);
        BOOST_TEST(moveVector.getRowOffset() == 4);
    }


BOOST_AUTO_TEST_SUITE_END()
