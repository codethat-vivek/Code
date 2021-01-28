// Question Link - https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

// Solution Details - https://leetcode.com/submissions/detail/449030868/

// SOLUTION - 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto x : nums){
            if(x == target)
                return true;
        }
        return false;
    }
};
