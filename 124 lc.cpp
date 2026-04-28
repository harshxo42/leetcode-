/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
    
private:
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;
        
        // Max sum from left and right subtrees (ignore negative contributions)
        int leftSum = max(0, dfs(node->left, maxSum));
        int rightSum = max(0, dfs(node->right, maxSum));
        
        // Path sum going through the current node as the highest node
        int currentPathSum = node->val + leftSum + rightSum;
        maxSum = max(maxSum, currentPathSum);
        
        // Return the max gain from this node to its parent
        return node->val + max(leftSum, rightSum);
    }
};
