// Question Link - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// Solution - 

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vp;
        vector<int>ans;
        for(int i=0; i<mat.size(); i++){
            int ones = 0;
            for(int j=0; j<mat[i].size(); j++){
                if(mat[i][j] == 0)
                    break;
                ones++;
            }
            vp.push_back(make_pair(ones, i));
        }
        sort(vp.begin(), vp.end());
        for(int i=0; i<k; i++)
            ans.push_back(vp[i].second);
        return ans;
    }
};
