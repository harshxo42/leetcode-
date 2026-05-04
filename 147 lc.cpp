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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0); // dummy node before sorted list
        ListNode* curr = head;
        
        while (curr) {
            // Find the position to insert current node in the sorted list
            ListNode* prev = dummy;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            // Store next node before modifying pointers
            ListNode* nextNode = curr->next;
            
            // Insert curr between prev and prev->next
            curr->next = prev->next;
            prev->next = curr;
            
            // Move to next node in original list
            curr = nextNode;
        }
        
        head = dummy->next;
        delete dummy;
        return head;
    }
};
