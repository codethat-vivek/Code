// Question Link - https://leetcode.com/problems/reverse-bits/

// Solution - 

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int p = 31;
        long long ans = 0;
        for(int i=0; i<32; i++){
            if(n & (1<<i))
                ans += pow(2, p);
            p--;
        }
        return ans;
    }
};
