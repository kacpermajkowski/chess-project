#include <boost/test/unit_test.hpp>
#include "model/State.h"
#include "model/UnitDir/Pawn.h"
#include "model/exceptions/GameAlreadyFinishedException.h"

struct TestSuiteStateFixture {

    BoardPtr board = std::make_shared<Board>();
    BoardPtr emptyBoard = std::make_shared<Board>(std::vector<FieldPtr>());

    PositionPtr positionA6 = std::make_shared<Position>(A, _6);
    PositionPtr positionA7 = std::make_shared<Position>(A, _7);

    PositionPtr positionE2 = std::make_shared<Position>(E, _2);
    PositionPtr positionE3 = std::make_shared<Position>(E, _3);
    PositionPtr positionE4 = std::make_shared<Position>(E, _4);

    PositionPtr positionF1 = std::make_shared<Position>(F, _1);
    PositionPtr positionF6 = std::make_shared<Position>(F, _6);

    PositionPtr positionG8 = std::make_shared<Position>(G, _8);

};


BOOST_FIXTURE_TEST_SUITE(TestSuiteState, TestSuiteStateFixture)

    BOOST_AUTO_TEST_CASE(TestNoParamConstructorState){
        StatePtr state = std::make_shared<State>();
        BoardPtr madeBoard = state->getBoard();
        BOOST_TEST(madeBoard != nullptr);
        BOOST_TEST(state->getConclusion() == IN_PROGRESS);
        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
        BOOST_TEST(state->getTurn() == WHITE);
        BOOST_TEST(state->isCheck(BLACK) == false);
    }

    BOOST_AUTO_TEST_CASE(TestParamConstructorState){
        StatePtr state = std::make_shared<State>(board);
        BOOST_TEST(state->getBoard() == board);
        BOOST_TEST(state->getConclusion() == IN_PROGRESS);
        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
        BOOST_TEST(state->getTurn() == WHITE);
        BOOST_TEST(state->isCheck(BLACK) == false);
    }

    BOOST_AUTO_TEST_CASE(TestConcludeState){
        StatePtr state = std::make_shared<State>();
        BOOST_TEST(state->hasConcluded() == false);

        state->conclude(DRAW);
        BOOST_TEST(state->getConclusion() == DRAW);
        BOOST_TEST(state->hasConcluded() == true);

        BOOST_CHECK_THROW(state->conclude(WHITE_WINS), GameAlreadyFinishedException);
    }

//    BOOST_AUTO_TEST_CASE(TestMoveUnitBetweenFiels){
//        StatePtr state = std::make_shared<State>(emptyBoard);
//        UnitPtr whitePawn = std::make_shared<Pawn>();
//        state->getBoard()->getField(positionE2)->setUnit(whitePawn);
//        MovePtr moveWhitePawn = std::make_shared<Move>(board->getField(positionE2), board->getField(positionE3));
//
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE2)->getUnit()) == typeid(Pawn));
//        BOOST_REQUIRE(*state->getBoard()->getField(positionE3)->getUnit() == nullptr);
//
//        state->makeAMove(moveWhitePawn);
//
//    }
//
//
//
//    BOOST_AUTO_TEST_CASE(TestMakeAMoveState){
//        StatePtr state = std::make_shared<State>();
//
//        //white pawn e2 to e3
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE2)->getUnit()) == typeid(Pawn));
//        BOOST_TEST(state->getBoard()->getField(positionE3)->getUnit() == nullptr);
//        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
//        BOOST_TEST(state->getTurn() == WHITE);
//
//        MovePtr moveWhitePawn = std::make_shared<Move>(board->getField(positionE2), board->getField(positionE3));
//        state->makeAMove(moveWhitePawn);
//
//        BOOST_TEST(moveWhitePawn->getTargetField()->getPosition() == positionE3);
//        BOOST_TEST(moveWhitePawn->getCurrentField()->getPosition() == positionE2);
//
//
//        BOOST_TEST(state->getLastMove() == moveWhitePawn);
//        BOOST_TEST(state->getBoard()->getField(positionE2)->getUnit() == nullptr);
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE3)->getUnit()) == typeid(Pawn));
//        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
//        BOOST_TEST(state->getTurn() == BLACK);
//
//        //black pawn e7 to e6
//        MovePtr moveBlackPawn = std::make_shared<Move>(board->getField(positionA7), board->getField(positionA6));
//        state->makeAMove(moveBlackPawn);
//        BOOST_TEST(state->getLastMove() == moveBlackPawn);
//        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
//        BOOST_TEST(state->getTurn() == WHITE);
//
//        //white bishop f1 to a6 (captures black pawn) - to check action
//        MovePtr moveWhiteBishop = std::make_shared<Move>(board->getField(positionF1), board->getField(positionA6));
//        state->makeAMove(moveWhiteBishop);
//        BOOST_TEST(state->getLastMove() == moveWhiteBishop);
//        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
//        BOOST_TEST(state->getTurn() == BLACK);
//
//        //black knight g8 to f6 - to check fiftyMovesRuleCounter ++
//        MovePtr moveBlackKnight = std::make_shared<Move>(board->getField(positionG8), board->getField(positionF6));
//        state->makeAMove(moveBlackKnight);
//        BOOST_TEST(state->getLastMove() == moveBlackKnight);
//        BOOST_TEST(state->getFiftyMovesRuleCounter() == 1);
//        BOOST_TEST(state->getTurn() == WHITE);
//
//        //white pawn e3 to e4 - to check if fiftyMovesRuleCounter reset
//        MovePtr moveWhitePawnAgain = std::make_shared<Move>(board->getField(positionE3), board->getField(positionE4));
//        state->makeAMove(moveWhitePawnAgain);
//        BOOST_TEST(state->getLastMove() == moveWhitePawnAgain);
//        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
//        BOOST_TEST(state->getTurn() == BLACK);
//
//        //black knight f6 to e8 - to check if a move can be made when the game is over
//        state->conclude(DRAW);
//        MovePtr moveBlackKnightAgain = std::make_shared<Move>(board->getField(positionF6), board->getField(positionG8));
//        BOOST_CHECK_THROW(state->makeAMove(moveBlackKnightAgain), std::invalid_argument);
//    }




BOOST_AUTO_TEST_SUITE_END()