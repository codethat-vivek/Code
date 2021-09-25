// Question Link - https://leetcode.com/problems/increasing-triplet-subsequence/

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
    
    int lis(vector<int>&nums){
        int n = nums.size();
        vector<int>v;
        v.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(v[v.size()-1] < nums[i])
                v.push_back(nums[i]);
            else if(v[v.size()-1] > nums[i]){
                int idx = bs(v, 0, v.size()-1, nums[i]);
                v[idx] = nums[i];
            }
        }
        return v.size();
    }
    
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)return false;
        // one method could be to implement LIS then see if it's >= 3
        int len = lis(nums);
        cout << len << endl;
        return len >= 3;
    }
};
