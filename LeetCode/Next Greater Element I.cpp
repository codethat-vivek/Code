// Question Link - https://leetcode.com/problems/next-greater-element-i/

// Solution - 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // since nums1[i] and nums2[i] contain UNIQUE values;
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2 == 1)
            return {-1};
        
        vector<int>ans;
        stack<int>st;
        unordered_map<int, int>um;
        st.push(nums2[0]);
        for(int i=1; i<n2; i++){
            while(!st.empty() && st.top() < nums2[i]){
                um[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        
        while(!st.empty()){
            um[st.top()] = -1;
            st.pop();
        }
        
        for(auto x : nums1)
            ans.push_back(um[x]);
        
        return ans;
    }
};
