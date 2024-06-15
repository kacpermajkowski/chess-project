//
// Created by user on 14.06.2024.
//
#include <boost/test/unit_test.hpp>
#include "../src/model/util/util.cpp"

class Base{};
class Derived1 : public Base{};
class Derived2 : public Base{};

BOOST_AUTO_TEST_SUITE(TestSuiteUtils)

    BOOST_AUTO_TEST_CASE(TestTypeComparisonWrapper){

        BOOST_TEST(!areSameType(new Base(), new Derived1()));
        BOOST_TEST(!areSameType(new Base(), new Derived2()));
        BOOST_TEST(!areSameType(new Derived1(), new Derived2()));
        BOOST_TEST(areSameType(new Derived1(), new Derived1()));    }

BOOST_AUTO_TEST_SUITE_END()