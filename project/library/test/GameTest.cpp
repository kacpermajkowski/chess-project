#include <boost/test/unit_test.hpp>
#include "model/Game.h"

#include "model/PlayerDir/ComputerPlayer.h"
#include "model/PlayerDir/HumanPlayer.h"


struct TestSuiteStateFixture {

    PlayerPtr firstPlayer = std::make_shared<ComputerPlayer>(WHITE);
    PlayerPtr secondPlayer = std::make_shared<HumanPlayer>(BLACK);

    PlayerPtr thirdPlayer = std::make_shared<ComputerPlayer>(WHITE);

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteGame, TestSuiteStateFixture)


    BOOST_AUTO_TEST_CASE(TestConstructorGame){
        Game valid_game(firstPlayer, secondPlayer, nullptr);
        BOOST_TEST(valid_game.getPlayer(WHITE) == firstPlayer);
        BOOST_TEST(valid_game.getPlayer(BLACK) == secondPlayer);

        BOOST_CHECK_THROW(Game invalid_game(firstPlayer, thirdPlayer, nullptr), std::invalid_argument);
    }

    //TODO: getState, getUI


BOOST_AUTO_TEST_SUITE_END()