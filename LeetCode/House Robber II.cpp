// Question Link - https://leetcode.com/problems/house-robber-ii/submissions/

// Solution - 

class Solution {
public:
    
    int helper(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int>arr(n, 0);
        arr[0] = nums[0];
        arr[1] = max(nums[0], nums[1]);
        for(int i=2; i<n; i++){
            if(arr[i-2] >= arr[i-1])
                arr[i] = nums[i]+arr[i-2];
            else
                arr[i] = max(nums[i]+arr[i-2], arr[i-1]);
        }
        return arr[n-1];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int last = nums[n-1];
        // choosing the 1st house 
        // this implies we can't choose the last house
        nums.erase(nums.end() - 1);
        int poss = helper(nums);
        
        nums.push_back(last);
        // not choosing the 1st house
        nums.erase(nums.begin());
        int poss1 = helper(nums);
        
        return max(poss, poss1);
        
        
    }
};
