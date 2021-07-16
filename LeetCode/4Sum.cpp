// Question Link - https://leetcode.com/problems/4sum/

// Solution - 

class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>nums, int n, int start, int target) {
        if(n < 3)
            return {};
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=start; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while (j < k){
                int sm = nums[i]+nums[j]+nums[k];
                if(sm == target){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;k--;
                }
                else if(sm < target)
                    j++;
                else if(sm > target)
                    k--;
            }
        }
        for(auto x : s)
            ans.push_back(x);
        return ans;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int ele, n = nums.size();
        if(n < 4)
            return {};
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        set<vector<int>>s;
        for(int i=0; i<n-3; i++){
            ele = nums[i];
            vector<vector<int>>temp = threeSum(nums, n, i+1, target-ele);
            for(auto x : temp){
                x.push_back(ele);
                s.insert(x);
            }
        }
        for(auto ss : s){
            ans.push_back(ss);
        }
        return ans;
    }
};
