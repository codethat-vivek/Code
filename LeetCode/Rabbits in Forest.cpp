// Question Link - https://leetcode.com/problems/rabbits-in-forest/

// Solution - 

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int>um;
        for(auto a : answers)
            um[a]++;
        int ans = 0, f, s, c;
        for(auto each : um){
            f = each.first;
            s = each.second;
            c = ceil((s*1.0)/(f+1));
            ans += c*(f+1);
        }
        return ans;
    }
};
