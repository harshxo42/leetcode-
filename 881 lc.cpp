#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0;
        int right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                // Pair the lightest and heaviest
                left++;
                right--;
            } else {
                // Heaviest goes alone
                right--;
            }
            boats++;
        }
        
        return boats;
    }
};
