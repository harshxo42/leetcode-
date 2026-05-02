class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        // Precompute palindrome substrings
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        
        // Length 1 substrings: always palindrome
        for (int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        
        // Length 2 substrings
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i+1]) {
                isPalin[i][i+1] = true;
            }
        }
        
        // Length >= 3 substrings
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && isPalin[i+1][j-1]) {
                    isPalin[i][j] = true;
                }
            }
        }
        
        vector<vector<string>> result;
        vector<string> current;
        
        backtrack(s, 0, current, result, isPalin);
        
        return result;
    }
    
private:
    void backtrack(const string& s, int start, vector<string>& current,
                   vector<vector<string>>& result, const vector<vector<bool>>& isPalin) {
        if (start == s.length()) {
            result.push_back(current);
            return;
        }
        
        for (int end = start; end < s.length(); end++) {
            if (isPalin[start][end]) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, current, result, isPalin);
                current.pop_back();
            }
        }
    }
};
