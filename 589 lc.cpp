/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    // Recursive solution
    vector<int> preorder(Node* root) {
        vector<int> result;
        preorderRecursive(root, result);
        return result;
    }
    
    void preorderRecursive(Node* node, vector<int>& result) {
        if (!node) return;
        
        // Visit current node
        result.push_back(node->val);
        
        // Recursively visit all children
        for (Node* child : node->children) {
            preorderRecursive(child, result);
        }
    }
    
    // Iterative solution using a stack
    vector<int> preorderIterative(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<Node*> stk;
        stk.push(root);
        
        while (!stk.empty()) {
            Node* node = stk.top();
            stk.pop();
            
            // Visit current node
            result.push_back(node->val);
            
            // Push children in reverse order to maintain left-to-right order
            // Since stack is LIFO, we push children from right to left
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stk.push(*it);
            }
        }
        
        return result;
    }
};
