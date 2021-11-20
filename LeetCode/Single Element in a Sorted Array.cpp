// Question Link - https://leetcode.com/problems/single-element-in-a-sorted-array/

// Solution - 

class Solution {
public:
    //int bs(vector<int>&nums, int start, int end)
    int singleNonDuplicate(vector<int>& nums) {
        /*
        [1,1,2,2,3,3,4,4,8,8]
        [0,1,2,3,4,5,6,7,8,9]
         ^   ^   ^   ^   ^
        */
        int n = nums.size();
        if(n == 1) return nums[0];
        int start = 0, end = n-1;
        while(start <= end){
            int mid = start + (end - start)/2;
            int prev = nums[(mid+n-1)%n], next = nums[(mid+1)%n];
            if(nums[mid] != prev && nums[mid] != next)
                return nums[mid];
            if(mid & 1){// odd
                if(nums[mid-1] != nums[mid]){
                    // we check on left side
                    end = mid-1;
                }
                else{
                    // we check on right side
                    start = mid+1;
                }
            }
            else{
                if(nums[mid] != nums[mid+1]){
                    // we check on left side
                    end = mid-1;
                }
                else{
                    // we check on right side
                    start = mid+1;
                }
            }
        }
        return -1;
    }
};
