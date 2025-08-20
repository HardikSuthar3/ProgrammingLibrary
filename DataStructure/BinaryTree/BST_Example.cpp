#include "BST.h"

// Example program demonstrating Binary Search Tree usage
int main() {
    cout << "=== Binary Search Tree Example Program ===" << endl;
    
    // Create BST instance
    BST bst;
    
    // Insert some values
    cout << "Inserting values: 50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45" << endl;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    bst.insert(10);
    bst.insert(25);
    bst.insert(35);
    bst.insert(45);
    
    cout << "BST Size: " << bst.size() << endl;
    cout << "BST Height: " << bst.height() << endl;
    
    // Display all traversals
    cout << "\n--- Tree Traversals ---" << endl;
    bst.printInorder();     // Shows sorted order
    bst.printPreorder();    // Shows construction order
    bst.printPostorder();   // Shows deletion order
    bst.printLevelOrder();  // Shows level-wise structure
    
    // Search operations
    cout << "\n--- Search Operations ---" << endl;
    vector<int> searchValues = {25, 55, 80, 100};
    for (int val : searchValues) {
        cout << "Search " << val << ": " << (bst.search(val) ? "Found" : "Not Found") << endl;
    }
    
    // Min and Max
    cout << "\nMinimum value: " << bst.getMin() << endl;
    cout << "Maximum value: " << bst.getMax() << endl;
    
    // Delete operations
    cout << "\n--- Delete Operations ---" << endl;
    cout << "Deleting 10 (leaf node):" << endl;
    bst.remove(10);
    bst.printInorder();
    
    cout << "Deleting 20 (node with one child):" << endl;
    bst.remove(20);
    bst.printInorder();
    
    cout << "Deleting 30 (node with two children):" << endl;
    bst.remove(30);
    bst.printInorder();
    
    cout << "Final BST size: " << bst.size() << endl;
    cout << "Final BST height: " << bst.height() << endl;
    
    cout << "\n=== End of BST Example ===" << endl;
    
    return 0;
}