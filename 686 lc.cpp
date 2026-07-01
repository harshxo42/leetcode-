#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        // Step 1: Check if all characters of b are in a
        for (char c : b) {
            if (a.find(c) == string::npos) {
                return -1;
            }
        }
        
        // Step 2: Base minimum repetitions needed
        int minReps = (b.length() + a.length() - 1) / a.length();
        
        // Step 3: Try minReps, minReps+1, minReps+2
        for (int reps = minReps; reps <= minReps + 2; reps++) {
            string repeated = "";
            for (int i = 0; i < reps; i++) {
                repeated += a;
            }
            if (repeated.find(b) != string::npos) {
                return reps;
            }
        }
        
        // Step 4: If not found, return -1
        return -1;
    }
};
