#include <vector>
#include <queue>
#include <tuple>

class Solution {
public:
    std::vector<std::vector<int>> kSmallestPairs(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<std::vector<int>> result;
        
        if (nums1.empty() || nums2.empty() || k == 0) {
            return result;
        }
        
        // Min-heap: (sum, index1, index2)
        // Using a lambda for custom comparison
        auto cmp = [](const std::tuple<int, int, int>& a, 
                      const std::tuple<int, int, int>& b) {
            return std::get<0>(a) > std::get<0>(b);  // Min-heap based on sum
        };
        
        std::priority_queue<std::tuple<int, int, int>, 
                           std::vector<std::tuple<int, int, int>>, 
                           decltype(cmp)> heap(cmp);
        
        // Push the first min(k, nums1.size()) pairs (nums1[i], nums2[0])
        for (int i = 0; i < std::min(k, (int)nums1.size()); i++) {
            heap.push({nums1[i] + nums2[0], i, 0});
        }
        
        // Get k smallest pairs
        while (!heap.empty() && result.size() < k) {
            auto [sum, i, j] = heap.top();
            heap.pop();
            
            result.push_back({nums1[i], nums2[j]});
            
            // If we can move j pointer forward, push the next pair
            if (j + 1 < nums2.size()) {
                heap.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }
        
        return result;
    }
};
