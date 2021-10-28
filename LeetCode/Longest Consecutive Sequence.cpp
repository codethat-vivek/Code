// Question Link - https://leetcode.com/problems/longest-consecutive-sequence/

// Solution - 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int>um;
        unordered_set<int>us;
        for(int x : nums){
            um[x] = 1;
            us.insert(x);
        }
        
        for(auto x : us){
            if(um.find(x-1) != um.end())
                um[x] = 0;
        }
        int ans = 0;
        vector<int>v;
        for(auto x : um){
            if(x.second == 1)
                v.push_back(x.first);
        }
        
        for(auto x : v){
            int ele = x;
            int cnt = 0;
            while(us.find(ele) != us.end()){
                cnt++;
                ele++;
            }
            ans = max(ans, cnt);
        }
        
        return ans;
        
    }
};
