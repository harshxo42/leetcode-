#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Split by spaces
        while (ss >> word) {
            words.push_back(word);
        }
        
        // Reverse words
        reverse(words.begin(), words.end());
        
        // Join with single space
        string result;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0) result += " ";
            result += words[i];
        }
        
        return result;
    }
};
