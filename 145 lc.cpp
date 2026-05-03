class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* curr = st.top();
            
            // If going down the tree
            if (!prev || prev->left == curr || prev->right == curr) {
                if (curr->left) {
                    st.push(curr->left);
                } else if (curr->right) {
                    st.push(curr->right);
                } else {
                    // Leaf node
                    result.push_back(curr->val);
                    st.pop();
                }
            }
            // If coming back from left child
            else if (curr->left == prev) {
                if (curr->right) {
                    st.push(curr->right);
                } else {
                    result.push_back(curr->val);
                    st.pop();
                }
            }
            // If coming back from right child
            else if (curr->right == prev) {
                result.push_back(curr->val);
                st.pop();
            }
            
            prev = curr;
        }
        
        return result;
    }
};
