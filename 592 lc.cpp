#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0, den = 1; // result starts as 0/1
        
        int i = 0;
        int n = expression.size();
        
        while (i < n) {
            // Determine sign
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '+') ? 1 : -1;
                i++;
            }
            
            // Parse numerator
            int numerator = 0;
            while (i < n && isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i] - '0');
                i++;
            }
            numerator *= sign;
            
            // Skip '/'
            i++;
            
            // Parse denominator
            int denominator = 0;
            while (i < n && isdigit(expression[i])) {
                denominator = denominator * 10 + (expression[i] - '0');
                i++;
            }
            
            // Add to result: num/den + numerator/denominator
            // = (num*denominator + numerator*den) / (den*denominator)
            int new_num = num * denominator + numerator * den;
            int new_den = den * denominator;
            
            // Reduce immediately to avoid overflow (though not required per constraints)
            int g = gcd(abs(new_num), new_den);
            num = new_num / g;
            den = new_den / g;
        }
        
        return to_string(num) + "/" + to_string(den);
    }
    
private:
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};
