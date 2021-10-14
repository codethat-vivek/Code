// Question Link - https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// Solution - 

class Solution {
public:
    bool bs(vector<int>nums, int target, int start, int end){
        int mid;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target)
                return true;
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return false;
    }
    int lb(vector<int>nums, int target, int start, int end){
        int mid;
        int ans = INT_MAX;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = min(ans, mid);
                end = mid-1;
            }
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return ans;
    }
    int ub(vector<int>nums, int target, int start, int end){
        int mid;
        int ans = INT_MIN;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = max(ans, mid);
                start = mid+1;
            }
            else if(nums[mid] > target)
                end = mid-1;
            else
                start = mid+1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!bs(nums, target, 0, nums.size()-1))return {-1, -1};
        int l=lb(nums, target, 0, nums.size()-1);
        int u=ub(nums, target, 0, nums.size()-1);
        return {l, u};
    }
};
