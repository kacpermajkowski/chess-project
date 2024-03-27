#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0 == 0.333, boost::test_tools::tolerance(0.0011));
        BOOST_TEST(true);
    }

BOOST_AUTO_TEST_SUITE_END()