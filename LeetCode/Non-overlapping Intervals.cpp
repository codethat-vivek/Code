// Question Link - https://leetcode.com/problems/non-overlapping-intervals/

// Solution - 

class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        if(a[0] < b[0])
            return true;
        else if(a[0] == b[0])
            return a[1] < b[1];
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1)
            return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        // for(auto x : intervals)
        //     cout << x[0] << " " << x[1] << endl;
        int deletions = 1;
        vector<vector<int>> v;
        int k = 0;
        while(v.size() != 1){
            if(intervals[k][1] > intervals[k+1][0]){
                if(intervals[k][1] > intervals[k+1][1])
                    v.push_back(intervals[k+1]);
                else
                    v.push_back(intervals[k]);
            }
            k++;
            if(k == n-1 && v.size() != 1)
                return 0;
            if(k == n-1 && v.size() == 1)
                return 1;
        }
        
        int p = 0;
        for(int i=k+1; i<intervals.size(); i++){
            if(v[p][1] > intervals[i][0]){ // there is a intersection
                if(v[p][1] > intervals[i][1]){ // this decides which one to delete, we always delete the one which has the larger end value
                    v[p][0] = intervals[i][0];
                    v[p][1] = intervals[i][1];
                }
                deletions++;
                p--;
            }
            else
                v.push_back(intervals[i]);
            p++;
        }
        return deletions;
    }
};
