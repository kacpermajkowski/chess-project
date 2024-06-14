#include <boost/test/unit_test.hpp>
#include "model/Position.h"

using namespace std;

struct TestSuitePositionFixture{
    PositionPtr position = make_shared<Position>(A, _5);
};

BOOST_FIXTURE_TEST_SUITE(TestSuitePosition, TestSuitePositionFixture)


    BOOST_AUTO_TEST_CASE(TestConstructorAndGetter){
        BOOST_TEST(position->getLetterIndex() == A);
        BOOST_TEST(position->getNumberIndex() == _5);
    }

    BOOST_AUTO_TEST_CASE(TestApplyMoveVector){
        MoveVectorPtr badMoveVector = make_shared<MoveVector>(-55, 1);
        BOOST_TEST(position->applyMoveVector(badMoveVector) == nullptr);
        MoveVectorPtr goodMoveVector = make_shared<MoveVector>(6, -2);
        PositionPtr newPos = position->applyMoveVector(goodMoveVector);
        BOOST_TEST(newPos->equals(make_shared<Position>(G, _3)));
    }

    BOOST_AUTO_TEST_CASE(TestEquals){
        PositionPtr pos1 = make_shared<Position>(B, _5);
        PositionPtr pos2 = make_shared<Position>(B, _5);
        BOOST_TEST(pos1->equals(pos2));
        BOOST_TEST(!pos1->equals(position));
    }

    //TODO: test applyMoveVector - MoveVectorPtr first

BOOST_AUTO_TEST_SUITE_END()