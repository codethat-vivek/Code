// Question Link - https://leetcode.com/problems/points-that-intersect-with-cars/description/

// Solution - 

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        int mn = 200, mx = -1;
        map<int, int>mp;
        for(auto &r : nums){
            mn = min(mn, r[0]);
            mx = max(mx, r[1]);
            mp[r[0]] ++;
            mp[r[1]+1] --;
        }

        int curr=0, ans=0, start=-1, end=-1;
        for(auto &p : mp){
            curr += p.second;
            if(curr == 0)
                start = p.first;
            else{
                end = p.first;
                if(start >= 0 && start < end){
                    ans += end-start;
                    start = -1;
                    end = -1;
                }
            }
        }
       
        return mx-mn+1-ans;
    }
};
