// Question Link - https://leetcode.com/problems/remove-stones-to-minimize-the-total/

// Solution - 

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq; // max heap
        for(auto each : piles)
            pq.push(each);
        while(k--){
            int ele = pq.top();
            pq.pop();
            pq.push(ele - ele/2);
        }
        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
