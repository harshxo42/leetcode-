class Solution {
public:
    string reverseWords(string s) {
        int start = 0;
        int n = s.length();
        
        for (int i = 0; i <= n; i++) {
            // When we hit a space or end of string, reverse the word
            if (i == n || s[i] == ' ') {
                // Reverse the word from start to i-1
                int left = start;
                int right = i - 1;
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                // Update start to the next word
                start = i + 1;
            }
        }
        
        return s;
    }
};
