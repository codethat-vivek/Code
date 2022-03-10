// Question Link - https://leetcode.com/problems/valid-mountain-array/

// Solution - 

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3 || arr[0] >= arr[1])return false;
        bool inc = true;

        for(int i=0; i<n-1; i++){
            if(inc && arr[i] < arr[i+1]){
                inc = true;
                continue;
            }
            if(inc && arr[i] > arr[i+1]){
                inc = false;
                continue;
            }
            
            if(!inc && arr[i] > arr[i+1])
                continue;
            
            return false;
        }
        if(inc)return false;
        return true;
    }
};
