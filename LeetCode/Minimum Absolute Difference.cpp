// Question Link - https://leetcode.com/problems/minimum-absolute-difference/

// Solution - 

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>>ans;
        int k = 3*1e6+1;
        for(int i=0; i<n-1; i++){
            k = min(k, arr[i+1]-arr[i]);
        }
        for(int i=0; i<n-1; i++){
            if(arr[i+1]-arr[i] == k)
                ans.push_back({arr[i], arr[i+1]});
        }
        return ans;
        
    }
};
