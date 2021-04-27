// Question Link - https://leetcode.com/problems/majority-element-ii/

// Solution Link - https://leetcode.com/submissions/detail/485705103/

// SOLUTION - 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> um;
        vector<int>ans;
        for(int i=0; i<n; i++){
            um[nums[i]] += 1;
        }
        
        for(auto const &pair : um){
            if(pair.second > n/3){
                ans.push_back(pair.first);
            }
        }
        return ans;
        
    }
};
