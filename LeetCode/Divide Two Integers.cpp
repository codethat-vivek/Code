// Question Link - https://leetcode.com/problems/divide-two-integers/

// Solution - 

class Solution {
public:
    int divide(int dividend, int divisor) {
        // HARD PROBLEM
        // For ex - dividend = 19, divisor = 3, expected answer = 6
        // 19 > 3 so 19 > 6 so 19 > 12 but 19 < 24, Therefore...
        // new dividend = 19 - 12 = 7
        // 7 > 3 so 7 > 6 but 7 < 12, Therefore...
        // new dividend = 7 - 6 = 1
        // 1 < 3
        // So final answer is the number of times these iterations went...
        // 1/2/4 = 4 Then 1/2 = 2. So final answer = 4+2 = 6
        
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        long dvd = labs(dividend), dvr = labs(divisor), ans = 0;
        
        while (dvd >= dvr) {
            long temp = dvr, subAns = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                subAns <<= 1;
            }
            dvd -= temp;
            ans += subAns;
        }
        cout << ans << endl;
        return sign * ans;
        
    }
};
