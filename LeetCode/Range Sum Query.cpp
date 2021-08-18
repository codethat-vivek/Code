// Question Link - https://leetcode.com/problems/range-sum-query-immutable/

// Solution - 

class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int i=1; i<arr.size(); i++){
            arr[i] += arr[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0)
            return arr[right];
        return arr[right] - arr[left-1];
    }
};
