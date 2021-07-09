// Question Link - https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// Solution - 

class Solution {
public:
    
    int binarySearch(vector<int>arr, int low, int high){
        int mid;
        int n = high+1;
        int next, prev;
        if(arr[low] < arr[high])
            return arr[low];
        while(low <= high){
            mid = low + (high - low)/2;
            next = (mid+1)%n;
            prev = (mid+n-1)%n;
            if(arr[mid] < arr[next] && arr[mid] < arr[prev])
                return arr[mid];
            else if(arr[mid] < arr[high])
                high = mid-1;
            else
                low = mid+1;
            
        }
        return arr[low];
    }
    
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return min(nums[0], nums[1]);
        return binarySearch(nums, 0, n-1);
    }
};
