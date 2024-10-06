#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to check if the tree is balanced
int checkBalance(TreeNode* root) {
    if (root == nullptr) {
        return 0; // Height of an empty tree is 0
    }

    // Recursively check the left and right subtrees
    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1) return -1; // Left subtree is not balanced

    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1) return -1; // Right subtree is not balanced

    // Check if the current node is balanced
    if (abs(leftHeight - rightHeight) > 1) {
        return -1; // Not balanced
    }

    // Return the height of the tree
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkBalance(root) != -1;
}

// Function to delete the tree (to free memory)
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

// Example usage
int main() {
    // Create a balanced binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    // Check if the tree is balanced
    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    // Clean up memory
    deleteTree(root);
    return 0;
}
