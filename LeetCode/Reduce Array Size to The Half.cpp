// Question Link - https://leetcode.com/problems/reduce-array-size-to-the-half/

// Solution - 

class Solution {
public:
    static bool cmp(pair<int, int>p1, pair<int, int>p2){
        return p1.second > p2.second;
    }
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int>um;
        vector<pair<int, int>> vp;
        int n = arr.size();
        for(int i=0; i<n; i++)
            um[arr[i]]++;
        
        for(auto &it : um)
            vp.push_back(it);
        
        sort(vp.begin(), vp.end(), cmp);
        int removed = 0;
        int ans = 0;
        for(auto it : vp){
            removed += it.second;
            ans++;
            if(removed >= n/2)
                return ans;
        }
        return ans;
        
    }
};
