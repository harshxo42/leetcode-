#include <string>
#include <sstream>

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // Parse first complex number
        int real1, imag1;
        parseComplex(num1, real1, imag1);
        
        // Parse second complex number
        int real2, imag2;
        parseComplex(num2, real2, imag2);
        
        // Multiply: (a+bi)(c+di) = (ac-bd) + (ad+bc)i
        int realPart = real1 * real2 - imag1 * imag2;
        int imagPart = real1 * imag2 + imag1 * real2;
        
        // Return result in required format
        return to_string(realPart) + "+" + to_string(imagPart) + "i";
    }
    
private:
    void parseComplex(const string& num, int& real, int& imag) {
        // Find the position of '+'
        size_t plusPos = num.find('+');
        
        // Extract real part
        string realStr = num.substr(0, plusPos);
        real = stoi(realStr);
        
        // Extract imaginary part (remove the trailing 'i')
        string imagStr = num.substr(plusPos + 1);
        imagStr = imagStr.substr(0, imagStr.length() - 1); // Remove 'i'
        imag = stoi(imagStr);
    }
};
