#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        const int MOD = 1e9 + 7;
        
        // Calculate LCM
        long long lcm = (1LL * a / gcd(a, b)) * b;
        
        // Binary search for the nth magical number
        long long low = 1, high = 1LL * min(a, b) * n;
        
        while (low < high) {
            long long mid = low + (high - low) / 2;
            
            // Count of magical numbers <= mid
            long long count = mid / a + mid / b - mid / lcm;
            
            if (count >= n) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        return low % MOD;
    }
};
