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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        // Create a dummy node to handle edge case when left = 1
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Find the node before the reversal starts
        ListNode* leftPrev = dummy;
        for (int i = 1; i < left; i++) {
            leftPrev = leftPrev->next;
        }
        
        // `current` is the first node to reverse (at position left)
        ListNode* current = leftPrev->next;
        ListNode* prev = nullptr;
        
        // Reverse the segment from left to right
        for (int i = left; i <= right; i++) {
            ListNode* nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        
        // Reconnect the reversed segment
        // leftPrev->next should point to the new head of reversed segment (which is prev)
        // The original first node of the segment (now at the end) should point to the remaining part
        leftPrev->next->next = current;
        leftPrev->next = prev;
        
        return dummy->next;
    }
};
