// Question Link - https://leetcode.com/problems/sign-of-the-product-of-an-array/

// Solution - 

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size(), neg = 0, isZero = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < 0)
                neg ++;
            else if(nums[i] == 0)
                isZero = 1;
        }
        if(isZero)
            return 0;
        if(neg%2 == 0)
            return 1;
        return -1;
    }
};
