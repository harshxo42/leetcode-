class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        // Pruning 1: If word length exceeds total cells
        if (word.length() > m * n) return false;
        
        // Pruning 2: Check character frequencies
        vector<int> boardCount(128, 0);
        vector<int> wordCount(128, 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boardCount[board[i][j]]++;
            }
        }
        
        for (char c : word) {
            wordCount[c]++;
            if (wordCount[c] > boardCount[c]) return false;
        }
        
        // Pruning 3: Start from fewer occurrences to reduce branches
        // Count occurrences of first and last character
        int firstCharCount = 0;
        int lastCharCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) firstCharCount++;
                if (board[i][j] == word.back()) lastCharCount++;
            }
        }
        
        // Start from the end if last character appears fewer times
        // This reduces the search space significantly
        if (lastCharCount < firstCharCount) {
            reverse(word.begin(), word.end());
        }
        
        // Try starting from each cell
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && 
                    dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, 
             int i, int j, int index) {
        // Base case: found all characters
        if (index == word.length()) return true;
        
        // Out of bounds or character mismatch
        if (i < 0 || i >= board.size() || 
            j < 0 || j >= board[0].size() || 
            board[i][j] != word[index]) {
            return false;
        }
        
        // Mark as visited by temporarily changing the cell
        char temp = board[i][j];
        board[i][j] = '#';  // Mark as visited
        
        // Explore all 4 directions
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        
        // Restore the cell (backtrack)
        board[i][j] = temp;
        
        return found;
    }
};
