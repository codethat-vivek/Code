// Question Link - https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/

// Solution - 

#define pii pair<int, int>

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size(), pIdx, nIdx;
        priority_queue <pii, vector<pii>, greater<pii>> pq;
        for(int i=0; i<n; i++)
            pq.push({nums[i], i});
        vector<int>visited(n, 0);
        long long ans = 0;
        while(!pq.empty()){
            pii top = pq.top();
            pq.pop();
            if(!visited[top.second]){
                ans += top.first;
                pIdx = top.second-1;
                nIdx = top.second+1;
                if(pIdx >= 0)visited[pIdx] = 1;
                if(nIdx < n) visited[nIdx] = 1;
            }
        }
        return ans;
    }
};
