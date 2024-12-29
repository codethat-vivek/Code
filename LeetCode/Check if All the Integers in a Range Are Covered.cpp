// Question Link - https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/

// Solution - 

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int n = ranges.size();
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> merged;
        for(int i=0; i<n; i++){
            if(i == 0) merged.push_back(ranges[i]);
            else{
                int size = merged.size();
                if(merged[size-1][1] >= ranges[i][0] || merged[size-1][1] == ranges[i][0]-1){
                    merged[size-1][0] = min(merged[size-1][0], ranges[i][0]);
                    merged[size-1][1] = max(merged[size-1][1], ranges[i][1]);    
                }
                else
                    merged.push_back(ranges[i]);
            }
        }
        for(int i=0; i<merged.size(); i++){
            if(merged[i][0] <= left && merged[i][1] >= right)
                return true;
        }
        return false;
    }
};
