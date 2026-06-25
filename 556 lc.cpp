class Solution {
public:
    int nextGreaterElement(int n) {
        // Convert to string for easy digit manipulation
        string digits = to_string(n);
        int length = digits.length();
        
        // Find the pivot: first digit from right that is smaller than digit to its right
        int pivot = -1;
        for (int i = length - 2; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) {
                pivot = i;
                break;
            }
        }
        
        // If no pivot found, digits are in descending order
        if (pivot == -1) {
            return -1;
        }
        
        // Find the smallest digit to the right of pivot that is greater than digits[pivot]
        // Since digits[pivot+1:] is in descending order, scan from right
        for (int i = length - 1; i > pivot; i--) {
            if (digits[i] > digits[pivot]) {
                swap(digits[i], digits[pivot]);
                break;
            }
        }
        
        // Reverse the suffix after pivot to get ascending order
        reverse(digits.begin() + pivot + 1, digits.end());
        
        // Convert back to integer and check for overflow
        long result = stol(digits);
        if (result > INT_MAX) {
            return -1;
        }
        
        return (int)result;
    }
};
