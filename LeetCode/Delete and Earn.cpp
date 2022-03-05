// Question Link - https://leetcode.com/problems/delete-and-earn/

// Solution - 

class Solution {
public:
    
    int helper(vector<int>arr, unordered_map<int, int>&um, int idx, vector<int>&memo){
        if(idx >= arr.size())
            return 0;
        
        //checking if idx is already present in memo
        if(memo[idx] != -1)
            return memo[idx];
        
        // if you are taking nums[idx]
        int fixedGain = arr[idx] * um[arr[idx]];
        int possible;
        
        if(um.find(arr[idx]+1) != um.end())
            possible = fixedGain + helper(arr, um, idx+2, memo);
        else
            possible = fixedGain + helper(arr, um, idx+1, memo);
        
        // if you are not taking nums[idx] and skipping it
        int skip = helper(arr, um, idx+1, memo);
        
        return memo[idx] = max(skip, possible);
            
            
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
        unordered_map<int, int>um;
        for(int each : nums)
            um[each]++;
        
        set<int>st;
        for(int ele : nums)
            st.insert(ele);
        
        vector<int>arr(st.begin(), st.end());
        sort(arr.begin(), arr.end());
        
        vector<int>memo(arr.size(), -1);
        
        return helper(arr, um, 0, memo);
        
    }
};
