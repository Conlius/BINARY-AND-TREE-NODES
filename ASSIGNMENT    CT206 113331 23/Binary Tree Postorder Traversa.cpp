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

// Recursive postorder traversal
void postorderTraversalRecursive(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    postorderTraversalRecursive(root->left, result);   // Traverse the left subtree
    postorderTraversalRecursive(root->right, result);  // Traverse the right subtree
    result.push_back(root->val);                        // Visit the root
}

// Iterative postorder traversal
vector<int> postorderTraversalIterative(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }

    stack<TreeNode*> nodeStack;
    stack<int> outputStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* currentNode = nodeStack.top();
        nodeStack.pop();
        outputStack.push(currentNode->val); // Store root in output stack

        // Push left and right children to the stack
        if (currentNode->left != nullptr) {
            nodeStack.push(currentNode->left);
        }
        if (currentNode->right != nullptr) {
            nodeStack.push(currentNode->right);
        }
    }

    // The output stack now contains the nodes in postorder
    while (!outputStack.empty()) {
        result.push_back(outputStack.top());
        outputStack.pop();
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

    // Vector to hold the result of recursive postorder traversal
    vector<int> resultRecursive;
    postorderTraversalRecursive(root, resultRecursive);
    
    cout << "Postorder Traversal (Recursive): ";
    for (int val : resultRecursive) {
        cout << val << " ";
    }
    cout << endl;

    // Iterative postorder traversal
    vector<int> resultIterative = postorderTraversalIterative(root);
    
    cout << "Postorder Traversal (Iterative): ";
    for (int val : resultIterative) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    deleteTree(root);
    return 0;
}
