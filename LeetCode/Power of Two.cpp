// Question Link - https://leetcode.com/problems/power-of-two/

// Solution - 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long i = 1;
        while(i < n){
            i = (i << 1);
        }
        return i == n ? true : false;
    }
};
// What is wrong here
/*
        int i = 1;
        while(i < n){
            i = (i << 1);
        }
        return i == n ? true : false;

*/
/*
Line 6: Char 20: runtime error: left shift of negative value -2147483648 (solution.cpp)
UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:15:20
*/
