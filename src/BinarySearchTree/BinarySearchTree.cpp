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
    : root_value_ptr(std::shared_ptr< T >(nullptr)),
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
        root_value_ptr = std::shared_ptr< T >(nullptr);
        left_tree_ptr = std::shared_ptr< BinarySearchTree< T > >(new BinarySearchTree< T >());
        right_tree_ptr = std::shared_ptr< BinarySearchTree< T > >(new BinarySearchTree< T >());

        // Abort.
        return;
    }

    // Copy-initialize root.
    root_value_ptr = std::shared_ptr< T >( new T(*origin.value_ptr));

    // Copy initialize left tree.
    left_tree_ptr = std::shared_ptr< BinarySearchTree< T > >( 
        new BinarySearchTree<T>(*origin.left_tree_ptr)
    );

    // Copy initialize right tree.
    right_tree_ptr = std::shared_ptr< BinarySearchTree< T > >( 
        new BinarySearchTree<T>(*origin.right_tree_ptr)
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
    return *root_value_ptr == nullptr;
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
unsigned int BinarySearchTree<T>::height()
{
    // Empty?
    if (empty())
    {
        // Return 0.
        return 0;
    }

    // Return.
    return 1 + std::max(
        left_tree_ptr->height(),
        *right_tree_ptr == right_tree_ptr->height()
    );
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Returns a number indicating the current number of nodes in the tree
 *
 * @return Integer indicating the current number of nodes in the tree
 *
 */
template<typename T>
unsigned int BinarySearchTree<T>::total_nodes() {}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Returns the value of the root node
 *
 * @return Returns the value of the root node
 *
 */
template<typename T>
T BinarySearchTree<T>::root_value()
{
    // Return root value.
    return *root_value_ptr;
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Clears the binary search tree
 *
 */
template<typename T>
void BinarySearchTree<T>::clear()
{
    // Reset all smart pointers.
    root_value_ptr.reset(nullptr);
    left_tree_ptr.reset(new BinarySearchTree< T >());
    right_tree_ptr.reset(new BinarySearchTree< T >());
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Searches the tree for the value and returns a boolean value that
 *          represents the results of the search.
 *
 * @param[in] key
 *            Value used for comparison in search.
 *
 * @return Boolean value that represents the results of the search.
 *
 */
template<typename T>
bool BinarySearchTree<T>::contains(T key) {}

template<typename T>
void BinarySearchTree<T>::preorder_traverse() {}

template<typename T>
void BinarySearchTree<T>::inorder_traverse() {}

template<typename T>
void BinarySearchTree<T>::postorder_traverse() {}

template<typename T>
void BinarySearchTree<T>::add(const T& key)
{
    // Empty?
    if (empty())
    {
        // Add as root.
        root_value_ptr.reset(new T(key));

        // Default initialize sub-trees.
        left_tree_ptr.reset(new BinarySearchTree< T >());
        right_tree_ptr.reset(new BinarySearchTree< T >());
    }

    // Which tree?
}

template<typename T>
void BinarySearchTree<T>::remove(const T& key) {}
//
//  Terminating Precompiler Directives  ////////////////////////////////////////
//
#endif // BINARY_SEARCH_TREE_CPP_
//