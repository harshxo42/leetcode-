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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Handle empty list or single node list
        if (!head || !head->next) {
            return head;
        }
        
        ListNode* current = head;
        
        while (current && current->next) {
            if (current->val == current->next->val) {
                // Skip the duplicate node
                ListNode* duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate; // Free memory (optional but good practice)
            } else {
                // Move to next node only when no duplicate is found
                current = current->next;
            }
        }
        
        return head;
    }
};
