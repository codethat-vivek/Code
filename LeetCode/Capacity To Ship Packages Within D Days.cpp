// Question Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

// Solution - 

class Solution {
public:
    
    bool isValid(vector<int>weights, int days, int mid){
        int sm = 0;
        int cnt = 1;
        for(int i=0; i<weights.size(); i++){
            sm += weights[i];
            if(sm > mid){
                cnt++;
                sm = weights[i];
            }
            if(cnt > days)
                return false;
        }
        return true;
    }
    
    int bs(vector<int>weights, int days, int start, int end){
        int mid, res;
        while(start <= end){
            mid = start + (end-start)/2;
            if(isValid(weights, days, mid)){
                res = mid;
                end = mid-1;
            }
            else
                start = mid+1;
        }
        return res;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int mx = -1;
        int sm = 0;
        for(auto each : weights){
            sm += each;
            mx = max(mx, each);
        }
        return bs(weights, days, mx, sm);
    }
};v
