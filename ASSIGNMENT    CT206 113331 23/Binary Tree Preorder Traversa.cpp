#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive preorder traversal
void preorderTraversalRecursive(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    result.push_back(root->val); // Visit the root
    preorderTraversalRecursive(root->left, result); // Traverse the left subtree
    preorderTraversalRecursive(root->right, result); // Traverse the right subtree
}

// Iterative preorder traversal
vector<int> preorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();
        result.push_back(currentNode->val); // Visit the root

        // Push right child first so that left child is processed first
        if (currentNode->right != nullptr) {
            nodeStack.push(currentNode->right);
        }
        if (currentNode->left != nullptr) {
            nodeStack.push(currentNode->left);
        }
    }
    return result;
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
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Vector to hold the result of recursive preorder traversal
    vector<int> resultRecursive;
    preorderTraversalRecursive(root, resultRecursive);
    
    cout << "Preorder Traversal (Recursive): ";
    for (int val : resultRecursive) {
        cout << val << " ";
    }
    cout << endl;

    // Iterative preorder traversal
    vector<int> resultIterative = preorderTraversalIterative(root);
    
    cout << "Preorder Traversal (Iterative): ";
    for (int val : resultIterative) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    deleteTree(root);
    return 0;
}
