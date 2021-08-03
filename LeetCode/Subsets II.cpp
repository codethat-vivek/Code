// Question Link - https://leetcode.com/problems/subsets-ii/

// Solution - 

class Solution {
public:
    vector<int> addAll(vector<int>a, vector<int>b){
        for(auto x : b){
            a.push_back(x);
        }
        return a;
    }
    vector<vector<int>> create(vector<int>nums, int idx){
        vector<vector<int>> ans;
        if(idx < 0)
            return {{}};
        
        else{
            ans = create(nums, idx-1);
            int ele = nums[idx];
            vector<vector<int>> more;
            for(vector<int> x : ans){
                vector<int> newlist;
                newlist = addAll(newlist, x);
                newlist.push_back(ele);
                more.push_back(newlist);
            }
            for(auto each : more)
                ans.push_back(each);
        }
        return ans;
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>> res =  create(nums, nums.size()-1);
        for(auto each : res){
            sort(each.begin(), each.end());
            st.insert(each);
        }
        vector<vector<int>> ans;
        for(auto each : st){
            ans.push_back(each);
        }
        return ans;
    }
};
