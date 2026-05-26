#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stack;
        
        for (char digit : num) {
            while (k > 0 && !stack.empty() && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }
        
        // If still need to remove more, remove from end
        while (k > 0) {
            stack.pop_back();
            k--;
        }
        
        // Build result, skip leading zeros
        string result = "";
        bool leadingZero = true;
        for (char c : stack) {
            if (leadingZero && c == '0') continue;
            leadingZero = false;
            result += c;
        }
        
        return result.empty() ? "0" : result;
    }
};
