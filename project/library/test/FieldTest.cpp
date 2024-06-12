#include <boost/test/unit_test.hpp>
#include "model/Field.h"

#include "model/UnitDir/Rook.h"

BOOST_AUTO_TEST_SUITE(TestSuiteField)

    PositionPtr position = new Position(A, _5);
    UnitPtr rookBlack = new Rook(BLACK);
    UnitPtr rookWhite = new Rook(WHITE);
    Field field(position, rookBlack);

    BOOST_AUTO_TEST_CASE(TestConstructorField){
        BOOST_TEST(field.getPosition() == position);
        BOOST_TEST(field.getUnit() == rookBlack);
    }

    BOOST_AUTO_TEST_CASE(TestSetterField){
        field.setUnit(rookWhite);
        BOOST_TEST(field.getUnit() == rookWhite);
    }

    //test for getPromotionField()

BOOST_AUTO_TEST_SUITE_END()
