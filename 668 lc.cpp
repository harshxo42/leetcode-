class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        
        auto countLessEqual = [&](int x) {
            int cnt = 0;
            for (int i = 1; i <= m; i++) {
                cnt += min(n, x / i);
            }
            return cnt;
        };
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (countLessEqual(mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
