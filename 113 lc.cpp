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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        
        dfs(root, targetSum, currentPath, result);
        
        return result;
    }
    
private:
    void dfs(TreeNode* node, int remainingSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;
        
        // Add current node to path
        currentPath.push_back(node->val);
        
        // Check if leaf and sum matches
        if (!node->left && !node->right && remainingSum == node->val) {
            result.push_back(currentPath);
        } else {
            // Recurse left and right
            dfs(node->left, remainingSum - node->val, currentPath, result);
            dfs(node->right, remainingSum - node->val, currentPath, result);
        }
        
        // Backtrack
        currentPath.pop_back();
    }
};
