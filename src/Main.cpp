/**
 * CSC232 - Data Structures
 * Missouri State University, Fall 2019
 *
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @file   Main.cpp
 * @brief  Contains the entry point for the main target.
 */

#include <cstdlib>
#include <fstream>
#include <iostream>

 /**
  * Entry point for the main target.
  * @param argc the number of command-line arguments, including the name of this target
  * @param argv an array of c-style strings that correspond to the command-line arguments,
  * including the name of this target
  * @return EXIT_SUCCESS is returned upon successful execution.
  */
int main(int argc, char** argv) {
    std::ifstream data{"mainData.txt"};
    if (data.is_open()) {
        std::cout << "Opened file: \"mainData.txt\"" << std::endl;
    } else {
        std::cerr << "Couldn't open \"mainData.txt\"" << std::endl;
    }
    std::cout << "Hello, Main!" << std::endl;

    if (data.is_open()) {
        std::cout << "Closing file: \"mainData.txt\"" << std::endl;
        data.close();
    }
    return EXIT_SUCCESS;
}
