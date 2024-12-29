// Question Link - https://leetcode.com/problems/maximum-population-year/description/

// Solution - 

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        sort(begin(logs), end(logs));
        vector<int>pref(102, 0);
        for(auto &log : logs){
            pref[log[0]-1950] += 1;
            pref[log[1]-1950] -= 1;
        }
        int year = 0, mx = 0, curr = 0;
        for(int i=0; i<102; i++){
            curr += pref[i];
            if (curr > mx){
                mx = curr;
                year = i + 1950;
            }
        }

        return year;
    }
};
