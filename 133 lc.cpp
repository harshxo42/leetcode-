class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        unordered_map<Node*, Node*> cloneMap;
        
        // Clone the starting node
        cloneMap[node] = new Node(node->val);
        
        queue<Node*> q;
        q.push(node);
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for (Node* neighbor : curr->neighbors) {
                // If neighbor not cloned yet, clone it and add to queue
                if (cloneMap.find(neighbor) == cloneMap.end()) {
                    cloneMap[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                // Connect cloned current to cloned neighbor
                cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
            }
        }
        
        return cloneMap[node];
    }
};
