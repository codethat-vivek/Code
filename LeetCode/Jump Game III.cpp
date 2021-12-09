// Question Link - https://leetcode.com/problems/jump-game-iii/

// Solution - 

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<pii>q;
        q.push({start, arr[start]}); // {5, 1}
        vector<int>vis(arr.size(), 0);
        vis[start]=1;
        while(!q.empty()){
            int len = q.size();
            while(len--){
                pii top = q.front();
                q.pop();
                //cout << top.first << " " << top.second << endl;
                if(top.second == 0)return true;
                vis[top.first]=1;
                int idx1 = top.first-top.second;
                int idx2 = top.first+top.second;
                if(idx1 >= 0 && !vis[idx1])
                    q.push({idx1, arr[idx1]});
                if(idx2 < arr.size() && !vis[idx2])
                    q.push({idx2, arr[idx2]});
            }
            
        }
        return false;
    }
};
