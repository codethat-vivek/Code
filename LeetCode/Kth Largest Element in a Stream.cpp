// Question Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/

// Solution - 

class KthLargest {
public:
    priority_queue <int, vector<int>, greater<int>> pq; // min heap
    int idx;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            if(pq.size() > k)
                pq.pop();
        }
        idx = k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > idx)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
