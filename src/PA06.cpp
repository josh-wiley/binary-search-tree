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
    auto bst1_ptr = std::make_shared< BinarySearchTree< unsigned int > >();
    auto bst2_ptr = std::make_shared< BinarySearchTree< unsigned int > >();

    // Generator function.
    auto generator = [] (std::shared_ptr< BinarySearchTree< unsigned int > > bst_ptr, size_t size)
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
        std::for_each(data_set_ptr->begin(), data_set_ptr->end(), [bst_ptr] (auto i)
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

    // Display BST #1 height.
    std::cout << "\n\nBST #1 height: " << bst1_ptr->height();

    // Display function.
    auto display_each = [] (auto i) { std::cout << *i << ' '; };

    // Display BST #1 in-order output.
    std::cout << "\n\nBST #1 in-order:\n";
    bst1_ptr->each_inorder(display_each);

    // Display BST #2 pre-order.
    std::cout << "\n\nBST #2 pre-order:\n";
    bst2_ptr->each_preorder(display_each);

    // Display BST #2 in-order.
    std::cout << "\n\nBST #2 in-order:\n";
    bst2_ptr->each_inorder(display_each);

    // Display BST #2 post-order.
    std::cout << "\n\nBST #2 post-order:\n";
    bst2_ptr->each_postorder(display_each);
    
    // Remove values in BST #2 from BST #1.
    bst2_ptr->each_inorder([bst1_ptr] (auto node_ptr)
    {
        // Remove from BST #1 and display result.
        if (bst1_ptr->remove(*node_ptr))
        {
            // Display success message.
            std::cout << "\n\nSuccessfully removed " << *node_ptr << " from BST #1...";
        }
        else
        {
            // Display failure message.
            std::cout << "\n\nThe value " << *node_ptr << " was not found in BST #1...";
        }
        
    });
    
    // Display BST #1 height (again).
    std::cout << "\n\nBST #1 height: " << bst1_ptr->height();

    // Display BST #1 total nodes.
    std::cout << "\n\nBST #1 total nodes: " << bst1_ptr->total_nodes();

    // Display BST #1 inorder.
    std::cout << "\n\nBST #1 in-order:\n";
    bst1_ptr->each_inorder(display_each);

    // Display BST #1 and BST #2 empty state.
    std::cout << "\n\nBST #1 empty state is " << bst1_ptr->empty()
              << "\n\nBST #2 empty state is " << bst2_ptr->empty();

    // Clear BSTs.
    bst1_ptr->clear();
    bst2_ptr->clear();

    // Display BST #1 and BST #2 empty state (again).
    std::cout << "\n\nBST #1 empty state is " << bst1_ptr->empty()
              << "\n\nBST #2 empty state is " << bst2_ptr->empty();

    // Padding and flush stream.
    std::cout << '\n' << std::endl;

    // Exit (success).
    return 0;
}
//
//  Terminating Precompiler Directives  ////////////////////////////////////////
//
#endif // PA06_CPP_
//