class Solution {
public:
    int longestSubstring(string s, int k) {
        return helper(s, 0, s.length() - 1, k);
    }
    
private:
    int helper(string& s, int start, int end, int k) {
        // Base case: if the segment is too short
        if (end - start + 1 < k) {
            return 0;
        }
        
        // Count frequency of each character in the current segment
        vector<int> freq(26, 0);
        for (int i = start; i <= end; i++) {
            freq[s[i] - 'a']++;
        }
        
        // Find the first invalid character (count < k)
        for (int i = start; i <= end; i++) {
            if (freq[s[i] - 'a'] < k) {
                // Split at this invalid character and check left and right parts
                int left = helper(s, start, i - 1, k);
                int right = helper(s, i + 1, end, k);
                return max(left, right);
            }
        }
        
        // If all characters appear at least k times, return the full length
        return end - start + 1;
    }
};
