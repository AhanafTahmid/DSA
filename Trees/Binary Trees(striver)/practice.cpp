                                
#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for
// the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Global variable to
    // store the diameter
    int diameter = 0;  

    // Function to calculate
    // the height of a subtree
    void f(Node *node){
        if(root == NULL) return;
        f(node->left);
        f(node->right);
    }
    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }

        // Recursively calculate the
        // height of left and right subtrees
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);

        // Calculate the diameter at the current
        // node and update the global variable
        diameter = max(diameter, leftHeight + rightHeight);

        // Return the height
        // of the current subtree
        return 1 + max(leftHeight, rightHeight);
    }

    // Function to find the
    // diameter of a binary tree
    int diameterOfBinaryTree(Node* root) {
        // Start the recursive
        // traversal from the root
        calculateHeight(root);

        // Return the maximum diameter
        // found during traversal
        return diameter;
    }
};



// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Calculate the diameter of the binary tree
    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
                                
                            