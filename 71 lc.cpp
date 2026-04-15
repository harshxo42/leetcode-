#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string component;
        
        while (std::getline(ss, component, '/')) {
            if (component == "" || component == ".") {
                continue; // ignore empty and current directory
            } else if (component == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // go to parent
                }
            } else {
                stack.push_back(component); // valid directory
            }
        }
        
        // Build the canonical path
        std::string result = "/";
        for (int i = 0; i < stack.size(); i++) {
            result += stack[i];
            if (i != stack.size() - 1) {
                result += "/";
            }
        }
        
        return result;
    }
};
