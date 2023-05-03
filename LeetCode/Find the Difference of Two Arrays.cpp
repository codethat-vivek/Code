// Question Link - https://leetcode.com/problems/find-the-difference-of-two-arrays/

// Solution - 

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>us1, us2;
        for(int e : nums1)
            us1.insert(e);
        for(int e : nums2)
            us2.insert(e);
        
        vector<vector<int>> ans;
        ans.push_back({});
        ans.push_back({});
        for(int e : us1){
            if(us2.find(e) == us2.end())
                ans[0].push_back(e);
        }
        
        for(int e : us2){
            if(us1.find(e) == us1.end())
                ans[1].push_back(e);
        }
        
        return ans;
        
    }
};
