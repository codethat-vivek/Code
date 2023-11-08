// Question Link - https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/

// Solution - 

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy)
            return t != 1;
        return t >= max(abs(fx-sx), abs(fy-sy));
    }
};
