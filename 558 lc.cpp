/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        // If both are leaves, OR their values
        if (quadTree1->isLeaf && quadTree2->isLeaf) {
            return new Node(quadTree1->val || quadTree2->val, true);
        }
        
        // If one is leaf
        if (quadTree1->isLeaf) {
            // If leaf is 1, OR result is 1 (leaf)
            if (quadTree1->val) {
                return new Node(true, true);
            }
            // If leaf is 0, return the other tree
            return new Node(quadTree2->val, quadTree2->isLeaf, 
                           quadTree2->topLeft, quadTree2->topRight,
                           quadTree2->bottomLeft, quadTree2->bottomRight);
        }
        
        if (quadTree2->isLeaf) {
            // If leaf is 1, OR result is 1 (leaf)
            if (quadTree2->val) {
                return new Node(true, true);
            }
            // If leaf is 0, return the other tree
            return new Node(quadTree1->val, quadTree1->isLeaf,
                           quadTree1->topLeft, quadTree1->topRight,
                           quadTree1->bottomLeft, quadTree1->bottomRight);
        }
        
        // Neither is leaf - recursively process all four children
        Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        
        // Check if all four children are leaves and have the same value
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && 
            bottomLeft->val == bottomRight->val) {
            // Merge into a single leaf
            return new Node(topLeft->val, true);
        }
        
        // Otherwise, create an internal node
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
