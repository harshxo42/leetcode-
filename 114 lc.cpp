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
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* rightSubtree = root->right;
        
        if (root->left) {
            root->right = root->left;
            root->left = nullptr;
            
            // Find the last node in this new right subtree
            TreeNode* last = root->right;
            while (last->right) {
                last = last->right;
            }
            
            // Attach the old right subtree
            last->right = rightSubtree;
        }
    }
};
