class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Remove leading nodes with target value
        while (head != nullptr && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        
        if (head == nullptr) return nullptr;
        
        ListNode* curr = head;
        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        
        return head;
    }
};
