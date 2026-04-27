/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        
        // Get length of linked list
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        
        // Use helper function with reference to head pointer
        return buildBST(head, 0, len - 1);
    }
    
private:
    TreeNode* buildBST(ListNode*& head, int left, int right) {
        if (left > right) return nullptr;
        
        int mid = left + (right - left) / 2;
        
        // Build left subtree
        TreeNode* leftChild = buildBST(head, left, mid - 1);
        
        // Current root
        TreeNode* root = new TreeNode(head->val);
        root->left = leftChild;
        
        // Move head to next node
        head = head->next;
        
        // Build right subtree
        root->right = buildBST(head, mid + 1, right);
        
        return root;
    }
};
