// Question Link - https://leetcode.com/problems/construct-string-with-repeat-limit/

// Solution - 

#define pci pair<char, int>

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> um;
        for(char c : s){
            um[c]++;
        }
        priority_queue<pci>pq;
        for(auto &e : um){
            pq.push({e.first, e.second});
        }
        
        string ans = "";
        char c, cc;
        int f, ff=0, mn;
        while(!pq.empty()){
            c = pq.top().first;
            f = pq.top().second;
            //cout << "c = " << c << ", f = " << f << endl;
            pq.pop();
            
            mn = min(repeatLimit, f);
            f -= mn;
            for(int i=0; i<mn; i++)
                ans += c;
            
            if(f > 0){
                if(pq.empty()) return ans;
                cc = pq.top().first;
                ff = pq.top().second;
                //cout << "cc = " << cc << ", ff = " << ff << endl;
                pq.pop();
                
                ans += cc; --ff;    
            }
            
            if(ff > 0){
                pq.push({cc, ff});
                ff = 0;
                
            }
            if(f > 0)
                pq.push({c, f});
            
        }
        
        return ans;
    }
};
