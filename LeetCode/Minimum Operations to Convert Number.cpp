// Question Link - https://leetcode.com/problems/minimum-operations-to-convert-number/

// Solution - 

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int operations = 0;
        queue<int>q;
        q.push(start);
        vector<bool>vis(1002, false);
        while(!q.empty()){
            int len = q.size();
            while(len--){
                int t = q.front();
                q.pop();
                if(t == goal)return operations;
                if(t < 0 || t > 1000 || vis[t])continue;
                vis[t] = true;
                for(int ele : nums){
                    q.push(t+ele);
                    q.push(t-ele);
                    q.push(t^ele);
                }
            }
            operations++;
        }
        return -1;
    }
};
