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

// Recursive inorder traversal
void inorderTraversalRecursive(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    inorderTraversalRecursive(root->left, result);  // Traverse the left subtree
    result.push_back(root->val);                     // Visit the root
    inorderTraversalRecursive(root->right, result); // Traverse the right subtree
}

// Iterative inorder traversal
vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> nodeStack;
    TreeNode* currentNode = root;

    while (currentNode != nullptr || !nodeStack.empty()) {
        // Reach the leftmost node of the current node
        while (currentNode != nullptr) {
            nodeStack.push(currentNode);
            currentNode = currentNode->left;
        }
        // Current must be nullptr at this point
        currentNode = nodeStack.top();
        nodeStack.pop();
        result.push_back(currentNode->val); // Visit the root
        // Move to the right subtree
        currentNode = currentNode->right;
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

    // Vector to hold the result of recursive inorder traversal
    vector<int> resultRecursive;
    inorderTraversalRecursive(root, resultRecursive);
    
    cout << "Inorder Traversal (Recursive): ";
    for (int val : resultRecursive) {
        cout << val << " ";
    }
    cout << endl;

    // Iterative inorder traversal
    vector<int> resultIterative = inorderTraversalIterative(root);
    
    cout << "Inorder Traversal (Iterative): ";
    for (int val : resultIterative) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    deleteTree(root);
    return 0;
}
