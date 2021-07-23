// Question Link - https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

// Solution - 

class Solution {
public:
    bool isInside(int x, int y, int r, int p, int q){
        int t = (p-x)*(p-x) + (q-y)*(q-y) - r*r;
        if (t <= 0)
            return true;
        return false;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int>ans;
        int cnt=0;
        for(int i=0; i<queries.size(); i++){
            cnt = 0;
            for(int j=0; j<points.size(); j++){
                if (isInside(queries[i][0], queries[i][1], queries[i][2], points[j][0], points[j][1]))
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
