// Question Link - https://leetcode.com/problems/first-missing-positive/

// Solution - 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        long pos;
        for(int i=0; i<n; i++){
            pos = (long)nums[i]-1;
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[pos]){
                swap(nums[i], nums[pos]);
                pos = nums[i]-1;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
        
    }
};
