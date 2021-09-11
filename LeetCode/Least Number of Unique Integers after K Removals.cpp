// Question Link - https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/

// Solution - 

class Solution {
public:
    static bool cmp(pair<int, int> &a, pair <int, int> &b){
        return (a.second < b.second);
    }
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>um;
        for(auto x : arr)
            um[x]++;
        if(k == 0)
            return (int)um.size();
        
        vector<pair<int, int>>vp (um.begin() ,um.end());
        sort(vp.begin(), vp.end(), cmp);
        int n = 0;
        for(auto each : vp){
            k -= each.second;
            if(k < 0)
                return (int)um.size() - n;
            if(k == 0)
                return (int)um.size() - n - 1;
            n ++;
        }
        
        return 0;
            
    }
};
