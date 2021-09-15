// Question Link - https://leetcode.com/problems/longest-turbulent-subarray/

// Solution - 

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n == 1)
            return 1;
        if(n == 2){
            if(arr[0] == arr[1])
                return 1;
            return 2;
        }
        // First increasing and then decreasing
        int inc=0, ans=1, cnt=1;
        
        for(int i=0; i<n-1; i++){
            if( (arr[i] < arr[i+1] && !inc) || (arr[i] > arr[i+1] && inc) ){
                inc = inc ^ 1;
                cnt ++;
            }    
            else{
                if(arr[i] < arr[i+1] && inc)
                    cnt = 2;
                else
                    cnt = 1;
            }
            ans = max(ans, cnt);
        }
        
        cnt = 1;
        int dec=0;
        for(int i=0; i<n-1; i++){
            if( (arr[i] > arr[i+1] && !dec) || (arr[i] < arr[i+1] && dec) ){
                dec = dec ^ 1;
                cnt ++;
            }    
            else{
                if(arr[i] > arr[i+1] && dec)
                    cnt = 2;
                else
                    cnt = 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
