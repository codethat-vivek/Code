// Question Link - https://leetcode.com/problems/climbing-stairs/

// Solution Link - https://leetcode.com/submissions/detail/445180535/

// SOLUTION - 

class Solution {
public:
    int climbStairs(int n) {
        int a=1, b=2, c;
        if(n == 1)
            return 1;
        else{
            for(int i=3; i<=n; i++){
                c = a+b;
                a = b;
                b = c;
            }
        }
        return b;
    }
};
