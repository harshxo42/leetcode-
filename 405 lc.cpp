#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        
        unsigned int n = num; // treat as unsigned for two's complement
        string hexDigits = "0123456789abcdef";
        string result = "";
        
        while (n > 0) {
            int last4bits = n & 0xF; // get last 4 bits
            result += hexDigits[last4bits];
            n >>= 4; // shift right by 4 bits
        }
        
        // result is in reverse order (least significant digit first)
        reverse(result.begin(), result.end());
        return result;
    }
};
