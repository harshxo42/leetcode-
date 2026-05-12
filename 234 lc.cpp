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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        // Step 1: Find middle
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Step 2: Reverse second half
        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        while (curr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        
        // Step 3: Compare
        ListNode *first = head;
        ListNode *second = prev;
        bool isPalin = true;
        while (second) {
            if (first->val != second->val) {
                isPalin = false;
                break;
            }
            first = first->next;
            second = second->next;
        }
        
        // Step 4: Restore list (optional)
        curr = prev;
        prev = nullptr;
        while (curr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        if (slow) slow->next = prev;
        
        return isPalin;
    }
};
