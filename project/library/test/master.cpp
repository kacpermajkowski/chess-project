#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

struct TestConfig{

    TestConfig(){
        tolerance(0.0001);

    }

    ~TestConfig(){

    }

};