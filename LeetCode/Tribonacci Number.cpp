// Question Link - https://leetcode.com/problems/n-th-tribonacci-number/

// Solution Details - https://leetcode.com/submissions/detail/445147234/

// SOLUTION - 

class Solution {
public:
    int tribonacci(int n) {
        int a = 0, b = 1, c = 1, d;
        // T(n+3) = T(n) + T(n+1) + T(n+2)
        if(n == 0)
            return a;
        else if(n == 1)
            return b;
        else{
            for(int i=3; i<=n; i++){
                d = a+b+c;
                a = b;
                b = c;
                c = d;
            }
        }
        return c;
    }
};
