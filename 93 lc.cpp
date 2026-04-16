class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> current;
        
        // Early pruning: length too short or too long for valid IP
        if (s.length() < 4 || s.length() > 12) return result;
        
        backtrack(s, 0, current, result);
        return result;
    }
    
private:
    void backtrack(const string& s, int start, vector<string>& current, 
                   vector<string>& result) {
        // Prune: remaining digits can't form valid segments
        int remaining = s.length() - start;
        int segmentsLeft = 4 - current.size();
        
        if (remaining < segmentsLeft || remaining > segmentsLeft * 3) {
            return;
        }
        
        if (current.size() == 4) {
            if (start == s.length()) {
                result.push_back(current[0] + "." + current[1] + "." + 
                                 current[2] + "." + current[3]);
            }
            return;
        }
        
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.length()) break;
            
            string segment = s.substr(start, len);
            
            if (len > 1 && segment[0] == '0') continue;
            
            int value = stoi(segment);
            if (value > 255) continue;
            
            current.push_back(segment);
            backtrack(s, start + len, current, result);
            current.pop_back();
        }
    }
};
