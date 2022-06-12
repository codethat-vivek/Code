// Question Link - https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// Solution - 

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // longest subarray with sum = s-x
        int n=nums.size(), sm = 0;
        for(int i : nums)
            sm += i;
        if(sm < x)return -1;
        if(sm == x)return n;
        int target = sm-x;
        int ans = 0;
        int i=0, j=0;
        sm = 0;
        
        while(j < n){
            sm += nums[j];
            if(sm == target)
                ans = max(ans, j-i+1);
            else if(sm > target){
                while(sm > target)
                    sm -= nums[i++];
                if(sm == target)
                    ans = max(ans, j-i+1);
            }
            //cout << ans << " ";
            j ++;
        }
        if(ans == 0)
            return -1;
        return n-ans;
    }
};
