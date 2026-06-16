class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find('=');
        string left = equation.substr(0, pos);
        string right = equation.substr(pos + 1);
        
        int coeff = 0;  // coefficient of x
        int constant = 0; // constant term
        
        // Parse left side: add terms as they are
        parseExpression(left, coeff, constant, 1);
        
        // Parse right side: subtract terms (move to left)
        parseExpression(right, coeff, constant, -1);
        
        // coeff * x + constant = 0
        // x = -constant / coeff
        
        if (coeff == 0) {
            if (constant == 0) {
                return "Infinite solutions";
            } else {
                return "No solution";
            }
        }
        
        int result = -constant / coeff;
        return "x=" + to_string(result);
    }
    
private:
    void parseExpression(string expr, int& coeff, int& constant, int sign) {
        int i = 0;
        int n = expr.length();
        
        while (i < n) {
            int curSign = 1;
            if (expr[i] == '+') {
                i++;
            } else if (expr[i] == '-') {
                curSign = -1;
                i++;
            }
            
            // Now we have a number, possibly with 'x'
            int num = 0;
            bool hasNum = false;
            
            while (i < n && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                hasNum = true;
                i++;
            }
            
            // Check if it's an 'x' term
            if (i < n && expr[i] == 'x') {
                // It's an x term
                if (!hasNum) {
                    num = 1; // implicit coefficient
                }
                coeff += sign * curSign * num;
                i++; // skip 'x'
            } else {
                // It's a constant
                if (!hasNum) {
                    // This shouldn't happen for valid input, but just in case
                    num = 0;
                }
                constant += sign * curSign * num;
            }
        }
    }
};
