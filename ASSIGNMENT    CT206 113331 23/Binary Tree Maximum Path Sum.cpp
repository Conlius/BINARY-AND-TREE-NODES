#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the maximum path sum
int maxPathSumHelper(TreeNode* root, int& maxSum) {
    if (root == nullptr) {
        return 0; // Base case: null nodes contribute 0
    }

    // Recursive call for left and right subtrees
    int leftMax = max(maxPathSumHelper(root->left, maxSum), 0);  // Ignore negative sums
    int rightMax = max(maxPathSumHelper(root->right, maxSum), 0); // Ignore negative sums

    // Calculate the maximum path sum with the current root
    int currentPathSum = root->val + leftMax + rightMax;

    // Update the global maximum sum
    maxSum = max(maxSum, currentPathSum);

    // Return the maximum sum of the path that can be extended to the parent
    return root->val + max(leftMax, rightMax);
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN; // Initialize to the smallest possible integer
    maxPathSumHelper(root, maxSum);
    return maxSum;
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

    // Calculate the maximum path sum
    int result = maxPathSum(root);
    
    cout << "Maximum Path Sum: " << result << endl;

    // Clean up memory
    deleteTree(root);
    return 0;
}
