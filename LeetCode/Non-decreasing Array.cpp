// Question Link - https://leetcode.com/problems/non-decreasing-array/

// Solution - 

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int dec = 0, n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] < nums[i-1]){
                dec++;
                if(dec == 1){
                    if(i+1<n && nums[i+1] < nums[i-1] && i-2 >= 0 && nums[i-2] > nums[i])
                        return false;
                }
            }
            if(dec == 2)return false;
        }
        return true;
    }
};
