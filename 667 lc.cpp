#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        // First k+1 elements
        int l = 1, r = k + 1;
        for (int i = 0; i <= k; i++) {
            if (i % 2 == 0) {
                ans[i] = l++;
            } else {
                ans[i] = r--;
            }
        }
        // Fill remaining elements
        for (int i = k + 1; i < n; i++) {
            ans[i] = i + 1; // increasing from k+2 to n
        }
        return ans;
    }
};
