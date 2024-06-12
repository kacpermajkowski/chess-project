#include <boost/test/unit_test.hpp>
#include "model/State.h"

BOOST_AUTO_TEST_SUITE(TestSuiteState)

    BoardPtr board = new Board();
    State state(board);

    BOOST_AUTO_TEST_CASE(TestConstructorState){
        BOOST_TEST(state.getBoard() == board);
        BOOST_TEST(state.getConclusion() == IN_PROGRESS);
        BOOST_TEST(state.getMovesWithoutCapture() == 0);
    }

    BOOST_AUTO_TEST_CASE(TestConcludeState){
        state.conclude(DRAW);
        BOOST_TEST(state.getConclusion() == DRAW);
    }


BOOST_AUTO_TEST_SUITE_END()