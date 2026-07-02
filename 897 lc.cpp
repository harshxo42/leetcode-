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
private:
    TreeNode* current = nullptr;
    
    void inorder(TreeNode* node) {
        if (!node) return;
        
        inorder(node->left);
        
        // Process current node
        node->left = nullptr;
        current->right = node;
        current = node;
        
        inorder(node->right);
    }
    
public:
    TreeNode* increasingBST(TreeNode* root) {
        // Create a dummy node to serve as the head
        TreeNode* dummy = new TreeNode(0);
        current = dummy;
        
        inorder(root);
        
        return dummy->right;
    }
};
