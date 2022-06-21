// Question Link - https://leetcode.com/problems/furthest-building-you-can-reach/

// Solution - 

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        priority_queue<int>pq;
        int diff, i=1, sm=0;
        while(i < n){
            diff = heights[i] - heights[i-1];
            if(diff > 0){
                sm += diff;
                if(sm > bricks){
                    if(pq.empty() || pq.top() == diff){
                        if(ladders == 0)return i-1;
                        else ladders--;
                        sm -= diff;
                    }
                    else if(pq.top() > diff){
                        if(ladders == 0)return i-1;
                        else ladders--;
                        sm -= pq.top();
                        pq.pop();
                        pq.push(diff);
                    }
                    else if(pq.top() < diff){
                        if(ladders == 0)return i-1;
                        else ladders --;
                        sm -= diff;
                    }   
                }
                else
                    pq.push(diff);
            }
            i += 1;
        }
        return n-1;
    }
};
