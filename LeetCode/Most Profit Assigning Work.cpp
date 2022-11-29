// Question Link - https://leetcode.com/problems/most-profit-assigning-work/

// Solution - 

class Solution {
public:
    
    bool static cmp(const pair<int, int> &p, const pair<int, int>& q){
        if(p.first < q.first) return true;
        if(p.first == q.first){
            if(p.second < q.second) return true;
            return false;
        }
        return false;
    }
    
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vp;
        for(int i=0; i<profit.size(); i++)
            vp.push_back(make_pair(difficulty[i], profit[i]));
        sort(vp.begin(), vp.end(), cmp);
        int mx = -1;
        vector<int>profitUpto;
        for(auto each : vp){
            mx = max(mx, each.second);
            profitUpto.push_back(mx);
        }
        
        int ans = 0;
        for(int w : worker){
            pair<int, int> p = make_pair(w, INT_MAX);
            int idx = lower_bound(begin(vp), end(vp), p) - begin(vp);
            if(idx == 0){
                if(vp[0].first == w)
                    ans += profitUpto[0];
                continue;
            }
            else if(idx == worker.size())
                ans += profitUpto[profitUpto.size()-1];
            
            else if(vp[idx].first == w)
                ans += profitUpto[idx];
            else
                ans += profitUpto[idx-1];
            
        }
        return ans;
    }
};
