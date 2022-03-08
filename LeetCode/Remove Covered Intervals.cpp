// Question Link - https://leetcode.com/problems/remove-covered-intervals/

// Solution - 

class Solution {
public:
    
    // static bool compare(vector<int>&interval1, vector<int>&interval2){
    //     if(interval1[0] < interval2[0])
    //         return true;
    //     else if(interval1[0] == interval2[0]){
    //         if(interval1[1] <= interval2[1])
    //             return true;
    //         return false;
    //     }
    //     return false;
    // }
    
    int intersection(vector<int>&I, vector<int>&J){
        if(J[0] <= I[0] && I[1] <= J[1])return 1;
        if(I[0] <= J[0] && J[1] <= I[1])return 2;
        return 0;
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), compare);
        // for(vector<int>each : intervals){
        //     cout << each[0] << " " << each[1] << endl;
        // }
        
        int deleted = 0;
        int n = intervals.size();
        set<int>dontConsider;
        for(int i=0; i<n; i++){
            if(dontConsider.find(i) != dontConsider.end())
                continue;
            for(int j=i+1; j<n; j++){
                if(dontConsider.find(j) != dontConsider.end())
                    continue;
                int val = intersection(intervals[i], intervals[j]);

                if(val == 1){
                    deleted++;
                    break;
                }
                if(val == 2){
                    dontConsider.insert(j);
                    deleted++;
                }
                
            }
        }
        
        return n - deleted;
        
    }
};
