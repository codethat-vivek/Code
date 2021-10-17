// Question Link - https://leetcode.com/problems/interval-list-intersections/

// Solution - 

class Solution {
public:
    vector<int> helper(vector<int>a, vector<int>b){
        int first = max(a[0], b[0]);
        int second = min(a[1], b[1]);
        if(first > second) // no intersection
            return {};
        return {first, second};
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0, j=0;
        int m = firstList.size(), n = secondList.size();
        vector<vector<int>>ans;
        while(i < m && j < n){
            vector<int>temp = helper(firstList[i], secondList[j]);
            if(temp.size() != 0) ans.push_back(temp);
            if(firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }
        return ans;
    }
};
