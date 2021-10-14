// Question Link - https://leetcode.com/problems/search-in-rotated-sorted-array/

// SOLUTION - O(log n)

class Solution {
public:
    
    int findPivot(vector<int>v, int start, int end){
        int mid, n = v.size();
        while(start <= end){
            mid = start + (end - start)/2;
            if(mid == 0){
                if(v[0] > v[1])
                    return 1;
                return 0;
            }
            if(mid == n-1){
                if(v[n-1] < v[n-2])
                    return n-1;
                return 0;
            }
            if(v[mid] < v[mid-1] && v[mid] < v[mid+1])
                return mid;
            else if(v[mid] < v[0])
                end = mid-1;
            else
                start = mid+1;
        }
        return -1;
    }
    
   int bs(vector<int>v, int k, int start, int end){
        while(start <= end){
            int mid = start + (end - start)/2; // to avoid overflows
            if(v[mid] == k)
                return mid;
            else if(v[mid] < k)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1; // not found condition
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 1){
            if(nums[0] == target)
                return 0;
            return -1;
        }
        int pivotIndex = findPivot(nums, 0, n-1);
        //cout << pivotIndex << endl;
        if(nums[pivotIndex] == target)
            return pivotIndex;
        
        int x = bs(nums, target, pivotIndex, n-1);
        int y = bs(nums, target, 0, pivotIndex);
        if(x == -1)
            return y;
        return x;
    }
};

/*
ANOTHER POSSIBLE SOLUTION (BINARY SEARCH IN ONE GO)
class Solution {
public:
    int modifiedBinarySearch(vector<int>nums, int start, int end, int target){
        if(start > end) return -1;
        int mid = start + (end - start)/2;
        //cout << mid << endl;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] >= nums[start]) // left part is sorted 
        {
            if(nums[start] <= target && target <= nums[mid])
                return modifiedBinarySearch(nums, start, mid-1, target);
            return modifiedBinarySearch(nums, mid+1, end, target);
        }
        else // right part is sorted
        {
            if(nums[mid] <= target && target <= nums[end])
                return modifiedBinarySearch(nums, mid+1, end, target);
            return modifiedBinarySearch(nums, start, mid-1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return modifiedBinarySearch(nums, 0, nums.size()-1, target);
    }
};

*/
