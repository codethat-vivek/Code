// Question Link - https://leetcode.com/problems/find-all-duplicates-in-an-array/

// Solution - 

// Time - O(n)
// Space - O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(auto &x : nums)
            x--;
        for(int i=0; i<n; i++)
            nums[nums[i]%n] += n;
        for(auto x : nums)
            cout << x << " ";
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(nums[i]/n == 2)
                ans.push_back(i+1);
        }
        return ans;
    }
};
