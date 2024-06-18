cmake_minimum_required(VERSION 3.4)
project(LibPointerComparison)

set(SOURCE_FILES
        lib.cpp
)

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(LibPointerComparison ${SOURCE_FILES})

target_include_directories(LibPointerComparison PUBLIC include)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)


#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (
        LibPointerComparison
)

#add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
#        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
#        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})