// Question Link - https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/

// Solution - 

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size(), idx=0;
        stack<int>st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(nums[i]);
                idx++;
            }
            else{
                if(nums[i] == st.top() && idx%2 != 0)
                    continue;
                st.push(nums[i]);
                idx++;
            }
            
        }
        if (st.size() % 2 == 0)
            return n-st.size();
        else
            return n-st.size()+1;
        
    }
};
