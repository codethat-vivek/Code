// Question Link - https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

// Solution - 

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        for(auto &t : time)
            t = t%60;
        unordered_map<int, int>um;
        for(auto t : time)
            um[t]++;
        
        int ans = 0, x;
        unordered_set<int>seen;
        for(int i=0; i<time.size(); i++){
            if(seen.find((60-time[i])%60) != seen.end())
                continue;
            seen.insert(time[i]);
            if(time[i] == 30 || time[i] == 0 || time[i] == 60){
                x = um[(60 - time[i])%60];
                ans += x*(x-1)/2;
            }
            else
                ans += um[(60 - time[i])%60];
        }
        
        return ans;
    }
};


