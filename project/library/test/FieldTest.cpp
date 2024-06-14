#include <boost/test/unit_test.hpp>
#include "model/Field.h"

#include "model/UnitDir/Queen.h"


struct TestSuiteFieldFixture {

    UnitPtr unitWhite = std::make_shared<Queen>(WHITE);
    UnitPtr unitBlack = std::make_shared<Queen>(BLACK);

    PositionPtr position = std::make_shared<Position>(A, _5);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteField, TestSuiteFieldFixture)

    BOOST_AUTO_TEST_CASE(TestConstructorAndGetter){
        Field emptyField(position);
        BOOST_TEST(emptyField.isOccupied() == false);

        Field fieldWithUnit(position, unitWhite);
        BOOST_TEST(fieldWithUnit.getPosition() == position);
        BOOST_TEST(fieldWithUnit.getUnit() == unitWhite);
    }

    BOOST_AUTO_TEST_CASE(TestUnitSetter){
        Field field(position, unitWhite);
        BOOST_TEST(field.getUnit() == unitWhite);
        field.setUnit(unitBlack);
        BOOST_TEST(field.getUnit() == unitBlack);
    }

    BOOST_AUTO_TEST_CASE(TestIsOccupied){
        Field field(position);
        BOOST_TEST(field.isOccupied() == false);
        BOOST_TEST(field.isOccupiedByEnemy(WHITE) == false);
        BOOST_TEST(field.isOccupiedByEnemy(BLACK) == false);
        BOOST_TEST(field.isOccupiedByAlly(WHITE) == false);
        BOOST_TEST(field.isOccupiedByAlly(BLACK) == false);

        field.setUnit(unitWhite);
        BOOST_TEST(field.isOccupied());
        BOOST_TEST(field.isOccupiedByEnemy(WHITE) == false);
        BOOST_TEST(field.isOccupiedByEnemy(BLACK) == true);

        BOOST_TEST(field.isOccupiedByEnemy(unitWhite) == false);
        BOOST_TEST(field.isOccupiedByEnemy(unitBlack) == true);

        BOOST_TEST(field.isOccupiedByAlly(WHITE) == true);
        BOOST_TEST(field.isOccupiedByAlly(BLACK) == false);

        BOOST_TEST(field.isOccupiedByAlly(unitWhite) == true);
        BOOST_TEST(field.isOccupiedByAlly(unitBlack) == false);
    }


BOOST_AUTO_TEST_SUITE_END()
