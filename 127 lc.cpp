#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in wordList, no transformation possible
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<pair<string, int>> q; // {current word, sequence length}
        q.push({beginWord, 1});
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [currentWord, length] = q.front();
            q.pop();
            
            // Try changing each character of currentWord
            for (int i = 0; i < currentWord.length(); i++) {
                char originalChar = currentWord[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == originalChar) continue;
                    
                    string newWord = currentWord;
                    newWord[i] = c;
                    
                    if (newWord == endWord) {
                        return length + 1;
                    }
                    
                    if (wordSet.find(newWord) != wordSet.end() && visited.find(newWord) == visited.end()) {
                        visited.insert(newWord);
                        q.push({newWord, length + 1});
                    }
                }
            }
        }
        
        return 0;
    }
};
