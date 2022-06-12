// Question Link - https://leetcode.com/problems/maximum-erasure-value/

// Solution - 

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int n=nums.size(), i=0, j=0;
        unordered_set<int>us;
        int sm = 0;
        while(j < n){
            if(us.find(nums[j]) == us.end()){
                sm += nums[j];
                us.insert(nums[j]);
            }
            else{
                while(nums[i] != nums[j]){
                    sm -= nums[i];
                    us.erase(us.find(nums[i++]));
                }
                i ++;
            }
            j++;
            ans = max(ans, sm);
        }
        return ans;
    }
};
