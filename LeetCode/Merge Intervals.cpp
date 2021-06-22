// Question Link - https://leetcode.com/problems/merge-intervals/

// Solution - 

class Solution {
public:
    // Commented comp. Function is wrong because we are not giving a clear message to the 
    // compiler of comparision . For Ex -> a = [1, 4] b = [2, 3]
    // Here comp(a, b) will result in true and comp(b, a) will also result in true
    // which confuses the compiler, hence resulting in runtime error.
    
    //  static bool comparatorFunction(vector<int>a, vector<int>b){
    //    return  a[0] <= b[0] ;    
    //  }
    
    static bool comparatorFunction(vector<int>a, vector<int>b){
        return  a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);   
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1)return intervals;
        // Sort
        sort(intervals.begin(), intervals.end(), comparatorFunction);
        // for(auto x : intervals){
        //     for(int i=0; i<x.size(); i++)
        //         cout << x[i] << " ";
        //     cout << endl;
        // }
        // logic
        
        int n = intervals.size();
        vector<vector<int>>ans;
        
        ans.push_back(intervals[0]);

        int i = 0;
        int j = 1;
        // [2, 45], [30, 55]
        // [2, 45], [55, 5675]
        while(j < n)
        {
            if(intervals[j][0] > ans[i][1])
            {
                // we can't merge
                ans.push_back(intervals[j]);
                i++;
                j++;
                
            }
            else
            {
                ans[i][1] = max(ans[i][1], intervals[j][1]);
                j++;
                //cout << "ok";
            }
            
        }
            
        return ans;
    }
};
