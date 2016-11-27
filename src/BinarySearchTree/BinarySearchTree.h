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

    void add(T); /**< Adds item to correct place in tree */
    void remove(T); /**< Removes all instances of value from tree */

// Private members.
private:
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