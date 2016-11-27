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
#include <algorithm>
#include "utils/data_generator.h"
#include "BinarySearchTree/BinarySearchTree.h"
//
//  Main Function Implementation  //////////////////////////////////////////////
//
int main()
{
    // Binary search trees.
    auto bst1_ptr = std::shared_ptr< BinarySearchTree< unsigned int > >(
        new BinarySearchTree< unsigned int >()
    );
    auto bst2_ptr = std::shared_ptr< BinarySearchTree< unsigned int > >(
        new BinarySearchTree< unsigned int >()
    );

    // Generator function.
    auto generator = [] (BinarySearchTree< unsigned int > bst_ptr, size_t size) mutable
    {
        // Test data.
        auto data_set_ptr = std::shared_ptr< std::list< unsigned int > >(
            new std::list<unsigned int>()
        );

        // Generate test data.
        data_generator::generate_random_data(
            size,
            DATA_SET_MIN,
            DATA_SET_MAX,
            data_set_ptr
        );

        // Build tree.
        std::for_each(data_set_ptr->begin(), data_set_ptr->end(), [] (auto i)
        {
            // Add item.
            bst_ptr->add(i);
        });
    };

    // Parallel BST generation.
    auto bst_builder_1 = std::thread(generator, bst1_ptr, DATA_SET_1_SIZE);
    auto bst_builder_2 = std::thread(generator, bst2_ptr, DATA_SET_2_SIZE);

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