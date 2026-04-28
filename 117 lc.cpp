class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* head = root; // head of current level
        
        while (head) {
            Node dummy;        // dummy node on stack (no heap allocation)
            Node* tail = &dummy;
            dummy.next = nullptr;
            
            // Traverse the current level
            Node* curr = head;
            while (curr) {
                if (curr->left) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }
            
            // Move to next level
            head = dummy.next;
        }
        
        return root;
    }
};
