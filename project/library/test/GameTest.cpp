#include <boost/test/unit_test.hpp>
#include "model/Game.h"

#include "model/ui/TextUI.h"

#include "model/player/ComputerPlayer.h"
#include "model/player/HumanPlayer.h"


struct TestSuiteGameFixture {

    PlayerPtr firstPlayer = std::make_shared<ComputerPlayer>(WHITE);
    PlayerPtr secondPlayer = std::make_shared<HumanPlayer>(BLACK);

    PlayerPtr thirdPlayer = std::make_shared<ComputerPlayer>(WHITE);

    UIPtr textUI = std::make_shared<TextUI>();
};


BOOST_FIXTURE_TEST_SUITE(TestSuiteGame, TestSuiteGameFixture)


    BOOST_AUTO_TEST_CASE(TestConstructorGame){
        Game valid_game(firstPlayer, secondPlayer, textUI);
        BOOST_TEST(valid_game.getPlayer(WHITE) == firstPlayer);
        BOOST_TEST(valid_game.getPlayer(BLACK) == secondPlayer);
        BOOST_TEST(valid_game.getUI() == textUI);
        StatePtr state = valid_game.getState();
        BOOST_TEST(state != nullptr);

        BOOST_CHECK_THROW(Game invalid_game(firstPlayer, thirdPlayer, textUI), std::invalid_argument);
    }


BOOST_AUTO_TEST_SUITE_END()