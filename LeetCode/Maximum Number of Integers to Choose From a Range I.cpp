// Question Link - https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/

// Solution - 

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int b = banned.size(), mx = -1;
        vector<int>vis(10001, 0);
        for(int i=0; i<b; i++){
            vis[banned[i]] = 1;
            mx = max(mx, banned[i]);
        }
        
        
        int ans = 0;
        long long int sm = 0;
        for(int i=1; i<=n; i++){
            if(vis[i] == 0 && sm + i <= maxSum){
                ans++;
                sm += i;
            }
                
        }
        
        return ans;
    }
};
