class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        
        int m = board.size();
        int n = board[0].size();
        
        // Mark safe 'O's on boundary and their connected 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);
            if (board[i][n-1] == 'O') dfs(board, i, n-1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);
            if (board[m-1][j] == 'O') dfs(board, m-1, j);
        }
        
        // Capture surrounded O's and restore safe ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';  // captured
                else if (board[i][j] == 'T') board[i][j] = 'O';  // safe
            }
        }
    }
    
private:
    void dfs(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        
        // Bounds check and condition check
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
        
        // Mark as safe (temporary)
        board[i][j] = 'T';
        
        // Explore 4 directions
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
