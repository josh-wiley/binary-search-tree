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
    : root_value_ptr(nullptr),
      left_tree_ptr(nullptr),
      right_tree_ptr(nullptr) {}
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
        root_value_ptr = nullptr;
        left_tree_ptr = nullptr;
        right_tree_ptr = nullptr;

        // Abort.
        return;
    }

    // Copy-initialize root.
    root_value_ptr = std::make_shared< T >(*origin.root_value_ptr);

    // Copy initialize left tree.
    left_tree_ptr = std::make_shared< BinarySearchTree< T > >( 
        *origin.left_tree_ptr
    );

    // Copy initialize right tree.
    right_tree_ptr = std::make_shared< BinarySearchTree< T > >( 
        *origin.right_tree_ptr
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
    return root_value_ptr == nullptr;
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
        right_tree_ptr->height()
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
    root_value_ptr = nullptr;
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
bool BinarySearchTree<T>::contains(T key)
{
    // Flag.
    auto is_key_present = std::make_shared< bool >(false);

    // Find.
    each_inorder([is_key_present, key] (auto i)
    {
        // Is match?
        if (key == *i)
        {
            // Set flag.
            *is_key_present = true;
        }
    });

    // Return.
    return *is_key_present;
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Iterates over the tree in preorder and executes the iteratee on each
 *          item.
 *
 * @param[in] iteratee
 *            Function to execute with each item.
 *
 */
template<typename T>
void BinarySearchTree<T>::each_preorder(std::function< void(std::shared_ptr<T>) > iteratee)
{
    // Empty?
    if (empty())
    {
        // Abort.
        return;
    }

    // Process root.
    iteratee(root_value_ptr);

    // Forward.
    left_tree_ptr->each_preorder(iteratee);
    right_tree_ptr->each_preorder(iteratee);
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Iterates over the tree in order and executes the iteratee on each
 *          item.
 *
 * @param[in] iteratee
 *            Function to execute with each item.
 *
 */
template<typename T>
void BinarySearchTree<T>::each_inorder(std::function< void(std::shared_ptr<T>) > iteratee)
{
    // Empty?
    if (empty())
    {
        // Abort.
        return;
    }

    // Forward.
    left_tree_ptr->each_inorder(iteratee);

    // Process root.
    iteratee(root_value_ptr);

    // Forward
    right_tree_ptr->each_inorder(iteratee);
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Iterates over the tree in postorder and executes the iteratee on each
 *          item.
 *
 * @param[in] iteratee
 *            Function to execute with each item.
 *
 */
template<typename T>
void BinarySearchTree<T>::each_postorder(std::function< void(std::shared_ptr<T>) > iteratee)
{
    // Empty?
    if (empty())
    {
        // Abort.
        return;
    }

    // Forward.
    left_tree_ptr->each_postorder(iteratee);
    right_tree_ptr->each_postorder(iteratee);

    // Process root.
    iteratee(root_value_ptr);
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Adds item with the value of the key parameter to the correct
 *          position in the tree.
 *
 * @param[in] key
 *            Item to add to tree.
 *
 */
template<typename T>
void BinarySearchTree<T>::add(const T& key)
{
    // Empty?
    if (empty())
    {
        // Add as root.
        root_value_ptr.reset(new T(key));

        // Default-initialize sub-trees.
        left_tree_ptr.reset(new BinarySearchTree< T >());
        right_tree_ptr.reset(new BinarySearchTree< T >());
    }
    // Left tree?
    else if (key <= *root_value_ptr)
    {
        // Add left.
        left_tree_ptr->add(key);
    }
    // Right tree.
    else
    {
        // Add right.
        right_tree_ptr->add(key);
    }
}
//
//  Class Member Implementation  ///////////////////////////////////////////////
//
/**
 *
 * @details Removes item specified by the value of key from the tree.
 *
 * @param[in] key
 *            Item to remove from the tree.
 *
 */
template<typename T>
void BinarySearchTree<T>::remove(const T& key)
{
    // Find node to remove.

    // Is leaf?
        // Remove.

    // Not leaf?
        // Get parent of leaf to swap with.
        // Get leaf to swap with.
        // Swap root values.
        // Remove leaf.
}
//
//  Terminating Precompiler Directives  ////////////////////////////////////////
//
#endif // BINARY_SEARCH_TREE_CPP_
//