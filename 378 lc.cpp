class Solution {
public:
    int kthSmallest(std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countLessOrEqual(matrix, mid);
            
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    
private:
    int countLessOrEqual(const std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix.size();
        int i = n - 1, j = 0;  // start at bottom-left
        int count = 0;
        
        while (i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                count += i + 1;  // all elements above in this column are ≤ target
                j++;  // move right to next column
            } else {
                i--;  // move up to find smaller elements
            }
        }
        return count;
    }
};
