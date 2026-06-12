class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        
        // pos[j] = index of largest digit from j to end
        vector<int> pos(n);
        pos[n-1] = n-1;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] > s[pos[i+1]]) {
                pos[i] = i;
            } else {
                pos[i] = pos[i+1];
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (s[i] < s[pos[i]]) {
                // swap with the last occurrence of the max digit
                int lastIdx = pos[i];
                // find last occurrence of this max digit
                while (lastIdx + 1 < n && s[lastIdx + 1] == s[pos[i]]) {
                    lastIdx++;
                }
                swap(s[i], s[lastIdx]);
                return stoi(s);
            }
        }
        
        return num;
    }
};
