#include <boost/test/unit_test.hpp>
#include <utility>
#include "model/State.h"
#include "model/UnitDir/Pawn.h"
#include "model/exceptions/GameAlreadyFinishedException.h"
#include "model/move/Move.h"
#include "model/UnitDir/Queen.h"
#include "model/UnitDir/Rook.h"

struct TestSuiteStateFixture {

    BoardPtr board = std::make_shared<Board>();
    BoardPtr emptyBoard = std::make_shared<Board>(std::vector<FieldPtr>());

    PositionPtr positionA1 = std::make_shared<Position>(A, _1);
    PositionPtr positionA6 = std::make_shared<Position>(A, _6);
    PositionPtr positionA7 = std::make_shared<Position>(A, _7);

    PositionPtr positionC1 = std::make_shared<Position>(C, _1);

    PositionPtr positionD1 = std::make_shared<Position>(D, _1);

    PositionPtr positionE1 = std::make_shared<Position>(E, _1);
    PositionPtr positionE2 = std::make_shared<Position>(E, _2);
    PositionPtr positionE3 = std::make_shared<Position>(E, _3);
    PositionPtr positionE4 = std::make_shared<Position>(E, _4);
    PositionPtr positionE8 = std::make_shared<Position>(E, _8);

    PositionPtr positionF1 = std::make_shared<Position>(F, _1);
    PositionPtr positionF6 = std::make_shared<Position>(F, _6);

    PositionPtr positionG8 = std::make_shared<Position>(G, _8);

    UnitPtr whiteKing = std::make_shared<King>(WHITE);
    UnitPtr whiteQueen = std::make_shared<Queen>(WHITE);
    UnitPtr whiteRook = std::make_shared<Rook>(WHITE);
    UnitPtr blackKing = std::make_shared<King>(BLACK);
    UnitPtr whitePawn = std::make_shared<Pawn>(WHITE);
    UnitPtr blackPawn = std::make_shared<Pawn>(BLACK);

    FieldPtr fieldA1 = emptyBoard->getField(positionA1);
    FieldPtr fieldC1 = emptyBoard->getField(positionC1);
    FieldPtr fieldE1 = emptyBoard->getField(positionE1);
    FieldPtr fieldE2 = emptyBoard->getField(positionE2);
    FieldPtr fieldE3 = emptyBoard->getField(positionE3);

};

class StateFriend{
private:
    StatePtr state;

public:
    explicit StateFriend(StatePtr state) : state(std::move(state)) {}
    void changeTurn(){
        state->changeTurn();
    }
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

    BOOST_AUTO_TEST_CASE(TestIsCheckState){
        FieldPtr blackKingField = std::make_shared<Field>(std::make_shared<Position>(D, _1), std::make_shared<King>(WHITE));

        BoardPtr caseBoard = std::make_shared<Board>(std::vector<FieldPtr> {
            blackKingField,
            std::make_shared<Field>(std::make_shared<Position>(D, _6), std::make_shared<Queen>(WHITE)),
            std::make_shared<Field>(std::make_shared<Position>(D, _8), std::make_shared<King>(BLACK)),
        });
        StatePtr state = std::make_shared<State>(caseBoard);
        StateFriend stateFriend(state);
        BOOST_TEST(state->isCheck(BLACK));

        if(state->getTurn() == WHITE){
            BOOST_TEST(!state->isCheck());
            stateFriend.changeTurn();
        }

        BOOST_TEST(state->isCheck());
    }

    BOOST_AUTO_TEST_CASE(TestMoveUnitToEmptyField){
        StatePtr state = std::make_shared<State>(emptyBoard);
        state->getBoard()->getField(positionE1)->setUnit(whiteKing);
        state->getBoard()->getField(positionE8)->setUnit(blackKing);

        state->getBoard()->getField(positionE2)->setUnit(whitePawn);

        MovePtr moveWhitePawn = std::make_shared<Move>(fieldE2, fieldE3);

        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE2)->getUnit()) == typeid(Pawn));
        BOOST_REQUIRE(state->getBoard()->getField(positionE3)->getUnit() == nullptr);

        state->makeAMove(moveWhitePawn);

        BOOST_CHECK(state->getBoard()->getField(positionE2)->getUnit() == nullptr);
        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE3)->getUnit()) == typeid(Pawn));
    }

    BOOST_AUTO_TEST_CASE(TestMoveUnitToOccupiedField){
        StatePtr state = std::make_shared<State>(emptyBoard);
        state->getBoard()->getField(positionE1)->setUnit(whiteKing);
        state->getBoard()->getField(positionE8)->setUnit(blackKing);

        state->getBoard()->getField(positionE2)->setUnit(whiteQueen);
        state->getBoard()->getField(positionE3)->setUnit(blackPawn);

        MovePtr moveWhiteQueen = std::make_shared<Move>(fieldE2, fieldE3);
        ActionPtr capturePawn = std::make_shared<Action>(CAPTURE, fieldE3);
        moveWhiteQueen->setAction(capturePawn);

        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE2)->getUnit()) == typeid(Queen));
        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE3)->getUnit()) == typeid(Pawn));
        BOOST_TEST(state->getTakenPieces().size() == 0);

        state->makeAMove(moveWhiteQueen);

        BOOST_CHECK(state->getBoard()->getField(positionE2)->getUnit() == nullptr);
        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE3)->getUnit()) == typeid(Queen));
        BOOST_TEST(state->getTakenPieces().size() == 1);
    }

//    BOOST_AUTO_TEST_CASE(TestCastling){
//        StatePtr state = std::make_shared<State>(emptyBoard);
//        state->getBoard()->getField(positionE1)->setUnit(whiteKing);
//        state->getBoard()->getField(positionE8)->setUnit(blackKing);
//
//        state->getBoard()->getField(positionA1)->setUnit(whiteRook);
//
//        MovePtr moveQueensideCastling = std::make_shared<Move>(fieldE1, field);
//        ActionPtr queensideCastling = std::make_shared<Action>(CASTLE, fieldC1);
//        moveQueensideCastling->setAction(queensideCastling);
//
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE1)->getUnit()) == typeid(King));
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionA1)->getUnit()) == typeid(Rook));
//
//        state->makeAMove(moveQueensideCastling);
//
//        BOOST_CHECK(state->getBoard()->getField(positionE1)->getUnit() == nullptr);
//        BOOST_CHECK(state->getBoard()->getField(positionA1)->getUnit() == nullptr);
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionC1)->getUnit()) == typeid(King));
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionD1)->getUnit()) == typeid(Rook));
//    }
//


//    BOOST_AUTO_TEST_CASE(TestMakeAMoveState){
//        StatePtr state = std::make_shared<State>();
//
//        //white pawn e2 to e3
//        BOOST_CHECK(typeid(*state->getBoard()->getField(positionE2)->getUnit()) == typeid(Pawn));
//        BOOST_TEST(state->getBoard()->getField(positionE3)->getUnit() == nullptr);
//
//        BOOST_TEST(state->getFiftyMovesRuleCounter() == 0);
//        BOOST_TEST(state->getTurn() == WHITE);
//
//        MovePtr moveWhitePawn = std::make_shared<Move>(fieldE2, fieldE3);
//        state->makeAMove(moveWhitePawn);
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