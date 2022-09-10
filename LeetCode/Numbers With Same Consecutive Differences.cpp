// Question Link - https://leetcode.com/problems/numbers-with-same-consecutive-differences/

// Solution - 

class Solution {
public:
    vector<int> gen(int start, int size, int diff){
        if(size == 0)return {};
        if(size == 1)return {start};
        
        vector<int>ans;
        
        if(start+diff < 10){
            vector<int>temp = gen(start + diff, size-1, diff);
            for(auto &x : temp)
                ans.push_back(x+start*pow(10, (size-1)));
        }
        
        if(start-diff >= 0){
            vector<int>temp = gen(start - diff, size-1, diff);
            for(auto &x : temp)
                ans.push_back(x+start*pow(10, (size-1)));
        }
        
        return ans;
        
    }
    
    
    vector<int> numsSameConsecDiff(int n, int k) {
        
        set<int>st;
        for(int i=1; i<=9; i++){
            vector<int>t = gen(i, n, k);
            for(auto x : t)
                st.insert(x);
        }
        vector<int>ans(st.begin(), st.end());
        return ans;
    }
};
