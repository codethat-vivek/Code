// Question Link - https://leetcode.com/problems/k-closest-points-to-origin/

// Solution - 

class Solution {
public:
    double findDistance(int a, int b){
        return sqrt(a*a+b*b);
    }
    static bool cmp(const pair<int, double>&a, const pair<int, double>&b){
        return a.second < b.second;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, double>>vp;
        for(int i=0; i<points.size(); i++)
            vp.push_back({i, findDistance(points[i][0], points[i][1])});
        sort(vp.begin(), vp.end(), cmp);
        vector<vector<int>>ans;
        for(int i=0; i<vp.size() && i<k; i++){
            ans.push_back(points[vp[i].first]);
        }
        return ans;
    }
};
