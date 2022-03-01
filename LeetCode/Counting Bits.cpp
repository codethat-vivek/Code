// Question Link - https://leetcode.com/problems/counting-bits/

// Solution - 

class Solution {
public:
    int countNumberOfBits(int n){
        int cnt = 0;
        long long int bit = 1;
        for(int i=0; i<32; i++){
            if((n&bit) != 0)cnt++;
            bit <<= 1;
        }
        return cnt;
    }
    
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0; i<=n; i++)
            ans.push_back(countNumberOfBits(i));
        return ans;
        
    }
};
