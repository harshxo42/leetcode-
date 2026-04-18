class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; i++) {
            // Update heights
            for (int j = 0; j < cols; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            
            // Largest rectangle in histogram for current heights
            stack<int> st;
            for (int j = 0; j <= cols; j++) {
                int currentHeight = (j == cols) ? 0 : heights[j];
                
                while (!st.empty() && currentHeight < heights[st.top()]) {
                    int height = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, height * width);
                }
                st.push(j);
            }
        }
        
        return maxArea;
    }
};
