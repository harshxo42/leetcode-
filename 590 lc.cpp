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
    // Recursive solution (trivial)
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorderRecursive(root, result);
        return result;
    }
    
    void postorderRecursive(Node* node, vector<int>& result) {
        if (!node) return;
        
        // Recursively visit all children first
        for (Node* child : node->children) {
            postorderRecursive(child, result);
        }
        
        // Then visit current node
        result.push_back(node->val);
    }
    
    // Iterative solution using two stacks
    vector<int> postorderIterative(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<Node*> stk1, stk2;
        stk1.push(root);
        
        // First stack: process nodes in preorder (root -> children)
        // Second stack: reverse the order to get postorder
        while (!stk1.empty()) {
            Node* node = stk1.top();
            stk1.pop();
            stk2.push(node);
            
            // Push children in normal order (will be popped in reverse)
            for (Node* child : node->children) {
                stk1.push(child);
            }
        }
        
        // stk2 now has nodes in postorder (but reversed)
        while (!stk2.empty()) {
            result.push_back(stk2.top()->val);
            stk2.pop();
        }
        
        return result;
    }
    
    // Alternative iterative solution using one stack (more efficient)
    vector<int> postorderIterativeOneStack(Node* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<pair<Node*, bool>> stk;  // (node, visited)
        stk.push({root, false});
        
        while (!stk.empty()) {
            auto& [node, visited] = stk.top();
            
            if (visited) {
                // All children processed, add current node
                result.push_back(node->val);
                stk.pop();
            } else {
                // Mark as visited and push children in reverse order
                visited = true;
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stk.push({*it, false});
                }
            }
        }
        
        return result;
    }
};
