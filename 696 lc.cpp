#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int count = 1;
        
        // Step 1: Build groups of consecutive identical characters
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count); // push the last group
        
        // Step 2: Sum min of adjacent groups
        int result = 0;
        for (int i = 0; i < groups.size() - 1; i++) {
            result += min(groups[i], groups[i + 1]);
        }
        
        return result;
    }
};
