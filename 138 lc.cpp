/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        // Step 1: Create interleaved copy nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        
        // Step 2: Set random pointers for copies
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        // Step 3: Separate the two lists
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        curr = head;
        
        while (curr) {
            copyCurr->next = curr->next;
            copyCurr = copyCurr->next;
            
            curr->next = curr->next->next;
            curr = curr->next;
        }
        
        return dummy->next;
    }
};
