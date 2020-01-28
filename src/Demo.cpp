/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @authors Jim Daehn <jdaehn@missouristate.edu><br />
 *          TODO: Erase this line and add your name using the above format here.
 * @file    Demo.cpp
 * @brief   Contains the entry point for the demo target.
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

/**
 * Entry point for the demo target.
 * @param argc the number of command-line arguments, including the name of this target
 * @param argv an array of c-style strings that correspond to the command-line arguments,
 * including the name of this target
 * @return EXIT_SUCCESS is returned upon successful execution.
 */
int main(int argc, char** argv) {
    std::ifstream data{"demoData.txt"};
    if (data.is_open()) {
        std::cout << "Opened file: \"demoData.txt\"" << std::endl;
    } else {
        std::cerr << "Couldn't open \"demoData.txt\"" << std::endl;
    }
    std::cout << "Hello, Demo!" << std::endl;

    if (data.is_open()) {
        std::cout << "Closing file: \"demoData.txt\"" << std::endl;
        data.close();
    }
    return EXIT_SUCCESS;
}
