// Question Link - https://leetcode.com/problems/intersection-of-two-arrays-ii/

// Solution - 

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size())
            return intersect(nums2, nums1);
        unordered_map<int, int>um1, um2;
        for(int each : nums1)
            um1[each]++;
        for(int each : nums2)
            um2[each]++;
        
        vector<int>ans;
        for(auto each : um1){
            int ele = each.first;
            if(um2.find(ele) != um2.end()){
                int times = min(um1[ele], um2[ele]);
                while(times--)
                    ans.push_back(ele);
            }
        }
        return ans;
    }
};
