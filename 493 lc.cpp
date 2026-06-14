class Solution {
private:
    int count = 0;
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        // Create temporary arrays for left and right halves
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        vector<int> leftArr(n1), rightArr(n2);
        
        // Copy data to temporary arrays
        for (int i = 0; i < n1; i++)
            leftArr[i] = nums[left + i];
        for (int j = 0; j < n2; j++)
            rightArr[j] = nums[mid + 1 + j];
        
        // Count reverse pairs before merging
        int j = 0;
        for (int i = 0; i < n1; i++) {
            while (j < n2 && leftArr[i] > 2LL * rightArr[j]) {
                j++;
            }
            count += j;
        }
        
        // Merge the temporary arrays back into nums[left..right]
        int i = 0;
        j = 0;
        int k = left;
        
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                nums[k] = leftArr[i];
                i++;
            } else {
                nums[k] = rightArr[j];
                j++;
            }
            k++;
        }
        
        // Copy remaining elements
        while (i < n1) {
            nums[k] = leftArr[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            nums[k] = rightArr[j];
            j++;
            k++;
        }
    }
    
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            // Sort left and right halves
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);
            
            // Count reverse pairs across the halves and merge
            merge(nums, left, mid, right);
        }
    }
    
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        
        count = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};
