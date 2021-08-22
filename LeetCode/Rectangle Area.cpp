// Question Link - https://leetcode.com/problems/rectangle-area/

// Solution - 

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs(ax1-ax2)*abs(ay1-ay2);
        int area2 = abs(bx1-bx2)*abs(by1-by2);
        
        int l = min(bx2, ax2) - max(ax1, bx1);
        int b = min(by2, ay2) - max(ay1, by1);
        
        if(l < 0 || b < 0)
            return area1+area2;
        return area1+area2-l*b;
        
    }
};
