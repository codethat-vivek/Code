// Question Link - https://leetcode.com/problems/subarray-product-less-than-k/

// Solution - 

class Solution {
public:
    int calc(int n, int k){
        int ans = 0;
        for(int i=0; i<k; i++)
            ans += n--;
        return ans;
            
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, prod=1;
        int n = nums.size();
        int start=n;
        for(int i=0; i<n; i++){
            if(nums[i] < k){
                start = i;
                break;
            }
        }
        if(start == n)return 0;
        int end, prev;
        for(end=start; end<n; end++){
            prod *= nums[end];
            if(prod >= k){
                prev = start;
                while(prod >= k)prod/=nums[start++];
                ans += calc(end-prev, start-prev);
            }
        }
        ans += (end-start)*(end-start+1)/2;
        return ans;
    }
};
