// Question Link - https://leetcode.com/problems/the-employee-that-worked-on-the-longest-task/

// Solution - 

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int mx = logs[0][1];
        int id = logs[0][0];
        for(int i=1; i<logs.size(); i++){
            if(mx < logs[i][1] - logs[i-1][1]){
                mx = logs[i][1] - logs[i-1][1];
                id = logs[i][0];
            }
            else if(mx == logs[i][1] - logs[i-1][1])
                id = min(id, logs[i][0]);
            
        }
        return id;
    }
};
