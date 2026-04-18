class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftSmaller(n), rightSmaller(n);
        stack<int> st;
        
        // Find next smaller element on left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            leftSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        // Clear stack for right smaller pass
        while (!st.empty()) st.pop();
        
        // Find next smaller element on right
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            rightSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        // Calculate max area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = rightSmaller[i] - leftSmaller[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        
        return maxArea;
    }
};
