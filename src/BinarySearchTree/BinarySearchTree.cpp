/**
 *
 * @file BinarySearchTree.cpp
 *
 * @brief Binary search tree class implementation.
 *
 * @author Josh Wiley
 *
 * @details Implements the BinarySearchTree class.
 *
 */
//
//  Preprocessor Directives  ///////////////////////////////////////////////////
//
#ifndef BINARY_SEARCH_TREE_CPP_
#define BINARY_SEARCH_TREE_CPP_
//
//  Header Files  //////////////////////////////////////////////////////////////
//
#include "BinarySearchTree.h"
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Default initializes empty tree
 *
 */
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
    : value_ptr(std::shared_ptr< T >(nullptr)),
      left_tree_ptr(std::shared_ptr< BinarySearchTree< T > >(nullptr)),
      right_tree_ptr(std::shared_ptr< BinarySearchTree< T > >(nullptr)) {}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Copy-initializes tree
 *
 */
template<typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& origin)
{
    // Is empty?
    if (origin.empty())
    {
        // Default-initialize.
        value_ptr = std::shared_ptr< T >(nullptr);
        left_tree_ptr = std::shared_ptr< BinarySearchTree< T > >(nullptr);
        right_tree_ptr = std::shared_ptr< BinarySearchTree< T > >(nullptr);

        // Abort.
        return;
    }

    // Copy-initialize value.
    value_ptr = std::shared_ptr< T >( new T(*origin.value_ptr));

    // If left tree, copy-initialize.
    left_tree_ptr = std::shared_ptr< BinarySearchTree< T > >( 
        origin.left_tree_ptr == nullptr ? nullptr : new BinarySearchTree<T>(*origin.left_tree_ptr)
    );
    
    // If right tree, copy-initialize.
    right_tree_ptr = std::shared_ptr< BinarySearchTree< T > >( 
        origin.right_tree_ptr == nullptr ? nullptr : new BinarySearchTree<T>(*origin.right_tree_ptr)
    );
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Destructor
 *
 */
template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Returns a boolean value indicating if the tree is empty
 *
 * @return Boolean value indicating if the tree is empty
 *
 */
template<typename T>
bool BinarySearchTree<T>::empty()
{
    // Empty if no root.
    return *value_ptr == nullptr;
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Returns a number indicating the current height of the tree
 *
 * @return Integer indicating the current height of the tree
 *
 */
template<typename T>
unsigned int BinarySearchTree<T>::height() {}
//
//  Terminating Precompiler Directives  ////////////////////////////////////////
//
#endif // BINARY_SEARCH_TREE_CPP_
//