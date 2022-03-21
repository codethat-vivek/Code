// Question Link - https://leetcode.com/problems/arithmetic-subarrays/

// Solution - 

class Solution {
public:
    bool check(vector<int>arr, int l, int r){
        if(r-l <= 1)return true;
        sort(arr.begin()+l, arr.begin()+r+1);
        int d = arr[l+1]-arr[l];
        for(int i=l+2; i<=r; i++){
            if(arr[i]-arr[i-1] != d)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>ans;
        for(int i=0; i<l.size(); i++)
            ans.push_back(check(nums, l[i], r[i]));
        return ans;
    }
};
