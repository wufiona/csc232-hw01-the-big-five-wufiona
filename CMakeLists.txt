cmake_minimum_required(VERSION 3.10)
project(hw01)

# Set compiler flags based on environment
if (MSVC)
    # Force to always compile with W4
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
elseif (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR (CMAKE_C_COMPILER_ID MATCHES "clang")
        OR (CMAKE_CXX_COMPILER_ID MATCHES "clang"))
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -g")
endif ()

# Download and unpack googletest at configure time
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config/CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
        ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path dependencies automatically
# when using CMake 2.8.11 or later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

set(CMAKE_CXX_STANDARD 14)

# Configure targets

set(SRC_MAIN_FILES
        src/Main.cpp
        src/Point.h
        src/TwoDimensionalPoint.cpp src/TwoDimensionalPoint.h)

set(SRC_DEMO_FILES
        src/Demo.cpp
        src/Point.h
        src/TwoDimensionalPoint.cpp src/TwoDimensionalPoint.h)

set(SRC_TEST_FILES
        src/Point.h
        src/TwoDimensionalPoint.cpp src/TwoDimensionalPoint.h test/BigFiveTest.cpp test/BigFiveTest.h test/PointTest.cpp test/PointTest.h)

# Add the files to the targets
add_executable(hw01 ${SRC_MAIN_FILES})
add_executable(hw01Demo ${SRC_DEMO_FILES})
# Now simply link against gtest or gtest_main as needed.
add_executable(hw01Test ${SRC_TEST_FILES} test/TwoDimensionalPointTest.cpp test/TwoDimensionalPointTest.h)
target_link_libraries(hw01Test gtest_main)
target_include_directories(hw01Test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# add custom commands that copy data input files to target working directories
add_custom_command(TARGET hw01 PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/resource/mainData.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET hw01Demo PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/resource/demoData.txt ${CMAKE_CURRENT_BINARY_DIR})
add_custom_command(TARGET hw01Test PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/resource/testData.txt ${CMAKE_CURRENT_BINARY_DIR})

# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

find_package(Doxygen
        OPTIONAL_COMPONENTS dot mscgen dia)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/config/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the config together with the application
    add_custom_target( doc_doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)
