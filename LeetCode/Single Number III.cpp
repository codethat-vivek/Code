// Question Link - https://leetcode.com/problems/single-number-iii/

// Solution -

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int ele : nums)
            xorr ^= ele;
        
        int i=0;
        while((xorr & (1<<i)) == 0)
            i++;
        
        int newXorr = 0;
        for(int ele : nums){
            if(ele & (1<<i)){
                
                newXorr ^= ele;
            }
        }
        
        return {newXorr, xorr^newXorr};
    }
};
