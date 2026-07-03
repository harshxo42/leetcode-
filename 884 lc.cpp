#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> freq;
        
        // Helper to split and count words
        auto countWords = [&](const string& s) {
            stringstream ss(s);
            string word;
            while (ss >> word) {
                freq[word]++;
            }
        };
        
        countWords(s1);
        countWords(s2);
        
        vector<string> result;
        for (auto& [word, count] : freq) {
            if (count == 1) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
