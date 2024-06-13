#include <boost/test/unit_test.hpp>
#include "model/Board.h"

//test for getField()
using namespace std;

struct TestSuiteBoardFixture{

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteBoard, TestSuiteBoardFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorBoard){
        BoardPtr board = make_shared<Board>(vector<FieldPtr>());
        BOOST_TEST(board->getFields().size() == 64);
    }

BOOST_AUTO_TEST_SUITE_END()