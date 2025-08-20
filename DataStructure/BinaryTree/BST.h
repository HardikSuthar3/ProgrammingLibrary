#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Binary Search Tree Node
class BSTNode {
public:
    int data;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Binary Search Tree Class
class BST {
private:
    BSTNode* root;
    
    // Helper function for inserting a node
    BSTNode* insertHelper(BSTNode* node, int value) {
        if (node == nullptr) {
            return new BSTNode(value);
        }
        
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else if (value > node->data) {
            node->right = insertHelper(node->right, value);
        }
        // If value is equal, we don't insert duplicates
        
        return node;
    }
    
    // Helper function for searching a value
    bool searchHelper(BSTNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return searchHelper(node->left, value);
        } else {
            return searchHelper(node->right, value);
        }
    }
    
    // Helper function to find minimum value node
    BSTNode* findMin(BSTNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    // Helper function for deleting a node
    BSTNode* deleteHelper(BSTNode* node, int value) {
        if (node == nullptr) {
            return node;
        }
        
        if (value < node->data) {
            node->left = deleteHelper(node->left, value);
        } else if (value > node->data) {
            node->right = deleteHelper(node->right, value);
        } else {
            // Node to be deleted found
            
            // Case 1: Node with only right child or no child
            if (node->left == nullptr) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            }
            // Case 2: Node with only left child
            else if (node->right == nullptr) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            
            // Case 3: Node with two children
            BSTNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteHelper(node->right, temp->data);
        }
        return node;
    }
    
    // Helper function for inorder traversal
    void inorderHelper(BSTNode* node, vector<int>& result) {
        if (node != nullptr) {
            inorderHelper(node->left, result);
            result.push_back(node->data);
            inorderHelper(node->right, result);
        }
    }
    
    // Helper function for preorder traversal
    void preorderHelper(BSTNode* node, vector<int>& result) {
        if (node != nullptr) {
            result.push_back(node->data);
            preorderHelper(node->left, result);
            preorderHelper(node->right, result);
        }
    }
    
    // Helper function for postorder traversal
    void postorderHelper(BSTNode* node, vector<int>& result) {
        if (node != nullptr) {
            postorderHelper(node->left, result);
            postorderHelper(node->right, result);
            result.push_back(node->data);
        }
    }
    
    // Helper function to calculate height
    int heightHelper(BSTNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + max(heightHelper(node->left), heightHelper(node->right));
    }
    
    // Helper function to count nodes
    int sizeHelper(BSTNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return 1 + sizeHelper(node->left) + sizeHelper(node->right);
    }
    
    // Helper function to delete all nodes (destructor helper)
    void deleteTree(BSTNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    // Constructor
    BST() {
        root = nullptr;
    }
    
    // Destructor
    ~BST() {
        deleteTree(root);
    }
    
    // Insert a value into the BST
    void insert(int value) {
        root = insertHelper(root, value);
    }
    
    // Search for a value in the BST
    bool search(int value) {
        return searchHelper(root, value);
    }
    
    // Delete a value from the BST
    void remove(int value) {
        root = deleteHelper(root, value);
    }
    
    // Get inorder traversal (sorted order)
    vector<int> inorderTraversal() {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    // Get preorder traversal
    vector<int> preorderTraversal() {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
    
    // Get postorder traversal
    vector<int> postorderTraversal() {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    // Get height of the tree
    int height() {
        return heightHelper(root);
    }
    
    // Get number of nodes in the tree
    int size() {
        return sizeHelper(root);
    }
    
    // Check if tree is empty
    bool isEmpty() {
        return root == nullptr;
    }
    
    // Get minimum value in the tree
    int getMin() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        BSTNode* minNode = findMin(root);
        return minNode->data;
    }
    
    // Get maximum value in the tree
    int getMax() {
        if (root == nullptr) {
            throw runtime_error("Tree is empty");
        }
        BSTNode* current = root;
        while (current->right != nullptr) {
            current = current->right;
        }
        return current->data;
    }
    
    // Level order traversal (BFS)
    vector<int> levelOrderTraversal() {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<BSTNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            BSTNode* current = q.front();
            q.pop();
            result.push_back(current->data);
            
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        
        return result;
    }
    
    // Print tree structure (for debugging)
    void printInorder() {
        vector<int> result = inorderTraversal();
        cout << "Inorder: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    void printPreorder() {
        vector<int> result = preorderTraversal();
        cout << "Preorder: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    void printPostorder() {
        vector<int> result = postorderTraversal();
        cout << "Postorder: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
    
    void printLevelOrder() {
        vector<int> result = levelOrderTraversal();
        cout << "Level Order: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << " ";
        }
        cout << endl;
    }
};