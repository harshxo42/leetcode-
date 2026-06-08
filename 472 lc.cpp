class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        // Sort words by length so shorter words come first
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        
        unordered_set<string> wordSet;
        vector<string> result;
        
        for (const string& word : words) {
            if (canForm(word, wordSet)) {
                result.push_back(word);
            }
            wordSet.insert(word);
        }
        
        return result;
    }
    
private:
    bool canForm(const string& word, const unordered_set<string>& wordSet) {
        // If word set is empty, word can't be formed from other words
        if (wordSet.empty()) return false;
        
        int n = word.length();
        // dp[i] indicates whether word[0:i] can be formed from words in set
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // If prefix up to j can be formed and substring j:i is in wordSet
                if (dp[j] && wordSet.count(word.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
