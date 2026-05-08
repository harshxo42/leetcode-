class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        if (leftDepth == rightDepth) {
            // Left subtree is perfect
            return (1 << leftDepth) + countNodes(root->right);
        } else {
            // Right subtree is perfect
            return (1 << rightDepth) + countNodes(root->left);
        }
    }
    
private:
    int getDepth(TreeNode* node) {
        int depth = 0;
        while (node) {
            depth++;
            node = node->left;
        }
        return depth;
    }
};
