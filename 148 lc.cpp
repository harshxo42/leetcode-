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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        // Step 1: Find length of list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        
        // Step 2: Bottom-up merge sort
        for (int size = 1; size < length; size *= 2) {
            ListNode* prev = &dummy;
            curr = dummy.next;
            
            while (curr) {
                // Find first sublist of size `size`
                ListNode* left = curr;
                ListNode* right = split(left, size);
                curr = split(right, size);
                
                // Merge left and right, attach to prev
                prev->next = merge(left, right);
                
                // Move prev to end of merged list
                while (prev->next) {
                    prev = prev->next;
                }
            }
        }
        
        return dummy.next;
    }
    
private:
    // Split list into two parts: first `size` nodes, rest remains.
    // Returns head of second part.
    ListNode* split(ListNode* head, int size) {
        if (!head) return nullptr;
        
        for (int i = 1; head && i < size; i++) {
            head = head->next;
        }
        
        if (!head) return nullptr;
        
        ListNode* second = head->next;
        head->next = nullptr;
        return second;
    }
    
    // Merge two sorted lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        tail->next = (l1 ? l1 : l2);
        return dummy.next;
    }
};
