#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        int n = s.size();

        unordered_map<string, int> wordCount;
        for (auto &w : words) wordCount[w]++;

        // Try every possible offset
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            unordered_map<string, int> currCount;

            for (int j = i; j + wordLen <= n; j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordCount.count(word)) {
                    currCount[word]++;

                    // Shrink from left if count is too much
                    while (currCount[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currCount[leftWord]--;
                        left += wordLen;
                    }

                    // If valid window found
                    if (j + wordLen - left == totalLen) {
                        result.push_back(left);
                    }
                } else {
                    // reset window
                    currCount.clear();
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};
