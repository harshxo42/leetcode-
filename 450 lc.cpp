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
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: tree is empty
        if (!root) {
            return nullptr;
        }
        
        // Search phase - O(height)
        if (key < root->val) {
            // Key is in left subtree
            root->left = deleteNode(root->left, key);
            return root;
        }
        else if (key > root->val) {
            // Key is in right subtree
            root->right = deleteNode(root->right, key);
            return root;
        }
        else {
            // Found the node to delete
            
            // Case 1: Leaf node (no children)
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            
            // Case 2: Only right child
            if (!root->left) {
                TreeNode* rightChild = root->right;
                delete root;
                return rightChild;
            }
            
            // Case 2: Only left child
            if (!root->right) {
                TreeNode* leftChild = root->left;
                delete root;
                return leftChild;
            }
            
            // Case 3: Two children
            // Find inorder successor (smallest node in right subtree)
            TreeNode* successor = findMin(root->right);
            
            // Replace current node's value with successor's value
            root->val = successor->val;
            
            // Delete the inorder successor from the right subtree
            root->right = deleteNode(root->right, successor->val);
            
            return root;
        }
    }
    
private:
    TreeNode* findMin(TreeNode* node) {
        // Find the node with minimum value in a subtree
        TreeNode* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
};
