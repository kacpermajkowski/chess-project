cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
	src/model/Client.cpp
		src/model/ClientType.cpp
			src/model/Default.cpp
			src/model/Bronze.cpp
			src/model/Silver.cpp
			src/model/Gold.cpp
			src/model/Platinum.cpp
			src/model/Diamond.cpp
    src/model/Address.cpp
	src/model/Vehicle.cpp
		src/model/Bicycle.cpp
		src/model/MotorVehicle.cpp
			src/model/Moped.cpp
			src/model/Car.cpp
	src/model/Rent.cpp

	include/typedefs.h
)

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing() 
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
	test/master.cpp
	test/ClientTest.cpp
	test/AddressTest.cpp
	test/VehicleTest.cpp
	test/RentTest.cpp
)

add_executable (LibraryTester ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTester
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test LibraryTest. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest LibraryTester
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})