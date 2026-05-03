#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo; // start index -> list of sentences
        
        return dfs(s, 0, dict, memo);
    }
    
private:
    vector<string> dfs(const string& s, int start, 
                       unordered_set<string>& dict, 
                       unordered_map<int, vector<string>>& memo) {
        if (memo.count(start)) {
            return memo[start];
        }
        
        vector<string> result;
        
        if (start == s.length()) {
            result.push_back(""); // base case: empty sentence
            return result;
        }
        
        for (int end = start + 1; end <= s.length(); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word)) {
                vector<string> suffixSentences = dfs(s, end, dict, memo);
                for (const string& suffix : suffixSentences) {
                    if (suffix.empty()) {
                        result.push_back(word);
                    } else {
                        result.push_back(word + " " + suffix);
                    }
                }
            }
        }
        
        memo[start] = result;
        return result;
    }
};
