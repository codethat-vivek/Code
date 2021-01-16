// Question Link - https://leetcode.com/problems/reverse-integer/

// Solution Details - https://leetcode.com/submissions/detail/443804254/

// SOLUTION - 

class Solution {
public:
    int reverse(int x) {
        int original = x;
        long r = 0;
        while(x != 0){
            r = r*10 + x%10;
            x = x/10;
        }
        if ( (original > 0 && r > INT_MAX) || (original < 0 && r < INT_MIN) )
            return 0;
        else
            return r;
    }
};
