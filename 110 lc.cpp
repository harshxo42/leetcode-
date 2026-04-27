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
    bool isBalanced(TreeNode* root) {
        return checkBalance(root) != -1;
    }
    
private:
    int checkBalance(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = checkBalance(node->left);
        if (leftHeight == -1) return -1; // left subtree unbalanced
        
        int rightHeight = checkBalance(node->right);
        if (rightHeight == -1) return -1; // right subtree unbalanced
        
        if (abs(leftHeight - rightHeight) > 1) return -1; // current node unbalanced
        
        return 1 + max(leftHeight, rightHeight);
    }
};
