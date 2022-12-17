// Question Link - https://leetcode.com/problems/frog-jump-ii/

// Solution - 

class Solution {
public:
    
    bool isPossible(vector<int>&stones, int jump){
        int n = stones.size();
        int start = 0;
        vector<bool>vis(n, false);
        for(int i=1; i<n; i++){
            vis[start] = true;
            if(stones[i] - stones[i-1] > jump)return false;
            int d = stones[i] - stones[start];
            if(d < jump)continue;
            if(d == jump){
                start = i;
                continue;
            }
            start = i-1;
        }
        vis[start] = true;
        vis[0] = false;
        
        start = n-1;
        int lastValid = n-1;
        for(int i=n-2; i>=0; i--){
            if(vis[i])continue;
            int d = stones[start] - stones[i];
            if(d > jump){
                start = lastValid;
                if(stones[start] - stones[i] > jump)return false;
            }
            if(d == jump)
                start = i;
            lastValid = i;
        }
        
        return true;
    }
    
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int low = INT_MAX, high = stones[n-1], ans;
        for(int i=1; i<n; i++) low = min(low, stones[i]-stones[i-1]);
        while(low <= high){
            int mid = low + (high - low)/2;
            cout << "mid = " << mid << endl;
            if(isPossible(stones, mid)){
                ans = mid;
                high = mid-1;
            }
            else
                low = mid+1;
                
        }
        return ans;
    }
};
