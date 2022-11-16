// Question Link - https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

// Solution - 

class Solution {
public:
    
    // Given if the maximum number of balls in the bag is maxNumOfBalls, find the minimum number of operations to achieve it
    int numOperations(vector<int>&nums, int maxNumOfBalls){
        int ops = 0;
        for(int i : nums){
            if(i > maxNumOfBalls)
                ops += (ceil((i*1.0)/maxNumOfBalls)-1);
        }
        return ops;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            int ops = numOperations(nums, mid);
            //cout << mid << " " << ops << ", ";
            if(ops > maxOperations){
                low = mid+1;
            }
            else if(ops <= maxOperations){
                high = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};
