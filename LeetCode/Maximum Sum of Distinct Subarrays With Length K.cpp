// Question Link - https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

// Solution - 

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long int i=0, j=0,sm=0,ans=0;
        unordered_set<int>us;
        while(j < n){
            if(j-i == k)
                ans = max(ans, sm);
            if(us.find(nums[j]) != us.end()){
                while(nums[i] != nums[j]){
                    sm -= nums[i];
                    us.erase(us.find(nums[i++]));
                }
                sm -= nums[i];
                us.erase(us.find(nums[i++]));
                us.insert(nums[j]);
                sm += nums[j++];
            }
            else{
                if(j-i < k){
                    sm += nums[j];
                    us.insert(nums[j++]);
                    //cout << "j-i < k " << sm << "\n";
                }
                else if(j-i == k){
                    sm -= nums[i];
                    us.erase(us.find(nums[i++]));
                    //cout << "j-i == k " << sm << "\n";
                }
                
            }
        }
        if(j-i == k)ans = max(ans, sm);
        return ans;
    }
};
