// Question Link - https://leetcode.com/problems/two-sum/

// Solution Details - https://leetcode.com/submissions/detail/443015359/

// SOLUTION - 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        vector<int>original = nums;
        sort(nums.begin(), nums.end());
        while(i<j){
            if(nums[i] + nums[j] == target)
                break;
            else if(nums[i] + nums[j] > target)
                j--;
            else
                i++;
        }
        vector<int>ans;
        for(int k=0; k<original.size(); k++){
            if(original[k] == nums[i] || original[k] == nums[j]){
                ans.push_back(k);
            }
        }
        return ans;
    }
};
