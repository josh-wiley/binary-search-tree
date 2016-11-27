/**
 *
 * @file PA06.cpp
 *
 * @brief Driver for binary search tree ADT.
 *
 * @author Josh Wiley
 *
 * @details Generates random data, inserts into binary search trees, and tests
 *          member functions.
 *
 */
//
//  Preprocessor Directives  ///////////////////////////////////////////////////
//
#ifndef PA06_CPP_
#define PA06_CPP_
#define DATA_SET_1_SIZE 100
#define DATA_SET_2_SIZE 10
#define DATA_SET_MIN 1
#define DATA_SET_MAX 200
//
//  Header Files  //////////////////////////////////////////////////////////////
//
#include <iostream>
#include <memory>
#include <thread>
#include <algorithm> // TODO: REMOVE?
#include "utils/data_generator.h"
//
//  Main Function Implementation  //////////////////////////////////////////////
//
int main()
{
    // Test data containers. (move into lambda)
    auto data_set_1_ptr = std::shared_ptr< std::list< unsigned int > >(
        new std::list<unsigned int>()
    );
    auto data_set_2_ptr = std::shared_ptr< std::list< unsigned int > >(
        new std::list<unsigned int>()
    );

    // Binary search trees.

    // Generator function.

    // Parallel BST generation.
    auto bst_builder_1 = std::thread(
        data_generator::generate_random_data,
        DATA_SET_1_SIZE,
        DATA_SET_MIN,
        DATA_SET_MAX,
        data_set_1_ptr
    );
    auto bst_builder_2 = std::thread(
        data_generator::generate_random_data,
        DATA_SET_2_SIZE,
        DATA_SET_MIN,
        DATA_SET_MAX,
        data_set_2_ptr
    );

    // Block until finished.
    bst_builder_1.join();
    bst_builder_2.join();

    // Display BST #1 stats.

    // Display BST #2 stats.

    // Remove values in BST #2 from BST #1.

    // Display BST #1 stats.

    // Clear BSTs.

    // Exit (success).
    return 0;
}
//
//  Terminating Precompiler Directives  ////////////////////////////////////////
//
#endif // PA06_CPP_
//