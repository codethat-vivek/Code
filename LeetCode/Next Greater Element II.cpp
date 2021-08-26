// Question Link - https://leetcode.com/problems/next-greater-element-ii/

// Solution - 

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>v (nums.begin(), nums.end());
        for(auto each : nums)
            v.push_back(each);
        vector<int>ans(n, -1);
        stack<pair<int, int>>st;
        for(int i=0; i<2*n; i++){
            while(!st.empty() && st.top().first < v[i]){
                if(st.top().second < n)
                    ans[st.top().second] = v[i];
                
                st.pop();
                
            }
            st.push({v[i], i});
        }
        return ans;
    }
};
