#include <iostream>
#include <string>
#include "dynamic_array.h"
#include <boost/test/included/unit_test.hpp>

#define BOOST_TEST_MODULE dynamic_array_tests

BOOST_AUTO_TEST_SUITE( test_suite_main_features )

    DynamicStringArray d;

    d.addEntry("check");
    d.addEntry("this");
    d.addEntry("out");

BOOST_AUTO_TEST_CASE( test_case_addEntry_getEntry_getSize ){
    
    BOOST_REQUIRE_EQUAL(d.getEntry(0), "check");
    BOOST_REQUIRE_EQUAL(d.getSize(), 3);
}

BOOST_AUTO_TEST_CASE( test_case_deleteEntry_true ){
    BOOST_REQUIRE(d.deleteEntry("out"));
}

BOOST_AUTO_TEST_CASE( test_case_deleteEntry_false ){
    BOOST_REQUIRE(d.deleteEntry("no") == false);
}

BOOST_AUTO_TEST_SUITE_END()