// Question Link - https://leetcode.com/problems/k-diff-pairs-in-an-array/

// Solution - 

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        if(k == 0){
            unordered_map<int, int>um;
            for(int e : nums)
                um[e]++;
            for(auto it = um.begin(); it != um.end(); ++it){
                if(it -> second >= 2)ans++;
            }
            return ans;
            
        }
        unordered_set<int>seen, exists;
        for(int each : nums)
            exists.insert(each);
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++){
            if(seen.find(nums[i]) != seen.end())continue;
            seen.insert(nums[i]);
            if(exists.find(nums[i]+k) != exists.end())ans++;
        }
        return ans;
    }
};
