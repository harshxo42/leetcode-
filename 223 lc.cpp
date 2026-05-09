class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, 
                    int bx1, int by1, int bx2, int by2) {
        
        // Calculate area of first rectangle
        int area1 = (ax2 - ax1) * (ay2 - ay1);
        
        // Calculate area of second rectangle
        int area2 = (bx2 - bx1) * (by2 - by1);
        
        // Calculate overlap
        int overlap_width = min(ax2, bx2) - max(ax1, bx1);
        int overlap_height = min(ay2, by2) - max(ay1, by1);
        
        int overlap_area = 0;
        
        // If there is overlap (both dimensions positive)
        if (overlap_width > 0 && overlap_height > 0) {
            overlap_area = overlap_width * overlap_height;
        }
        
        // Total area = sum of areas - overlap
        return area1 + area2 - overlap_area;
    }
};
