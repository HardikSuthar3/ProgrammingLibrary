# Binary Search Tree (BST) Implementation

## Overview
This directory contains a complete C++ implementation of a Binary Search Tree data structure with comprehensive functionality.

## Files
- **BST.h** - Complete BST implementation with BSTNode and BST classes
- **BST_Example.cpp** - Example program demonstrating BST usage

## Features

### BSTNode Class
- Simple node structure with integer data and left/right pointers

### BST Class
Complete Binary Search Tree implementation with the following operations:

#### Core Operations
- `insert(int value)` - Insert a value into the BST
- `search(int value)` - Search for a value in the BST
- `remove(int value)` - Remove a value from the BST

#### Traversal Methods
- `inorderTraversal()` - Returns values in sorted order
- `preorderTraversal()` - Returns values in pre-order (root first)
- `postorderTraversal()` - Returns values in post-order (root last)
- `levelOrderTraversal()` - Returns values level by level (BFS)

#### Utility Methods
- `height()` - Returns the height of the tree
- `size()` - Returns the number of nodes in the tree
- `isEmpty()` - Checks if the tree is empty
- `getMin()` - Returns the minimum value in the tree
- `getMax()` - Returns the maximum value in the tree

#### Print Methods
- `printInorder()` - Prints inorder traversal
- `printPreorder()` - Prints preorder traversal
- `printPostorder()` - Prints postorder traversal
- `printLevelOrder()` - Prints level order traversal

## Usage Example

```cpp
#include "BST.h"

int main() {
    BST bst;
    
    // Insert values
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    
    // Search for values
    bool found = bst.search(30); // returns true
    
    // Get tree properties
    int height = bst.height();
    int size = bst.size();
    int minVal = bst.getMin();
    int maxVal = bst.getMax();
    
    // Print traversals
    bst.printInorder();  // Shows sorted order
    
    // Remove values
    bst.remove(30);
    
    return 0;
}
```

## Key Properties
- **Time Complexity**: O(log n) average case for insert/search/delete operations, O(n) worst case
- **Space Complexity**: O(n) for storage, O(log n) average recursion depth
- **No Duplicates**: The implementation does not allow duplicate values
- **Memory Management**: Automatic cleanup via destructor

## Compilation
```bash
g++ BST_Example.cpp -o bst_example
./bst_example
```

The implementation uses standard C++ libraries and should compile with any modern C++ compiler.