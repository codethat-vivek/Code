// Question Link - https://leetcode.com/problems/take-gifts-from-the-richest-pile/

// Solution - 

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int>pq;
        for(int g : gifts)
            pq.push(g);
        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(int(sqrt(top)));
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        
        return ans;
    }
};
