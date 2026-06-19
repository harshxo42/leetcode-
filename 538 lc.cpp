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
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        reverseInorder(root, sum);
        return root;
    }
    
private:
    void reverseInorder(TreeNode* node, int& sum) {
        if (node == nullptr) {
            return;
        }
        
        // Traverse right subtree first (greater values)
        reverseInorder(node->right, sum);
        
        // Update current node
        sum += node->val;
        node->val = sum;
        
        // Traverse left subtree (smaller values)
        reverseInorder(node->left, sum);
    }
};
