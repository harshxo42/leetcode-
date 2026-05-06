#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char, int> indexS;
        std::unordered_map<char, int> indexT;
        
        for (int i = 0; i < s.length(); i++) {
            if (indexS[s[i]] != indexT[t[i]]) return false;
            indexS[s[i]] = i + 1;  // +1 to avoid 0 default value
            indexT[t[i]] = i + 1;
        }
        
        return true;
    }
};
