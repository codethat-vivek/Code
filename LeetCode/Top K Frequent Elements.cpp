// Question Link - https://leetcode.com/problems/top-k-frequent-elements/

// Solution - 

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>um;
        for(auto x : nums)
            um[x]++;
        priority_queue<pair<int, int>>pq;
        for(auto x : um)
            pq.push(make_pair(x.second, x.first));
        vector<int>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};
