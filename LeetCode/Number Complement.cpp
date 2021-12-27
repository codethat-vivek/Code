// Question Link - https://leetcode.com/problems/number-complement/

// Solution - 

class Solution {
public:
    int findComplement(int n) {
        int ans = n;
        int num = 1;
        int bits = 32 - __builtin_clz(n);
        for(int i=0; i<bits; i++){
            ans = (ans^num);
            num = (num<<1);
        }
        return ans;
    }
};
