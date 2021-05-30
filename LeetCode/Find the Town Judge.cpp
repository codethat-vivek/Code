// Question Link - https://leetcode.com/problems/find-the-town-judge/

// SOLUTION - 

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int>s;
        for(int i=1; i<=n; i++){
            s.insert(i);
        }
        for(auto x: trust){
            s.erase(x[0]);
        }
        if(s.size() != 1)
            return -1;
        
        auto it = s.begin();
        int first = *it;
        
        int cnt = 0;
        for(auto x : trust){
            if(x[1] == first)
                cnt++;
        }
        if(cnt == n-1)
            return first;
        else
            return -1;
        
    }
};
