// Question Link - https://leetcode.com/problems/search-in-rotated-sorted-array/

// Solution Details - https://leetcode.com/submissions/detail/449008703/

// SOLUTION - 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++)
        {
            if (nums[i] == target)
                return i;
        }
        return -1;
    }
};
