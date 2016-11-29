/**
 *
 * @file BinarySearchTree.h
 *
 * @brief Binary search tree class definition.
 *
 * @author Josh Wiley
 *
 * @details Defines the BinarySearchTree class.
 *
 */
//
//  Preprocessor Directives  ///////////////////////////////////////////////////
//
#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_
//
//  Header Files  //////////////////////////////////////////////////////////////
//
#include <memory>
#include <algorithm>
#include <functional>
//
//  Class Definition  //////////////////////////////////////////////////////////
//
template<class T>
class BinarySearchTree
{
// Public members.
public:
    BinarySearchTree(BinarySearchTree* parent_ptr = nullptr); /**< Default constructor */
    BinarySearchTree(const BinarySearchTree<T>&); /**< Copy constructor */
    ~BinarySearchTree(); /**< Destructor */

    bool empty(); /**< Returns boolean indicating whether the tree is empty or not */
    unsigned int height(); /**< Returns height of tree */
    unsigned int total_nodes(); /**< Returns the total number of nodes in the tree */
    T root_value(); /**< Returns value of root node */
    void clear(); /**< Clears tree and all sub-trees. */
    bool contains(T); /**< Check if the value exists in the tree */
    void each_preorder(std::function< void(std::shared_ptr<T>) >); /**< Executes provided function on each item in pre-order. */
    void each_inorder(std::function< void(std::shared_ptr<T>) >); /**< Executes provided function on each item in-order. */
    void each_postorder(std::function< void(std::shared_ptr<T>) >); /**< Executes provided function on each item in post-order. */
    bool add(const T&); /**< Adds item to correct place in tree and returns boolean value indicating success */
    bool remove(const T&); /**< Removes value from tree and returns boolean value indicating success */

// Private members.
private:
    BinarySearchTree< T >* parent_rawptr_; /**< Smart pointer to parent. */
    std::shared_ptr< T > root_value_ptr_; /** Smart pointer to value of root node */
    std::shared_ptr< BinarySearchTree< T > > left_tree_ptr_; /**< Smart pointer to the left binary search tree */
    std::shared_ptr< BinarySearchTree< T > > right_tree_ptr_; /**< Smart pointer to the right binary search tree */

    BinarySearchTree< T >* fetch_node(T); /**< Search for node with given value and return pointer to node */
};
//
//  Implementation Files  //////////////////////////////////////////////////////
//
#include "BinarySearchTree.cpp"
//
//  Terminating Precompiler Directives  ////////////////////////////////////////
//
#endif // BINARY_SEARCH_TREE_H_
//