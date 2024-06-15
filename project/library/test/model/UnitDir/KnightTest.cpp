//
//#include <boost/test/unit_test.hpp>
//#include "model/UnitDir/Knight.h"
//#include "model/State.h"
//#include "model/UnitDir/Rook.h"
//#include "model/UnitDir/Rook.h"
//
//using namespace std;
//
//struct TestSuiteKnightFixture {
//
//    BoardPtr board = make_shared<Board>(vector<FieldPtr>());
//    StatePtr state = make_shared<State>(board);
//
//};
//
//BOOST_FIXTURE_TEST_SUITE(TestSuiteKnight, TestSuiteKnightFixture)
//
//    BOOST_AUTO_TEST_CASE(TestConstructorKnight){
//        UnitPtr whiteKnight = make_shared<Knight>(WHITE);
//        BOOST_TEST(whiteKnight->getColor() == WHITE);
//        UnitPtr blackKnight = make_shared<Knight>(BLACK);
//        BOOST_TEST(blackKnight->getColor() == BLACK);
//    }
//
//    BOOST_AUTO_TEST_CASE(TestLegalMovesKnight){
//        UnitPtr whiteKnight = make_shared<Knight>(WHITE);
//        UnitPtr whiteRook = make_shared<Rook>(WHITE);
//        UnitPtr blackRook1 = make_shared<Rook>(BLACK);
//        UnitPtr blackRook2 = make_shared<Rook>(BLACK);
//
//        FieldPtr whiteKnightField = state->getBoard()->getField(make_shared<Position>(D, _8));
//        FieldPtr whiteRookField = state->getBoard()->getField(make_shared<Position>(E, _6));
//        FieldPtr blackRookField1 = state->getBoard()->getField(make_shared<Position>(B, _7));
//        FieldPtr blackRookField2 = state->getBoard()->getField(make_shared<Position>(C, _8));
//
//        BOOST_REQUIRE(whiteKnightField != nullptr);
//        BOOST_REQUIRE(whiteRookField != nullptr);
//        BOOST_REQUIRE(blackRookField1 != nullptr);
//        BOOST_REQUIRE(blackRookField2 != nullptr);
//        whiteKnightField->setUnit(whiteKnight);
//        whiteRookField->setUnit(whiteRook);
//        blackRookField1->setUnit(blackRook1);
//        blackRookField2->setUnit(blackRook2);
//
//        vector<MovePtr> moves = whiteKnight->getLegalMoves(state);
//        list<PositionPtr> positons {
//                std::make_shared<Position>(B, _7),
//                std::make_shared<Position>(C, _6),
//                std::make_shared<Position>(F, _7),
//        };
//
//        BOOST_TEST(positons.size() == moves.size());
//        for(PositionPtr p: positons){
//            bool hasCorrespondingMove = false;
//            for(MovePtr m : moves){
//                BOOST_TEST(m->getCurrentField() == whiteKnightField);
//                PositionPtr target = m->getTargetField()->getPosition();
//                if(target->getLetterIndex() == p->getLetterIndex()){
//                    if(target->getNumberIndex() == p->getNumberIndex()){
//                        hasCorrespondingMove = true;
//                        break;
//                    }
//                }
//            }
//
//            BOOST_TEST(hasCorrespondingMove);
//        }
//
//    }
//
//
//
//BOOST_AUTO_TEST_SUITE_END()
