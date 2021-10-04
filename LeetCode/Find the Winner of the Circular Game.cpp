// Question Link - https://leetcode.com/problems/find-the-winner-of-the-circular-game/

// Solution - 

class Solution {
public:
    // https://www.youtube.com/watch?v=2CjWWuYcb6s
    int findTheWinner(int n, int k) {
        queue<int>q;
        for(int i=1; i<=n; i++)
            q.push(i);
        while (q.size() != 1){
            int times = k-1;
            while(times--){
                int ele = q.front();
                q.push(ele);
                q.pop();
            }
            q.pop();
        }
        return q.front();
    }
};
