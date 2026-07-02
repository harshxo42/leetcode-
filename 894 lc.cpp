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
    vector<TreeNode*> allPossibleFBT(int n) {
        // Even number of nodes cannot form a full binary tree
        if (n % 2 == 0) {
            return {};
        }
        
        // Memoization to avoid recomputation
        static unordered_map<int, vector<TreeNode*>> memo;
        
        if (memo.count(n)) {
            return memo[n];
        }
        
        // Base case: single node tree
        if (n == 1) {
            return {new TreeNode(0)};
        }
        
        vector<TreeNode*> result;
        
        // Try all possible left subtree sizes (must be odd)
        for (int leftNodes = 1; leftNodes < n; leftNodes += 2) {
            int rightNodes = n - 1 - leftNodes;
            
            // rightNodes must be odd (which it will be since odd - 1 - odd = odd)
            vector<TreeNode*> leftSubtrees = allPossibleFBT(leftNodes);
            vector<TreeNode*> rightSubtrees = allPossibleFBT(rightNodes);
            
            // Combine all left and right subtrees
            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        memo[n] = result;
        return result;
    }
};
