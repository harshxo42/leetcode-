class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> result;
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            
            // Push right first so left is on top
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        
        return result;
    }
};
