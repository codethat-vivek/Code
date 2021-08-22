// Question Link  -https://leetcode.com/problems/split-array-largest-sum/

// Solution - 

class Solution {
public:
    // https://www.youtube.com/watch?v=2JSQIhPcHQg 
    // This question is same as -> allocate minimum number of pages 
    bool isPossible(vector<int>nums, int mid, int k){
        int sm = 0;
        int subarrays = 1;
        for(int i=0; i<nums.size(); i++){
            sm += nums[i];
            if(sm > mid){
                subarrays++;
                sm = nums[i];
            }
            if(subarrays > k)
                return false;
        }
        return true;
    }
    
    int BS(vector<int>nums, int start, int end, int k){
        int mid;
        int res;
        while(start <= end){
            mid = start + (end - start)/2;
            if(isPossible(nums, mid, k)){
                res = mid;
                //cout << res << " ";
                end = mid-1;
            }
            else
                start = mid+1; 
        }
        return res;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sm = 0;
        int mx = INT_MIN;
        for(auto each : nums){
            sm += each;
            mx = max(mx, each);
        }
        int idx = BS(nums, mx, sm, k);
        return idx;
    }
};
