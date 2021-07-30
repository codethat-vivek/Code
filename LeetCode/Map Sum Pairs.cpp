// Question Link - https://leetcode.com/problems/map-sum-pairs/

// Solution - 

class MapSum {
public:
    /** Initialize your data structure here. */
    vector<pair<string, int>> ds;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        bool found = false;
        for(auto &x : ds){
            if(x.first == key){
                found = true;
                x.second = val;
            }
        }
        if(!found)
            ds.push_back({key, val});
        
    }
    
    int sum(string prefix) {
        int ans = 0;
        for(auto x : ds){
            string s = x.first;
            if(s.find(prefix) == 0)
                ans += x.second;
        }
        return ans;
    }
};
