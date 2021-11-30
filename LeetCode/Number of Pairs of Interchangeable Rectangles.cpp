// Question Link - https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/

// Solution - 

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        long long ans = 0;
        vector<double>ratios;
        for(auto each : rectangles){
            ratios.push_back((each[0]*1.0)/each[1]);
        }
        
        sort(ratios.begin(), ratios.end());
        // for(int i=0; i<n; i++)
        //     cout << ratios[i] << " ";
        // cout << endl;
        long long cnt = 1;
        for(int i=0; i<n-1; i++){
            if(ratios[i] == ratios[i+1])
                cnt++;
            else{
                ans += (long long)(cnt*(cnt-1)/2);
                cnt = 1;
            }
        }
        ans += (long long)(cnt*(cnt-1)/2);
        return ans;
    }
};
