#include <string>
#include <stack>
#include <cctype>

class Solution {
public:
    int calculate(std::string s) {
        int result = 0;
        int sign = 1;
        int n = s.length();
        std::stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            
            if (isdigit(c)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                i--; // adjust because loop increments i
            } 
            else if (c == '+') {
                sign = 1;
            } 
            else if (c == '-') {
                sign = -1;
            } 
            else if (c == '(') {
                // push current result and sign to stack, reset for subexpression
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } 
            else if (c == ')') {
                // pop sign, then previous result, apply current result
                int prevSign = st.top(); st.pop();
                int prevResult = st.top(); st.pop();
                result = prevResult + prevSign * result;
            }
            // ignore spaces
        }
        
        return result;
    }
};
