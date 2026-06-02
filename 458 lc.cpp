#include <cmath>
#include <algorithm>

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;
        
        // Find smallest p such that states^p >= buckets
        int pigs = 0;
        long long maxBuckets = 1;
        
        while (maxBuckets < buckets) {
            maxBuckets *= states;
            pigs++;
        }
        
        return pigs;
    }
};
