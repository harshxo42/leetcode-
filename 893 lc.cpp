#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> groups;
        
        for (const string& word : words) {
            string even = "", odd = "";
            
            for (int i = 0; i < word.length(); i++) {
                if (i % 2 == 0) {
                    even += word[i];
                } else {
                    odd += word[i];
                }
            }
            
            sort(even.begin(), even.end());
            sort(odd.begin(), odd.end());
            
            string signature = even + odd;
            groups.insert(signature);
        }
        
        return groups.size();
    }
};
