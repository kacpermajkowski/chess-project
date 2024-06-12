#include <boost/test/unit_test.hpp>
#include "model/Game.h"

//#include "model/PlayerDir/HumanPlayer.h"
//#include "model/PlayerDir/ComputerPlayer.h"

BOOST_AUTO_TEST_SUITE(TestSuiteGame)

    Game game(PVP, nullptr);

    //PlayerPtr whitePlayer = new HumanPlayer(WHITE);
    //PlayerPtr blackPlayer = new ComputerPlayer(BLACK);
    //BoardPtr board = new Board();
    //StatePtr state = new State(board);

    BOOST_AUTO_TEST_CASE(TestConstructorGame){
//        BOOST_TEST(game.getPlayer(WHITE) == whitePlayer);
//        BOOST_TEST(game.getPlayer(BLACK) == blackPlayer);
        BOOST_TEST(game.getUi() == nullptr);
//        BOOST_TEST(game.getState() == state);
//        BOOST_TEST(game.getBoard() == board);
    }

BOOST_AUTO_TEST_SUITE_END()