// Question Link - https://leetcode.com/problems/maximum-total-importance-of-roads/

// Solution - 

#define ll long long
class Solution {
public:
    
    static bool cmp(pair<ll, ll>& a, pair<ll, ll>& b){
        return a.second > b.second;
    }
    
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<ll, ll>mp;
        for(auto t : roads){
            mp[t[0]]++;
            mp[t[1]]++;
        }
        vector<pair<ll, ll>>vp;
        for(auto &t : mp)
            vp.push_back(t);
        sort(vp.begin(), vp.end(), cmp);
        
        
        
        // for(auto t : vp)
        //     cout << t.first << " " << t.second << endl;
        
        map<pair<int, int>, int>mpp;
        
        for(auto &t : vp){
            mpp[t] = n;
            n -= 1;
        }
        
        // cout << " ========================================================= " << endl;
        // for(auto &t: mpp){
        //     cout << t.first.first << " " << t.first.second << " " << t.second << endl;
        // }
        
        ll ans = 0;
        for(auto t : roads)
            ans += (mpp[{t[0], mp[t[0]]}] + mpp[{t[1], mp[t[1]]}]);
        
        
        return ans;
        
    }
};
