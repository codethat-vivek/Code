// Question Link - https://leetcode.com/problems/daily-temperatures/

// Solution - 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>>st;
        vector<int>ans(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){
            if(st.empty() || temperatures[i] <= st.top().first)
                st.push({temperatures[i], i});
            else{
                while(!st.empty() && st.top().first < temperatures[i]){
                    ans[st.top().second] = i-st.top().second;
                    st.pop();
                }
                st.push({temperatures[i], i});
            }
        }
        return ans;
    }
};
