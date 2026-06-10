#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> stk;
        int n = code.size();
        int i = 0;

        // Must start with valid start tag
        if (!isValidStartTag(code, i, stk)) return false;

        // Process the rest of the content
        while (i < n) {
            if (code[i] == '<') {
                if (i + 1 < n && code[i + 1] == '/') {
                    // End tag
                    if (!isValidEndTag(code, i, stk)) return false;
                    // If stack becomes empty, we must be at end of string
                    if (stk.empty() && i != n) return false;
                } else if (i + 8 < n && code.substr(i, 9) == "<![CDATA[") {
                    // CDATA
                    i += 9;
                    int closePos = code.find("]]>", i);
                    if (closePos == string::npos) return false;
                    i = closePos + 3;
                } else {
                    // Start tag
                    if (!isValidStartTag(code, i, stk)) return false;
                }
            } else {
                // Plain text
                i++;
            }
        }

        return stk.empty();
    }

private:
    bool isValidTagName(const string& s, int start, int end) {
        if (start >= end) return false;
        int len = end - start;
        if (len < 1 || len > 9) return false;
        for (int i = start; i < end; i++) {
            if (!isupper(s[i])) return false;
        }
        return true;
    }

    bool isValidStartTag(const string& code, int& i, stack<string>& stk) {
        if (code[i] != '<') return false;
        int j = i + 1;
        while (j < code.size() && code[j] != '>') {
            j++;
        }
        if (j == code.size()) return false; // no matching '>'
        
        string tagName = code.substr(i + 1, j - i - 1);
        if (!isValidTagName(tagName, 0, tagName.size())) return false;
        
        stk.push(tagName);
        i = j + 1;
        return true;
    }

    bool isValidEndTag(const string& code, int& i, stack<string>& stk) {
        if (code[i] != '<' || i + 1 >= code.size() || code[i + 1] != '/') return false;
        int j = i + 2;
        while (j < code.size() && code[j] != '>') {
            j++;
        }
        if (j == code.size()) return false;
        
        string tagName = code.substr(i + 2, j - i - 2);
        if (!isValidTagName(tagName, 0, tagName.size())) return false;
        
        if (stk.empty() || stk.top() != tagName) return false;
        
        stk.pop();
        i = j + 1;
        return true;
    }
};
