// Question Link - https://leetcode.com/problems/find-peak-element/

// Solution - 

class Solution {
public:
    
    int binarySearch(vector<int>arr, int low, int high){
        int mid;
        int n = arr.size();
        while(low <= high){
            mid = low + (high - low)/2;
            if(mid == 0){
                if(arr[0] > arr[1])
                    return 0;
                else
                    return 1;
            }
            if(mid == n-1){
                if(arr[mid] > arr[mid-1])
                    return n-1;
                else
                    return n-2;
            }
            if(arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid] < arr[mid-1])
                high = mid;
            else if(arr[mid] < arr[mid+1])
                low = mid+1;
            
        }
        return low;
    }
    
    int findPeakElement(vector<int>& nums) {
    // This is cool. We can actually binary search in nums array even if it is not sorted.
        int n = nums.size();
        if(n == 1)
            return 0;
        // if(n == 2){
        //     if(nums[0] > nums[1])
        //         return 0;
        //     return 1;
        // }
            
        return binarySearch(nums, 0, nums.size()-1);
        
    }
};
