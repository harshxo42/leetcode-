#include <vector>
#include <string>

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    std::string word;
    int refCount;  // Track number of words passing through this node
    
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEnd = false;
        word = "";
        refCount = 0;
    }
};

class Solution {
private:
    std::vector<std::string> result;
    int rows, cols;
    
    void dfs(std::vector<std::vector<char>>& board, TrieNode* node, int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] == '#') {
            return;
        }
        
        char ch = board[row][col];
        int index = ch - 'a';
        
        if (node->children[index] == nullptr || node->children[index]->refCount == 0) {
            return;
        }
        
        node = node->children[index];
        
        if (node->isEnd) {
            result.push_back(node->word);
            node->isEnd = false;  // Avoid duplicates
        }
        
        // Temporarily mark as visited
        board[row][col] = '#';
        
        // Explore neighbors
        dfs(board, node, row - 1, col);  // up
        dfs(board, node, row + 1, col);  // down
        dfs(board, node, row, col - 1);  // left
        dfs(board, node, row, col + 1);  // right
        
        // Backtrack
        board[row][col] = ch;
        
        // Optimization: Remove leaf nodes to prune
        if (node->refCount == 0) {
            delete node;
        }
    }
    
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board, 
                                        std::vector<std::string>& words) {
        rows = board.size();
        cols = board[0].size();
        
        // Build Trie
        TrieNode* root = new TrieNode();
        for (const std::string& word : words) {
            TrieNode* current = root;
            for (char ch : word) {
                int index = ch - 'a';
                if (current->children[index] == nullptr) {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
                current->refCount++;  // Increment reference count
            }
            current->isEnd = true;
            current->word = word;
        }
        
        // Start DFS from each cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                char ch = board[i][j];
                int index = ch - 'a';
                if (root->children[index] != nullptr) {
                    dfs(board, root, i, j);
                }
            }
        }
        
        return result;
    }
};
