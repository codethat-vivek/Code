// Question Link - https://leetcode.com/problems/search-insert-position/

// Solution - 

class Solution {
public:
    int bs(vector<int>nums, int start, int end, int target){
        int mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return start;
    }
    int searchInsert(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target);
    }
};
