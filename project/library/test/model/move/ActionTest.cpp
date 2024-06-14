//
// Created by user on 14.06.2024.
//

#include <boost/test/unit_test.hpp>
#include "model/Position.h"
#include "model/Field.h"
#include "model/move/Action.h"
#include "model/UnitDir/Rook.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(TestSuiteAction)

    BOOST_AUTO_TEST_CASE(TestConstructorAndGetter){
        BOOST_CHECK_THROW(make_shared<Action>(CAPTURE, nullptr), std::invalid_argument);

        FieldPtr field = make_shared<Field>(make_shared<Position>(A, _6));
        BOOST_CHECK_THROW(make_shared<Action>(CAPTURE, field), std::invalid_argument);

        field->setUnit(make_shared<Rook>(WHITE));
    }

BOOST_AUTO_TEST_SUITE_END()