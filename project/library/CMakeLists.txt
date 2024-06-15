cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/model/UnitDir/Unit.cpp
        src/model/UnitDir/King.cpp
        src/model/UnitDir/Rook.cpp
        src/model/UnitDir/Pawn.cpp
        src/model/UnitDir/Knight.cpp
        src/model/UnitDir/Queen.cpp
        src/model/UnitDir/Bishop.cpp
        src/model/PlayerDir/Player.cpp
        src/model/PlayerDir/HumanPlayer.cpp
        src/model/PlayerDir/ComputerPlayer.cpp
        src/model/State.cpp
        src/model/Game.cpp
        src/model/Board.cpp
        src/model/Field.cpp
        src/model/move/Move.cpp
        src/model/Position.cpp
        src/model/ui/TextUI.cpp
        src/model/move/MoveVector.cpp
        src/model/move/Action.cpp
        include/typedefs.h
        src/model/util/util.cpp
        src/model/exceptions/NoMoveToChooseFromException.cpp
        src/model/exceptions/GameAlreadyFinishedException.cpp
        include/model/exceptions/IllegalMoveException.h
        src/model/exceptions/IllegalMoveException.cpp
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
        test/BoardTest.cpp
        test/FieldTest.cpp
        test/GameTest.cpp
        test/model/move/MoveTest.cpp
        test/PositionTest.cpp
        test/StateTest.cpp
        test/model/UnitDir/RookTest.cpp
        test/PlayerTest.cpp
        include/model/move/MoveVector.h
        test/model/UnitDir/BishopTest.cpp
        test/model/UnitDir/QueenTest.cpp
        test/model/UnitDir/KnightTest.cpp
        test/model/UnitDir/PawnTest.cpp
        src/model/exceptions/NoMoveToChooseFromException.cpp
        src/model/exceptions/GameAlreadyFinishedException.cpp
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