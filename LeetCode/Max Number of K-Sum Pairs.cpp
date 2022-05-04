// Question Link - https://leetcode.com/problems/max-number-of-k-sum-pairs/

// Solution - 

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int l=0, r=nums.size()-1;
        int removals = 0;
        while(l < r){
            int sm = nums[l]+nums[r];
            if(sm == k){
                removals++;
                l++;
                r--;
            }
            else if(sm > k)
                r--;
            else
                l++;
        }
        return removals;
    }
};
