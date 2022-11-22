// Question Link - https://leetcode.com/problems/h-index-ii/

// Solution - 

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low=0, high=n;
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            int idx = lower_bound(begin(citations), end(citations), mid) - begin(citations);
            if(n - idx >= mid){
                ans = mid;
                low = mid+1;
            }
            else
                high = mid-1;
        }
        return ans;
    }
};
