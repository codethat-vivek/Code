// Question Link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// SOLUTION - 

class Solution {
public:
    bool bs(vector<int>nums, int start, int end, int target){
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return true;
            if(nums[start] == nums[mid] && nums[mid] == nums[end]){
                // with duplicates we can have this contdition, just update left & right
                start++;
                end--;
            }
            else if(nums[start] <= nums[mid]){// first half is in order
                if(nums[start] <= target && target < nums[mid])
                    end = mid-1;
                else
                    start = mid+1;
            }
            else{// second half is in order
                if(nums[mid] < target && target <= nums[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return bs(nums, 0, nums.size()-1, target);
    }
};
