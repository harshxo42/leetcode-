/** 
 * Forward declaration of guess API.
 * @param num your guess
 * @return -1 if num is higher than the picked number
 *          1 if num is lower than the picked number
 *          0 if num is equal to the picked number
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = n;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int result = guess(mid);
            
            if (result == 0) {
                return mid;
            } else if (result == -1) {
                high = mid - 1;  // mid is too high
            } else {
                low = mid + 1;   // mid is too low
            }
        }
        
        return -1; // Should never reach here
    }
};
