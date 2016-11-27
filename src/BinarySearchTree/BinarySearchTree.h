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
//
//  Class Definition  //////////////////////////////////////////////////////////
//
template<class T>
class BinarySearchTree
{
// Public members.
public:
    BinarySearchTree(); /**< Default constructor */
    BinarySearchTree(const BinarySearchTree<T>&); /**< Copy constructor */
    ~BinarySearchTree(); /**< Destructor */

    bool empty(); /**< Returns boolean indicating whether the tree is empty or not */
    unsigned int height(); /**< Returns height of tree */
    unsigned int total_nodes(); /**< Returns the total number of nodes in the tree */
    T root_value(); /**< Returns value of root node */
    void clear(); /**< Clears tree and all sub-trees. */
    bool contains(T); /**< Check if the value exists in the tree */
    void preorder_traverse();
    void inorder_traverse();
    void postorder_traverse();
    void add(T); /**< Adds item to correct place in tree */
    void remove(T); /**< Removes value from tree */

// Private members.
private:
    std::shared_ptr< T > root_value_ptr; /** Smart pointer to value of root node */
    std::shared_ptr< BinarySearchTree< T > > left_tree_ptr; /**< Smart pointer to the left binary search tree */
    std::shared_ptr< BinarySearchTree< T > > right_tree_ptr; /**< Smart pointer to the right binary search tree */
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