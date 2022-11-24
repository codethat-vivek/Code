// Question Link - https://leetcode.com/problems/frequency-of-the-most-frequent-element/

// Solution - 

class Solution {
public:
    
    int calculateK(vector<int>&nums, vector<long long int>&prefix, int freq){
        if(freq == 1) return 0;
        long long int moves = INT_MAX;
        for(int i=freq-1; i<nums.size(); i++){
            if(i == freq-1)
                moves = min(moves, (long long)nums[i]*(freq-1)-prefix[i-1]);
            else
                moves = min(moves, (long long)nums[i]*(freq-1)-prefix[i-1]+prefix[i-freq]);
        }
        return moves;
    }
    
    int maxFrequency(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(begin(nums), end(nums));
        
        vector<long long int>prefix(n, 0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++)
            prefix[i] = prefix[i-1] + nums[i];
        
        int ans ;
        int low=1, high=n;
        while(low <= high){
            int mid = low + (high - low)/2;
            int val = calculateK(nums, prefix, mid);
            if(val > k)
                high = mid-1;
            else{
                low = mid+1;
                ans = mid;
            }
        }
        return ans;
   
    }
};
