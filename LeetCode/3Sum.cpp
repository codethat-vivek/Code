// Question Link - https://leetcode.com/problems/3sum/

// Solution - 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 3)
            return {};
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while (j < k){
                int sm = nums[i]+nums[j]+nums[k];
                if(sm == 0){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;k--;
                }
                else if(sm < 0)
                    j++;
                else if(sm > 0)
                    k--;
            }
        }
        for(auto x : s)
            ans.push_back(x);
        return ans;
    }
};
