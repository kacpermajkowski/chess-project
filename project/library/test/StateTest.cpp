#include <boost/test/unit_test.hpp>
#include "model/State.h"

struct TestSuiteStateFixture {
    //
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteState, TestSuiteStateFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorState){
        State state;
        BoardPtr board = state.getBoard();
        BOOST_TEST(board != nullptr);
        BOOST_TEST(state.getConclusion() == IN_PROGRESS);
        BOOST_TEST(state.getMovesWithoutCapture() == 0);
        BOOST_TEST(state.getTurn() == WHITE);
        BOOST_TEST(state.isCheck() == false);
    }

    BOOST_AUTO_TEST_CASE(TestConcludeState){
        State state;
        BOOST_TEST(state.hasConcluded() == false);

        state.conclude(DRAW);
        BOOST_TEST(state.getConclusion() == DRAW);
        BOOST_TEST(state.hasConcluded() == true);

        state.conclude(WHITE_WINS);
        BOOST_TEST(state.getConclusion() == DRAW);
        BOOST_TEST(state.hasConcluded() == true);
    }

    BOOST_AUTO_TEST_CASE(TestRegisterMove){
        State state;
        BOOST_TEST(state.hasConcluded() == false);

        state.conclude(DRAW);
        BOOST_TEST(state.getConclusion() == DRAW);
        BOOST_TEST(state.hasConcluded() == true);

        state.conclude(WHITE_WINS);
        BOOST_TEST(state.getConclusion() == DRAW);
        BOOST_TEST(state.hasConcluded() == true);
    }


BOOST_AUTO_TEST_SUITE_END()