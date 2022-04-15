// Question Link - https://leetcode.com/problems/range-sum-query-mutable/

// Solution - 

class NumArray {
    
private:
    int segTree[12*10000] = {0};
    vector<int>arr;
public:
    
    void build(int idx, int low, int high){
        if(low == high){
            segTree[idx] = arr[low];
            return;
        }
        
        int mid = (low + high)/2;
        build(2*idx+1, low, mid);
        build(2*idx+2, mid+1, high);
        
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
        
    }
    
    NumArray(vector<int>& nums) {
        arr = nums;
        build(0, 0, arr.size()-1);
    }
    
    void updateHelper(int index, int val, int idx, int low, int high){
        if(index < low || index > high)
            return;
        if(low == high && low == index){
            arr[index] = val;
            segTree[idx] = val;
            return;
        }
        
        int mid = (low + high)/2;
        updateHelper(index, val, 2*idx+1, low, mid);
        updateHelper(index, val, 2*idx+2, mid+1, high);
        
        segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
        
    }
    
    void update(int index, int val) {
        updateHelper(index, val, 0, 0, arr.size()-1);
    }
    
    int sumHelper(int idx, int low, int high, int left, int right){
        if(left > high || right < low)
            return 0;
        if(low >= left && high <= right)
            return segTree[idx];
        
        int mid = (low + high)/2;
        return sumHelper(2*idx+1, low, mid, left, right) + sumHelper(2*idx+2, mid+1, high, left, right);
        
    }
    
    int sumRange(int left, int right) {
        return sumHelper(0, 0, arr.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
