// Question Link - https://leetcode.com/problems/moving-stones-until-consecutive/

// Solution - 

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if(a > b)swap(a, b);
        if(a > c)swap(a, c);
        if(b > c)swap(b, c);
        //cout << a << " " << b << " " << c << endl;
        int big = c - a - 2;
        if(big == 0)
            return {0, 0};
        if(b - a >= 3 && c - b >= 3)
            return {2, big};
        return {1, big};
    }
};
